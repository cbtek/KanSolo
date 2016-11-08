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

#include "UIKanSoloTaskTile.h"
#include "ui_UIKanSoloTaskTile.h"

namespace cbtek {
namespace products {
namespace kan_solo {


UIKanSoloTaskTile::UIKanSoloTaskTile(const KanSoloTask &task, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui_UIKanSoloTaskTile)
{
    m_ui->setupUi(this);
    m_task = task;

    m_ui->m_txtTitle->setText(QString::fromStdString(task.getTitle()));
    m_ui->m_txtDescription->setText(QString::fromStdString(task.getDescription()));

    if (m_task.getPriority() == TaskPriority::LOW)
    {
        //m_currentImage.load(":/imgScrumNoteLow.png");
        m_currentBG.setRgb(127,255,127);
    }

    else if (m_task.getPriority() == TaskPriority::NORMAL)
    {
        //m_currentImage.load(":/imgScrumNoteNormal.png");
        m_currentBG.setRgb(255,255,127);
    }

    else if (m_task.getPriority() == TaskPriority::HIGH)
    {
        //m_currentImage.load(":/imgScrumNoteHigh.png");
        m_currentBG.setRgb(255,127,127);
    }


    switch(m_task.getScore())
    {
        case 1:m_currentScoreImage.load(":/imgScore1.png");break;
        case 2:m_currentScoreImage.load(":/imgScore2.png");break;
        case 3:m_currentScoreImage.load(":/imgScore3.png");break;
        case 5:m_currentScoreImage.load(":/imgScore5.png");break;
        case 8:m_currentScoreImage.load(":/imgScore8.png");break;
        case 13:m_currentScoreImage.load(":/imgScore13.png");break;
        case 20:m_currentScoreImage.load(":/imgScore20.png");break;
        case 40:m_currentScoreImage.load(":/imgScore40.png");break;
        case 100:m_currentScoreImage.load(":/imgScore100.png");break;
        case 0:m_currentScoreImage.load(":/imgScoreQuestion.png");break;
        case -1:m_currentScoreImage.load(":/imgScoreInfinity.png");break;
        case -2:m_currentScoreImage.load(":/imgScoreHalf.png");break;
        default:break;
    }
    m_ui->m_lblScore->setPixmap(QPixmap::fromImage(m_currentScoreImage));
    m_ui->m_lblScore->setScaledContents(true);
    connect(m_ui->m_btnClose,SIGNAL(clicked(bool)),this,SLOT(onDelete()));
    connect(m_ui->m_btnEdit,SIGNAL(clicked(bool)),this,SLOT(onEdit()));

}

void UIKanSoloTaskTile::paintEvent(QPaintEvent *evt)
{
    QPainter g(this);    
    //g.setRenderHint(QPainter::SmoothPixmapTransform,true);
    //g.drawImage(QRectF(0,0,this->width(),this->height()),m_currentImage);
    int lw = 0;
    g.fillRect(QRectF(lw,lw,this->width()-lw-lw,this->height()-lw-lw),m_currentBG);
    QPen pen = g.pen();
    pen.setColor(QColor(0,0,0));
    pen.setWidth(4);
    g.setPen(pen);
    g.drawRect(QRectF(0,0,this->width(),this->height()));
}

UIKanSoloTaskTile::~UIKanSoloTaskTile()
{
    delete m_ui;
}

void UIKanSoloTaskTile::mouseDoubleClickEvent(QMouseEvent *e)
{
    if (e->button()==Qt::LeftButton)
    {
        onPromote();
    }
    else if (e->button()==Qt::RightButton)
    {
        onDemote();
    }
}

void UIKanSoloTaskTile::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button()==Qt::LeftButton)
    {
        onEdit();
    }
}

void UIKanSoloTaskTile::onDelete()
{
    int button = QMessageBox::question(this,"Delete Task?","Are you sure you want to delete this task?");
    if (button == QMessageBox::Yes)
    {
        //m_task.update();
        emit remove(m_task);
    }
}

void UIKanSoloTaskTile::onPromote()
{
    //m_task.update();
    emit promote(m_task);
}

void UIKanSoloTaskTile::onDemote()
{
    //m_task.update();
    emit demote(m_task);
}

void UIKanSoloTaskTile::onEdit()
{
    //m_task.update();
    emit edit(m_task);
}

}}}//end namespace

