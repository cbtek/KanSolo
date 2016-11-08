/**
MIT License

Copyright (c) 2016 cbtek

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#include "UIKanSoloMain.h"
#include "ui_UIKanSoloMain.h"
#include "utility/inc/FileUtils.hpp"
#include "utility/inc/DateUtils.hpp"
#include "utility/inc/TimeUtils.hpp"


#include "KanSoloProjectManager.h"
#include <QDir>
#include "UIKanSoloCreateNewBoard.h"
#include "UIKanSoloCreateNewProject.h"
#include "UIKanSoloCreateNewSprint.h"

#include <QMessageBox>

using namespace cbtek::common::utility;
namespace cbtek {
namespace products {
namespace kan_solo {


UIKanSoloMain::UIKanSoloMain(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui_UIKanSoloMain)
{    
    m_ui->setupUi(this);
    m_toggleFullScreen=false;
    connect(m_ui->m_btnNewBoard,SIGNAL(clicked(bool)),this,SLOT(onCreateBoard()));    
    connect(m_ui->m_btnNewTask,SIGNAL(clicked(bool)),this,SLOT(onCreateTask()));
    connect(m_ui->m_btnExit,SIGNAL(clicked(bool)),this,SLOT(onClose()));
    connect(m_ui->m_cmbBoards,SIGNAL(currentIndexChanged(int)),this,SLOT(onSelectBoard(int)));
    connect(m_ui->m_cmbThemes,SIGNAL(currentIndexChanged(int)),this,SLOT(onSelectTheme(int)));
    m_ui->m_frmBoard->hide();
    m_ui->m_btnNewTask->hide();
    m_currentThemes = KanSoloProjectManager::inst().getThemes();
    m_currentBoard = NULL;
    for (KanSoloTheme theme : m_currentThemes)
    {

        if (theme.isValid())
        {
            m_ui->m_cmbThemes->addItem(QString::fromStdString(theme.getName()));
            if (m_ui->m_cmbThemes->count()==1)
            {
                m_currentBackgroundUrl = QString::fromStdString(theme.getBackgroundUrl());
                QString btnNewTask = QString::fromStdString(theme.getNewTaskButtonUrl());
                QString btnNewBoard = QString::fromStdString(theme.getNewBoardButtonUrl());
                QString btnExit = QString::fromStdString(theme.getExitButtonUrl());
                QString logoUrl = QString::fromStdString(theme.getLogoUrl());
                this->setStyleSheet("#centralwidget{background:url(\""+m_currentBackgroundUrl+"\");}");
                m_ui->m_btnExit->setIcon(QIcon(btnExit));
                m_ui->m_btnNewTask->setIcon(QIcon(btnNewTask));
                m_ui->m_btnNewBoard->setIcon(QIcon(btnNewBoard));

                m_ui->m_lblLogo->setPixmap(QPixmap(logoUrl));
            }
        }
    }
    onPopulateBoardList();

    //Auto populate last combo box selections
    try
    {
        size_t boardIndex = KanSoloProjectManager::inst().getDefaultBoardIndex();
        if (boardIndex>=0 && boardIndex < m_ui->m_cmbBoards->count())
        {
            onSelectBoard(boardIndex);
        }
    }
    catch(std::exception & ){}

    try
    {
        size_t themeIndex = KanSoloProjectManager::inst().getDefaultThemeIndex();
        if (themeIndex >=0 && themeIndex < m_ui->m_cmbThemes->count())
        {
            onSelectTheme(themeIndex);
        }

    }
    catch(std::exception & ){}
}


UIKanSoloMain::~UIKanSoloMain()
{
    delete m_ui;
}

void UIKanSoloMain::loadTasks()
{

}

void UIKanSoloMain::resizeEvent(QResizeEvent *)
{

}

void UIKanSoloMain::keyPressEvent(QKeyEvent * e)
{
    if (e->key() == Qt::Key_Escape)
    {
        m_toggleFullScreen =!m_toggleFullScreen;
        if (m_toggleFullScreen)
        {
            m_ui->m_frmCommands->hide();
            m_ui->m_frmSelections->hide();
            this->setWindowState( Qt::WindowMaximized |
                                  Qt::WindowFullScreen);
        }
        else
        {
            m_ui->m_frmCommands->show();
            m_ui->m_frmSelections->show();
            this->setWindowState( Qt::WindowNoState);
        }
    }
    else if (e->key() == Qt::Key_Space)
    {
        onCreateTask();
    }
}

void UIKanSoloMain::showEvent(QShowEvent *)
{

    resizeEvent(NULL);
}


void UIKanSoloMain::onCreateTask()
{
    if (m_currentBoard == NULL)
    {
        return;
    }
    UIKanSoloCreateNewTask taskUI;
    connect(&taskUI,SIGNAL(taskCreated(KanSoloTask)),this,SLOT(onCreateTask(KanSoloTask)));
    taskUI.exec();
}

void UIKanSoloMain::onCreateTask(KanSoloTask task)
{
    if (m_currentBoard)
    {
        task.create();
        task.setScaleX(0);
        task.setScaleY(.25);
        m_currentBoard->addTask(task);
        task.setBoardId(m_currentBoardId.toStdString());
        KanSoloProjectManager::inst().createTask(task);
        this->update();
    }
}
void UIKanSoloMain::onLoadTasks()
{
    if (m_currentBoard)
    {
        m_currentBoard->clearTasks();
        std::vector<KanSoloTask> tasks = KanSoloProjectManager::inst().getTasks(m_currentBoardId.toStdString());
        for (KanSoloTask task : tasks)
        {
            m_currentBoard->addTask(task);
        }
        this->update();
    }
}



void UIKanSoloMain::onEditTask(KanSoloTask task)
{
    UIKanSoloCreateNewTask taskUI(task);
    connect(&taskUI,SIGNAL(taskUpdated(KanSoloTask)),this,SLOT(onUpdateTask(KanSoloTask)));
    taskUI.exec();
}
void UIKanSoloMain::onRemoveTask(const KanSoloTask &task)
{
    KanSoloProjectManager::inst().removeTask(m_currentBoardId.toStdString(),task.getId());
}

void UIKanSoloMain::onUpdateTask(KanSoloTask task)
{
    if (m_currentBoard)
    {

        task.update();
        task.setBoardId(m_currentBoardId.toStdString());
        KanSoloProjectManager::inst().updateTask(m_currentBoardId.toStdString(),task);
        m_currentBoard->updateTask(task);
    }
}



void UIKanSoloMain::onCreateBoard(const KanSoloBoard &board)
{
    bool firstBoard = m_ui->m_cmbBoards->count() == 1;
    if (m_currentBoard)
    {
        m_currentBoard->hide();
    }
    m_currentBoard = new UIKanSoloBoard(board,m_currentBackgroundUrl);

    m_ui->m_cmbBoards->addItem(QString::fromStdString(board.getTitle())
                              ,QVariant(QString::fromStdString(board.getId())));



    connect(m_currentBoard,SIGNAL(taskUpdated(KanSoloTask)),this,SLOT(onUpdateTask(KanSoloTask)));
    connect(m_currentBoard,SIGNAL(taskEdited(KanSoloTask)),this,SLOT(onEditTask(KanSoloTask)));
    connect(m_currentBoard,SIGNAL(taskDeleted(KanSoloTask)),this,SLOT(onRemoveTask(KanSoloTask)));

    connect(m_currentBoard,SIGNAL(boardEdited(KanSoloBoard)),this,SLOT(onEditBoard(KanSoloBoard)));
    connect(m_currentBoard,SIGNAL(boardDeleted(KanSoloBoard)),this,SLOT(onDeleteBoard(KanSoloBoard)));
    m_ui->m_frmBoard->layout()->addWidget(m_currentBoard);
    if (firstBoard)
    {
        m_ui->m_cmbBoards->setItemText(0,"--Select Active Board--");        
    }    
    m_ui->m_lblLogo->hide();
    m_ui->m_frmBoard->show();
    m_ui->m_btnNewTask->show();
    m_boards.push_back(m_currentBoard);
    m_ui->m_cmbBoards->setCurrentIndex(m_boards.size());
}


void UIKanSoloMain::onUpdateBoard(const KanSoloBoard &board)
{
    if (m_currentBoard)
    {
        //Update board name in combo box
        for (size_t a1= 0;a1<m_ui->m_cmbBoards->count();++a1)
        {
            std::string id = m_ui->m_cmbBoards->itemData(a1,Qt::UserRole).toString().toStdString();
            if (id == board.getId())
            {
                m_ui->m_cmbBoards->setItemText(a1,QString::fromStdString(board.getTitle()));
            }
        }

        //Update board instance in database
        KanSoloProjectManager::inst().updateBoard(board);

        //Update visual board instance
        m_currentBoard->updateBoard(board);
    }
}


void UIKanSoloMain::onEditBoard(const KanSoloBoard &board)
{
    UIKanSoloCreateNewBoard editBoard(board);
    connect(&editBoard,
            SIGNAL(boardUpdated(const KanSoloBoard &)),
            this,
            SLOT(onUpdateBoard(const KanSoloBoard &)));

    editBoard.exec();
}

void UIKanSoloMain::onCreateBoard()
{  

    UIKanSoloCreateNewBoard newBoard;
    connect(&newBoard,
            SIGNAL(boardCreated(const KanSoloBoard &)),
            this,
            SLOT(onCreateBoard(const KanSoloBoard &)));
    newBoard.exec();
}


void UIKanSoloMain::onDeleteBoard(const KanSoloBoard &board)
{

}


void UIKanSoloMain::onPopulateBoardList()
{
    std::vector<KanSoloBoard> boards;
    boards = KanSoloProjectManager::inst().getBoards();
    m_ui->m_cmbBoards->clear();
    m_boards.clear();
    if (boards.size())
    {

        m_ui->m_cmbBoards->addItem("--Select Active Board--");
    }
    else
    {

        m_ui->m_cmbBoards->addItem("--No Boards Available--");
    }
    for(KanSoloBoard board : boards)
    {
        m_ui->m_cmbBoards->addItem(QString::fromStdString(board.getTitle()),
                                   QVariant(QString::fromStdString(board.getId())));
        UIKanSoloBoard * boardUI = new UIKanSoloBoard(board,m_currentBackgroundUrl);
        m_boards.push_back(boardUI);
        boardUI->hide();
    }
}

void UIKanSoloMain::onSelectBoard(int index)
{
    if (index<1)
    {
        m_ui->m_lblLogo->show();
        m_ui->m_frmBoard->hide();

        m_currentBoardId = "";
        m_ui->m_btnNewTask->hide();
    }
    else if(index < m_ui->m_cmbBoards->count())
    {

        m_ui->m_lblLogo->hide();
        m_ui->m_frmBoard->show();
        if (m_currentBoard)
        {
            m_currentBoard->hide();
        }
        m_currentBoard = m_boards[index-1];

        connect(m_currentBoard,SIGNAL(taskUpdated(KanSoloTask)),this,SLOT(onUpdateTask(KanSoloTask)));
        connect(m_currentBoard,SIGNAL(taskEdited(KanSoloTask)),this,SLOT(onEditTask(KanSoloTask)));
        connect(m_currentBoard,SIGNAL(taskDeleted(KanSoloTask)),this,SLOT(onRemoveTask(KanSoloTask)));
        connect(m_currentBoard,SIGNAL(boardEdited(KanSoloBoard)),this,SLOT(onEditBoard(KanSoloBoard)));
        connect(m_currentBoard,SIGNAL(boardDeleted(KanSoloBoard)),this,SLOT(onDeleteBoard(KanSoloBoard)));

        KanSoloProjectManager::inst().setDefaultBoardIndex(index);
        m_ui->m_frmBoard->layout()->addWidget(m_currentBoard);        
        m_currentBoardId = m_ui->m_cmbBoards->currentData(Qt::UserRole).toString();
        onLoadTasks();
        m_currentBoard->show();
        m_currentBoard->updateBackgroundUrl(m_currentBackgroundUrl);
        m_ui->m_btnNewTask->show();
    }
}

void UIKanSoloMain::onSelectTheme(int index)
{

    if (index >=0 && index <m_currentThemes.size())
    {
        KanSoloTheme theme = m_currentThemes[index];
        m_currentBackgroundUrl = QString::fromStdString(theme.getBackgroundUrl());
        QString btnNewTask = QString::fromStdString(theme.getNewTaskButtonUrl());
        QString btnNewBoard = QString::fromStdString(theme.getNewBoardButtonUrl());
        QString btnExit = QString::fromStdString(theme.getExitButtonUrl());
        QString logoUrl = QString::fromStdString(theme.getLogoUrl());

        this->setStyleSheet("#centralwidget{background:url(\""+m_currentBackgroundUrl+"\");}");
        m_ui->m_btnExit->setIcon(QIcon(btnExit));
        m_ui->m_btnNewTask->setIcon(QIcon(btnNewTask));
        m_ui->m_btnNewBoard->setIcon(QIcon(btnNewBoard));
                    m_ui->m_lblLogo->setPixmap(QPixmap(logoUrl));

        KanSoloProjectManager::inst().setDefaultThemeIndex(index);
        if (m_currentBoard)
        {
            m_currentBoard->updateBackgroundUrl(m_currentBackgroundUrl);
        }
    }
}

void UIKanSoloMain::onClose()
{
    this->close();
}

}}}//end namespace

