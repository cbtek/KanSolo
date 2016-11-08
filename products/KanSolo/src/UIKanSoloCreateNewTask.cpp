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
#include <QMessageBox>
#include <QHeaderView>
#include <QLabel>

#include "utility/inc/TimeUtils.hpp"
#include "utility/inc/DateTimeUtils.hpp"

#include "UIKanSoloCreateNewTask.h"
#include "ui_UIKanSoloCreateNewTask.h"

using namespace cbtek::common::utility;

namespace cbtek {
namespace products {
namespace kan_solo {

UIKanSoloCreateNewTask::UIKanSoloCreateNewTask(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui_UIKanSoloCreateNewTask)
{
    m_ui->setupUi(this);
    setupScoreList();
    setupPriorityList();
    setupSizeList();
    setPriority(TaskPriority::LOW);
    setCardSize(TaskCardSize::SMALL);
    setScore(-2);
    connect(m_ui->m_btnSave,SIGNAL(clicked(bool)),this,SLOT(onSaveNew()));
    connect(m_ui->m_btnCancel,SIGNAL(clicked(bool)),this,SLOT(onCancel()));

}

UIKanSoloCreateNewTask::UIKanSoloCreateNewTask(const KanSoloTask & task, QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui_UIKanSoloCreateNewTask)
{

    m_ui->setupUi(this);
    m_task = task;
    setupScoreList();
    setupPriorityList();
    setupSizeList();
    m_ui->m_txtTask->setText(QString::fromStdString(m_task.getDescription()));
    m_ui->m_txtTitle->setText(QString::fromStdString(m_task.getTitle()));

    this->setPriority(m_task.getPriority());
    this->setScore(m_task.getScore());
    this->setCardSize(m_task.getCardSize());

    connect(m_ui->m_btnSave,SIGNAL(clicked(bool)),this,SLOT(onSaveExisting()));
    connect(m_ui->m_btnCancel,SIGNAL(clicked(bool)),this,SLOT(onCancel()));


}


UIKanSoloCreateNewTask::~UIKanSoloCreateNewTask()
{
    delete m_ui;
}

TaskPriority UIKanSoloCreateNewTask::getPriority() const
{
    QModelIndex index = m_ui->m_tblPriority->currentIndex();
    if (index.isValid())
    {
        QWidget * widget = m_ui->m_tblPriority->cellWidget(index.row(),index.column());
        if (widget)
        {
            return static_cast<TaskPriority>(widget->property("priority").toInt());
        }
    }
    return TaskPriority::LOW;
}

TaskCardSize UIKanSoloCreateNewTask::getCardSize() const
{
//    QModelIndex index = m_ui->m_tblSize->currentIndex();
//    if (index.isValid())
//    {
//        QWidget * widget = m_ui->m_tblSize->cellWidget(index.row(),index.column());
//        if (widget)
//        {
//            return static_cast<TaskCardSize>(widget->property("size").toInt());
//        }
//    }
    return TaskCardSize::SMALL;
}

int UIKanSoloCreateNewTask::getScore() const
{
    QModelIndex index = m_ui->m_tblScores->currentIndex();
    if (index.isValid())
    {
        QWidget * widget = m_ui->m_tblScores->cellWidget(index.row(),index.column());
        if (widget)
        {
            return static_cast<int>(widget->property("score").toInt());
        }
    }
    return -2;
}

void UIKanSoloCreateNewTask::setPriority(TaskPriority priority)
{
    QLabel * label = m_priorityItemMap[priority];

    if (label)
    {
        int row = label->property("row").toInt();
        int col = label->property("col").toInt();
        m_ui->m_tblPriority->setCurrentCell(row,col);
    }
}

void UIKanSoloCreateNewTask::setScore(int score)
{
    QLabel * label = m_scoreItemMap[score];

    if (label)
    {
        int row = label->property("row").toInt();
        int col = label->property("col").toInt();
        m_ui->m_tblScores->setCurrentCell(row,col);
    }
}


void UIKanSoloCreateNewTask::setCardSize(TaskCardSize size)
{
//    QLabel * label = m_sizeItemMap[size];

//    if (label)
//    {
//        int row = label->property("row").toInt();
//        int col = label->property("col").toInt();
//        m_ui->m_tblSize->setCurrentCell(row,col);
//    }
}

void UIKanSoloCreateNewTask::setupScoreList()
{
    m_ui->m_tblScores->clear();
    m_ui->m_tblScores->setRowCount(2);
    m_ui->m_tblScores->setColumnCount(6);
    QStringList icons;
    Int64List scores;
    icons << ":/imgScoreHalf.png";
    icons << ":/imgScore1.png";
    icons << ":/imgScore2.png";
    icons << ":/imgScore3.png";
    icons << ":/imgScore5.png";
    icons << ":/imgScore8.png";
    icons << ":/imgScore13.png";
    icons << ":/imgScore20.png";
    icons << ":/imgScore40.png";
    icons << ":/imgScore100.png";
    icons << ":/imgScoreInf.png";
    icons << ":/imgScoreQuestion.png";

    scores << -2;
    scores << 1;
    scores << 2;
    scores << 3;
    scores << 5;
    scores << 8;
    scores << 13;
    scores << 20;
    scores << 40;
    scores << 100;
    scores << -1;
    scores << 0;

    int row=0,col=0;
    for(size_t a1 = 0;a1<scores.size();++a1)
    {
        int score = scores[a1];
        QString iconStr = icons[a1];
        QLabel * label = new QLabel;
        label->setPixmap(QPixmap::fromImage(QImage(iconStr)));
        label->setProperty("score",score);
        label->setProperty("row",row);
        label->setProperty("col",col);
        label->setAlignment(Qt::AlignCenter);
        label->setScaledContents(true);
        m_ui->m_tblScores->setCellWidget(row,col,label);
        m_scoreItemMap[score]=label;
        ++col;
        if (col > 5)
        {
            col=0;
            ++row;
        }
    }

    m_ui->m_tblScores->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_ui->m_tblScores->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void UIKanSoloCreateNewTask::setupPriorityList()
{
    m_ui->m_tblPriority->clear();
    m_ui->m_tblPriority->setRowCount(1);
    m_ui->m_tblPriority->setColumnCount(3);
    ObjectList<TaskPriority> priorities;
    priorities << TaskPriority::LOW;
    priorities << TaskPriority::NORMAL;
    priorities << TaskPriority::HIGH;
    for(size_t a1 = 0;a1<priorities.size();++a1)
    {
        TaskPriority priority = priorities[a1];
        QLabel * label = new QLabel;
        switch(priority)
        {
            case TaskPriority::LOW:
            {
                label->setText("Low");
                label->setFont(QFont("arial",18,QFont::Bold));
                label->setStyleSheet("QLabel{color:#aaffaa;background:#222;border-radius:4px;}");
            }
            break;
            case TaskPriority::NORMAL:
            {
                label->setText("Normal");
                label->setFont(QFont("arial",18,QFont::Bold));
                label->setStyleSheet("QLabel{color:#ffffaa;background:#222;border-radius:4px;}");
            }
            break;
            case TaskPriority::HIGH:
            {
                label->setText("High");
                label->setFont(QFont("arial",18,QFont::Bold));
                label->setStyleSheet("QLabel{color:#ffaaaa;background:#222;border-radius:4px;}");
            }
            break;
        }

        label->setProperty("priority",static_cast<int>(priority));
        label->setProperty("row",QVariant(0));
        label->setProperty("col",QVariant(static_cast<int>(a1)));
        label->setAlignment(Qt::AlignCenter);
        m_priorityItemMap[priority]=label;
        m_ui->m_tblPriority->setCellWidget(0,a1,label);

    }

    m_ui->m_tblPriority->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_ui->m_tblPriority->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void UIKanSoloCreateNewTask::setupSizeList()
{
//    m_ui->m_tblSize->clear();
//    m_ui->m_tblSize->setRowCount(1);
//    m_ui->m_tblSize->setColumnCount(3);
//    ObjectList<TaskCardSize> sizes;
//    sizes << TaskCardSize::SMALL;
//    sizes << TaskCardSize::MEDIUM;
//    sizes << TaskCardSize::LARGE;
//    for(size_t a1 = 0;a1<sizes.size();++a1)
//    {
//        TaskCardSize size = sizes[a1];
//        QLabel * label = new QLabel;
//        switch(size)
//        {
//            case TaskCardSize::SMALL:
//            {
//                label->setText("small");
//                label->setFont(QFont("arial",10));
//                label->setStyleSheet("QLabel{color:#ffffff;background:#222222;border-radius:4px;}");
//            }
//            break;
//            case TaskCardSize::MEDIUM:
//            {
//                label->setText("Medium");
//                label->setFont(QFont("arial",14));
//                label->setStyleSheet("QLabel{color:#ffffff;background:#222;border-radius:4px;}");
//            }
//            break;
//            case TaskCardSize::LARGE:
//            {
//                label->setText("LARGE");
//                label->setFont(QFont("arial",18,QFont::Bold));
//                label->setStyleSheet("QLabel{color:#ffffff;background:#222;border-radius:4px;}");
//            }
//            break;
//        }

//        m_sizeItemMap[size] = label;
//        label->setProperty("size",static_cast<int>(size));
//        label->setProperty("row",0);
//        label->setProperty("col",QVariant(static_cast<int>(a1)));
//        label->setAlignment(Qt::AlignCenter);

//        m_ui->m_tblSize->setCellWidget(0,a1,label);

//    }

//    m_ui->m_tblSize->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    m_ui->m_tblSize->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void UIKanSoloCreateNewTask::onSave()
{
    m_task.setDescription(this->m_ui->m_txtTask->toPlainText().toStdString());
    m_task.setTitle(this->m_ui->m_txtTitle->text().toStdString());
    m_task.setPriority(getPriority());
    m_task.setScore(getScore());
    m_task.setCardSize(getCardSize());
}

void UIKanSoloCreateNewTask::onSaveNew()
{
    if (m_ui->m_txtTitle->text().trimmed().isEmpty())
    {
        QMessageBox::information(this,"No title...","Please enter a title for this task.");
        m_ui->m_txtTitle->setFocus();
        return;
    }
    onSave();
    emit taskCreated(m_task);
    this->close();
}

void UIKanSoloCreateNewTask::onSaveExisting()
{
    if (m_ui->m_txtTitle->text().trimmed().isEmpty())
    {
        QMessageBox::information(this,"No title...","Please enter a title for this task.");
        m_ui->m_txtTitle->setFocus();
        return;
    }
    onSave();
    emit taskUpdated(m_task);
    this->close();
}

void UIKanSoloCreateNewTask::onCancel()
{
    this->close();
}

}}}//end namespace

