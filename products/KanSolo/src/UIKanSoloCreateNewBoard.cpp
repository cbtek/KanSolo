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
#include "UIKanSoloCreateNewBoard.h"
#include "ui_UIKanSoloCreateNewBoard.h"


#include <QMessageBox>

#include "utility/inc/StringUtils.hpp"

#include "KanSoloProjectManager.h"

using namespace cbtek::common::utility;

namespace cbtek {
namespace products {
namespace kan_solo {


UIKanSoloCreateNewBoard::UIKanSoloCreateNewBoard(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui_UIKanSoloCreateNewBoard)
{
    m_ui->setupUi(this);    
    connect(m_ui->m_btnSave,SIGNAL(clicked(bool)),this,SLOT(onSave()));
    connect(m_ui->m_btnCancel,SIGNAL(clicked(bool)),this,SLOT(close()));
    m_isUpdate = false;
}

UIKanSoloCreateNewBoard::UIKanSoloCreateNewBoard(const KanSoloBoard &board,
                                                 QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui_UIKanSoloCreateNewBoard)
{
    m_ui->setupUi(this);
    connect(m_ui->m_btnSave,SIGNAL(clicked(bool)),this,SLOT(onSave()));
    connect(m_ui->m_btnCancel,SIGNAL(clicked(bool)),this,SLOT(close()));
    m_ui->m_txtBacklogLabel->setText(QString::fromStdString(board.getBacklogTitle()));
    m_ui->m_txtTestingLabel->setText(QString::fromStdString(board.getTestingTitle()));
    m_ui->m_txtProcessingLabel->setText(QString::fromStdString(board.getProcessingTitle()));
    m_ui->m_txtFinishedLabel->setText(QString::fromStdString(board.getFinishedTitle()));
    m_ui->m_txtBoardName->setText(QString::fromStdString(board.getTitle()));
    m_isUpdate = true;
    this->setWindowTitle("Edit Board");
    m_board=board;
}


UIKanSoloCreateNewBoard::~UIKanSoloCreateNewBoard()
{
    delete m_ui;
}

void UIKanSoloCreateNewBoard::onSave()
{
    if (m_ui->m_txtBoardName->text().trimmed().isEmpty())
    {
        QMessageBox::information(this,"Empty Name?","Please input a valid board name!");
        m_ui->m_txtBoardName->setFocus();
        return;
    }

    if (m_ui->m_txtBacklogLabel->text().trimmed().isEmpty())
    {
        QMessageBox::information(this,"Empty Field?","Please input a valid backlog title!");
        m_ui->m_txtBacklogLabel->setFocus();
        return;
    }
    if (m_ui->m_txtProcessingLabel->text().trimmed().isEmpty())
    {
        QMessageBox::information(this,"Empty Field?","Please input a valid processing title!");
        m_ui->m_txtProcessingLabel->setFocus();
        return;
    }
    if (m_ui->m_txtTestingLabel->text().trimmed().isEmpty())
    {
        QMessageBox::information(this,"Empty Field?","Please input a valid processing title!");
        m_ui->m_txtTestingLabel->setFocus();
        return;
    }
    if (m_ui->m_txtFinishedLabel->text().trimmed().isEmpty())
    {
        QMessageBox::information(this,"Empty Field?","Please input a valid finished title!");
        m_ui->m_txtFinishedLabel->setFocus();
        return;
    }

    m_board.setTitle(m_ui->m_txtBoardName->text().toStdString());
    m_board.setBacklogTitle(m_ui->m_txtBacklogLabel->text().toStdString());
    m_board.setProcessingTitle(m_ui->m_txtProcessingLabel->text().toStdString());
    m_board.setTestingTitle(m_ui->m_txtTestingLabel->text().toStdString());
    m_board.setFinishedTitle(m_ui->m_txtFinishedLabel->text().toStdString());

    if (!m_isUpdate)
    {
        m_board.setId("BOARD-"+StringUtils::createUUID(true));
        try
        {
            KanSoloProjectManager::inst().createBoard(m_board);
            emit boardCreated(m_board);
        }
        catch(std::exception & e)
        {
            QMessageBox::critical(this,"Board Creation Exception!","An exception was thrown when trying to create the board named \""+QString::fromStdString(m_board.getTitle())+"\":\n "+QString::fromStdString(std::string(e.what())));
        }
    }
    else
    {
        try
        {
            KanSoloProjectManager::inst().updateBoard(m_board);
            emit boardUpdated(m_board);
        }
        catch(std::exception & e)
        {
            QMessageBox::critical(this,"Board Update Exception!","An exception was thrown when trying to update the board named \""+QString::fromStdString(m_board.getTitle())+"\":\n "+QString::fromStdString(std::string(e.what())));
        }
    }


    this->close();
}

}}}//end namespace

