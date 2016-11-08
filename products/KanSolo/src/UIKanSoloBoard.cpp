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
#include <set>

#include "UIKanSoloBoard.h"

#include <QPainter>
#include <QFontMetrics>

#include <GL/glu.h>
#include <QMessageBox>

#include "utility/inc/StringUtils.hpp"
#include "utility/inc/ColorFactory.h"
#include "utility/inc/DateUtils.hpp"
#include "utility/inc/TimeUtils.hpp"


using namespace cbtek::common::utility;

namespace cbtek {
namespace products {
namespace kan_solo {

UIKanSoloBoard::UIKanSoloBoard(const KanSoloBoard &board,
                               const QString & defaultBoardBackground,
                     QWidget *parent) : QWidget(parent)
{
    m_frameCount = 0;
    m_fps = 0;
    m_timeout = 0;
    m_rebuildBackgroundEvent = true;    
    m_rebuildTaskCacheEvent = true;
    m_updateTaskPositionsEvent = true;

    m_backlogTitle = QString::fromStdString(board.getBacklogTitle());
    m_processingTitle = QString::fromStdString(board.getProcessingTitle());
    m_testingTitle = QString::fromStdString(board.getTestingTitle());
    m_finishedTitle = QString::fromStdString(board.getFinishedTitle());
    m_board=board;

    m_defaultEditButtonIcon.load(":/imgEdit.png");;
    m_DefaultNewButtonIcon.load(":/imgNew.png");;
    m_defaultDeleteButtonIcon.load(":/imgDelete.png");


    m_backgroundTile.load(defaultBoardBackground);

    m_defaultLaneFont = QFont("arial",28);
    m_processingCount = 0;
    m_testingCount = 0;
    m_finishedCount = 0;
    m_backlogCount = 0;
    m_isCardMoving = false;
    m_currentCard = -1;
    setMouseTracking(true);
    m_resized=false;
    m_cardOffsetX = 0;
    m_cardOffsetY = 0;
    m_maxTextHeight = 0;
}

void UIKanSoloBoard::addTask(KanSoloTask task)
{

    TaskCard card;
    bindTaskToCard(task,card);
    m_cards.push_back(card);
    m_taskMap[card.id]=task;
    m_updateTaskPositionsEvent = true;
    m_rebuildBackgroundEvent=true;
    m_rebuildTaskCacheEvent=true;
    resizeEvent(NULL);
}

void UIKanSoloBoard::updateTask(KanSoloTask task)
{
    for (TaskCard & card : m_cards)
    {
        if (card.id==task.getId())
        {
            bindTaskToCard(task,card);
            m_taskMap[card.id]=task;
            m_updateTaskPositionsEvent = true;
            m_rebuildBackgroundEvent=true;
            m_rebuildTaskCacheEvent=true;
            resizeEvent(NULL);
            break;
        }
    }

}

void UIKanSoloBoard::updateBoard(const KanSoloBoard &board)
{
    m_board = board;
    m_processingTitle  = QString::fromStdString(board.getProcessingTitle());
    m_testingTitle  = QString::fromStdString(board.getTestingTitle());
    m_finishedTitle  = QString::fromStdString(board.getFinishedTitle());
    m_backlogTitle  = QString::fromStdString(board.getBacklogTitle());
    rebuildBackground();
    resizeEvent(NULL);
}
void UIKanSoloBoard::bindTaskToCard(const KanSoloTask & task,
                                    TaskCard & card)
{
    card.state = task.getState();
    card.title=task.getTitle();
    card.id = task.getId();
    card.desc=task.getDescription();
    card.parentW=this->width();
    card.parentH=this->height();
    card.x = task.getScaleX() * this->width();
    card.y = task.getScaleY() * this->height();

    //Set background color for priority
    switch(task.getPriority())
    {
        case TaskPriority::HIGH: card.bgColor.set(255,64,64);break;
        case TaskPriority::NORMAL: card.bgColor.set(255,255,127);break;
        case TaskPriority::LOW: card.bgColor.set(127,255,127);break;
        default:break;
    }

    //Set card attributes based on user defined size
    switch(task.getCardSize())
    {
        case TaskCardSize::SMALL:
        {
            card.w = 190;
            card.h = 120;
            card.descFont = Font("arial",10);
            card.titleFont = Font("arial",12);
            card.iconW = 32;
            card.iconH = 48;
            card.noDescIconW = 48;
            card.noDescIconH = 64;
            card.titleH = 24;
            m_defaultBorderWidth = 4;
        }
        break;
        case TaskCardSize::MEDIUM:
        {
            card.w = 270;
            card.h = 160;
            card.descFont = Font("arial",12);
            card.titleFont = Font("arial",14);
            card.iconW = 48;
            card.iconH = 64;
            card.noDescIconW = 64;
            card.noDescIconH = 96;
            card.titleH = 32;
            m_defaultBorderWidth = 6;
        }
        break;
        case TaskCardSize::LARGE:
        {
            card.w = 350;
            card.h = 240;
            card.descFont = Font("arial",16);
            card.titleFont = Font("arial",18);
            card.iconW = 64;
            card.iconH = 96;
            card.noDescIconW = 96;
            card.noDescIconH = 128;
            card.titleH = 48;
            m_defaultBorderWidth = 8;
        }
        break;
        default:break;
    }
    int score = task.getScore();
    if (!m_scoreImageMap.count(score))
    {
        switch(score)
        {
            case 1:this->m_scoreImageMap[score].load(":/imgScore1.png");break;
            case 2:this->m_scoreImageMap[score].load(":/imgScore2.png");break;
            case 3:this->m_scoreImageMap[score].load(":/imgScore3.png");break;
            case 5:this->m_scoreImageMap[score].load(":/imgScore5.png");break;
            case 8:this->m_scoreImageMap[score].load(":/imgScore8.png");break;
            case 13:this->m_scoreImageMap[score].load(":/imgScore13.png");break;
            case 20:this->m_scoreImageMap[score].load(":/imgScore20.png");break;
            case 40:this->m_scoreImageMap[score].load(":/imgScore40.png");break;
            case 100:this->m_scoreImageMap[score].load(":/imgScore100.png");break;
            case 0:this->m_scoreImageMap[score].load(":/imgScoreQuestion.png");break;
            case -1:this->m_scoreImageMap[score].load(":/imgScoreInfinity.png");break;
            case -2:this->m_scoreImageMap[score].load(":/imgScoreHalf.png");break;
            default:break;
        }
    }
    card.scoreImage = m_scoreImageMap[task.getScore()];
}

void UIKanSoloBoard::updateBackgroundUrl(const QString &url)
{

    m_backgroundTile = QImage(url);
    m_rebuildBackgroundEvent=true;
    resizeEvent(NULL);
}

void UIKanSoloBoard::clearTasks()
{
    m_cards.clear();
    m_taskMap.clear();
    m_currentCard = -1;
    m_rebuildBackgroundEvent = true;
    m_rebuildTaskCacheEvent = true;
    resizeEvent(NULL);
}


void UIKanSoloBoard::paintEvent(QPaintEvent *)
{
    if (m_rebuildBackgroundEvent)
    {
        rebuildBackground();
    }

    if (m_rebuildTaskCacheEvent)
    {
        rebuildTaskCache();
    }
    QPainter g(this);
    g.setRenderHint(QPainter::SmoothPixmapTransform);
    g.setRenderHint(QPainter::Antialiasing);
    g.setRenderHint(QPainter::TextAntialiasing);

    g.drawImage(0,0,m_background);

    if (m_updateTaskPositionsEvent)
    {
        updateTaskPositions();
    }

    for (int a1 = 0;a1<m_cards.size();++a1)
    {
        TaskCard & card = m_cards[a1];
        g.drawImage(card.x,card.y,card.image);
    }
    g.end();

    m_rebuildBackgroundEvent = false;
    m_rebuildTaskCacheEvent = false;
    m_updateTaskPositionsEvent = false;
}

void UIKanSoloBoard::mouseMoveEvent(QMouseEvent *e)
{
    m_mx = e->pos().x();
    m_my = e->pos().y();
   if (m_isCardMoving)
   {
       updateLaneCounts();
       TaskCard & card = m_cards.back();
       card.x  = m_mx - card.lx;
       card.y = m_my - card.ly;
       KanSoloTask & task = m_taskMap[card.id];
       double scaleX = ((double)card.x/(double)this->width());
       double scaleY = ((double)card.y/(double)this->height());
       task.setScaleX(scaleX);
       task.setScaleY(scaleY);
       update();
   } 
}

void UIKanSoloBoard::mousePressEvent(QMouseEvent *e)
{
    for (int a1 = m_cards.size()-1;a1>=0;--a1)
    {
        TaskCard card = m_cards[a1];
        if (e->pos().x() >= card.x &&
                e->pos().y() >= card.y &&
                e->pos().x() < card.x+card.w &&
                e->pos().y() < card.y+card.h)
        {
            card.lx = e->pos().x()-card.x;
            card.ly = e->pos().y()-card.y;
            m_currentCard = a1;
            m_cards.erase(m_cards.begin()+a1);
            m_cards.push_back(card);
            m_isCardMoving = true;
            update();
            break;

        }
    }
}

void UIKanSoloBoard::mouseReleaseEvent(QMouseEvent *e)
{
    if (m_currentCard >=0 && m_cards.size())
    {
        updateLaneCounts();
        TaskCard & card = m_cards.back();
        if (m_taskMap.count(card.id))
        {
            KanSoloTask &task = m_taskMap[card.id];

            double scaleX = ((double)card.x/(double)this->width());
            double scaleY = ((double)card.y/(double)this->height());
            task.setScaleX(scaleX);
            task.setScaleY(scaleY);

            task.setState(card.state);
            task.setUpdateDate(DateUtils::getCurrentDate().toDateInteger());
            task.setUpdateTime(TimeUtils::getCurrentTime().toTimeInteger());            
            emit taskUpdated(task);
        }

    }

    m_isCardMoving = false;
    m_currentCard = -1;
}



void UIKanSoloBoard::mouseDoubleClickEvent(QMouseEvent *e)
{

    for (int a1 = m_cards.size()-1;a1>=0;--a1)
    {
        TaskCard card = m_cards[a1];
        if (e->pos().x() >= card.x &&
                e->pos().y() >= card.y &&
                e->pos().x() < card.x+card.w &&
                e->pos().y() < card.y+card.h)
        {
            KanSoloTask task = m_taskMap[card.id];
            if (e->button()==Qt::LeftButton)
            {
                emit taskEdited(task);
                e->accept();
                update();
                return;
            }
            else if (e->button() == Qt::RightButton)
            {
                if (QMessageBox::information(this,"Delete Task...","Are you sure you want to delete this task: \""+QString::fromStdString(task.getTitle())+"\"?",QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes)
                {
                    m_cards.erase(m_cards.begin()+a1);
                    m_taskMap.erase(task.getId());
                    updateLaneCounts();
                    emit taskDeleted(task);
                    update();
                    e->accept();
                    return;
                }
            }

        }
    }
    int mx = e->pos().x();
    int my = e->pos().y();
    QRect boardNamesRect(0,0,this->width(),this->m_maxTextHeight);

    if (boardNamesRect.contains(mx,my))
    {
        if (e->button()==Qt::LeftButton)
        {
            emit boardEdited(m_board);
            e->accept();
            return;
        }
        else if (e->button() == Qt::RightButton)
        {

        }
    }
}
void UIKanSoloBoard::resizeEvent(QResizeEvent *)
{
    m_background =  QImage(this->width(),this->height(),QImage::Format_RGB32);
    m_rebuildBackgroundEvent = true;
    m_updateTaskPositionsEvent = true;
    m_rebuildTaskCacheEvent = true;
    update();
    setWindowTitle(QString::number(this->width())+" x "+QString::number(this->height()));
}

void UIKanSoloBoard::updateLaneCounts()
{

    int lastBacklogCount = m_backlogCount;
    int lastTestingCount = m_testingCount;
    int lastProcessingCount = m_processingCount;
    int lastFinishedCount = m_finishedCount;

    m_backlogCount = 0;
    m_testingCount = 0;
    m_processingCount = 0;
    m_finishedCount = 0;
    for (TaskCard & card : m_cards)
    {
        if (m_backlogRect.contains(card.x+(card.w/2),card.y+(card.h/2)))
        {
            m_backlogCount++;
            card.state = TaskState::BACKLOG;
        }
        else if (m_processingRect.contains(card.x+(card.w/2),card.y+(card.h/2)))
        {
            m_processingCount++;
            card.state = TaskState::PROCESSING;
        }
        else if (m_testingRect.contains(card.x+(card.w/2),card.y+(card.h/2)))
        {
            m_testingCount++;
            card.state = TaskState::TESTING;
        }
        else if (m_finishedRect.contains(card.x+(card.w/2),card.y+(card.h/2)))
        {
            m_finishedCount++;
            card.state = TaskState::FINISHED;
        }
    }

    bool noChange =  (lastBacklogCount == m_backlogCount &&
        lastProcessingCount == m_processingCount &&
        lastTestingCount == m_testingCount &&
        lastFinishedCount == m_finishedCount);

    if (!noChange)
    {
        m_rebuildBackgroundEvent = true;
    }
}

void UIKanSoloBoard::updateTaskPositions()
{
    for (TaskCard & card : m_cards)
    {
        KanSoloTask & task = m_taskMap[card.id];
        QRect lane;
        switch(task.getState())
        {
            case TaskState::BACKLOG:lane = m_backlogRect;break;
            case TaskState::PROCESSING:lane = m_processingRect;break;
            case TaskState::TESTING:lane = m_testingRect;break;
            case TaskState::FINISHED:lane = m_finishedRect;break;
            default:break;

        }
        double scaleX = task.getScaleX();
        double scaleY = task.getScaleY();
       card.x = (int)(scaleX * (double)this->width());
       card.y = (int)(scaleY * (double)this->height());
    }
    updateLaneCounts();

}

void UIKanSoloBoard::rebuildTaskCache()
{
    for (int a1 = 0;a1<m_cards.size();++a1)
    {
        TaskCard & card = m_cards[a1];
        card.image = QImage(card.w,card.h, QImage::Format_RGB32);
        int w = card.w;
        int h = card.h;
        QPainter g(&card.image);
        g.setRenderHint(QPainter::SmoothPixmapTransform);
        g.setRenderHint(QPainter::Antialiasing);
        g.setRenderHint(QPainter::TextAntialiasing);
        g.setRenderHint(QPainter::HighQualityAntialiasing);

        QColor fg(card.fgColor.getRed(),
                  card.fgColor.getGreen(),
                  card.fgColor.getBlue());

        QColor bg(card.bgColor.getRed(),
                  card.bgColor.getGreen(),
                  card.bgColor.getBlue());

        //Draw card background
        //g.fillRect(0,0,card.w,card.h,bg);
        g.setBrush(QColor(bg));
        g.drawRoundedRect(0,0,card.w,card.h,10,10);

        //Draw card foreground
        QPen pen;
        if (card.hover)
        {
            pen.setColor(Qt::white);
        }
        else
        {
            pen.setColor(fg);
        }

        pen.setWidth(m_defaultBorderWidth);
        g.setPen(pen);
        //g.drawRect(0,0,w,h);
        g.drawRoundedRect(0,0,w,h,10,10);

        QTextOption option;
        option.setAlignment(Qt::AlignHCenter);
        int textInset=8;
        g.setPen(Qt::black);
        g.setFont(QFont(QString::fromStdString(card.titleFont.getFontFamily()),card.titleFont.getPointSize(),QFont::Bold));

        QFontMetrics metrics(g.font());
        int tx=textInset;
        int ty=textInset;
        int tw=w-textInset-textInset;
        int th=card.titleH;

        QString text = metrics.elidedText(QString::fromStdString(card.title),Qt::ElideRight,tw);
        g.drawText(QRectF(tx,ty,tw,th),text,option);

        //Draw Task Description
        g.setFont(QFont(QString::fromStdString(card.descFont.getFontFamily()),card.descFont.getPointSize()));
        metrics = QFontMetrics(g.font());
        ty+=card.titleH;
        tw-=card.iconW;
        option.setAlignment(Qt::AlignLeft);
        th = h-textInset-card.titleH;
        option.setWrapMode(QTextOption::WordWrap);               
        int metricHeight = metrics.height();
        if (metricHeight == 0)
        {
            metricHeight=1;
        }
        if (card.desc.empty())
        {
            int cx = (card.w/2)-(card.noDescIconW/2);
            int cy = (card.h/2)-(card.noDescIconH/2);
            g.drawImage(QRect(cx,cy+(card.titleH/2),card.noDescIconW,card.noDescIconH),card.scoreImage);
        }
        else
        {
            text = metrics.elidedText(QString::fromStdString(card.desc),Qt::ElideRight,tw*((th/metricHeight)-2));
            g.drawText(QRectF(tx,ty,tw,th),text,option);
            g.drawImage(QRect(tx+tw+(textInset/2),
                             ty+((th/2) - (card.iconH/2) ),
                             card.iconW,
                             card.iconH),card.scoreImage);
        }
        g.end();
    }

}

void UIKanSoloBoard::rebuildBackground()
{
    QPainter g(&m_background);
    g.setRenderHint(QPainter::SmoothPixmapTransform);
    g.setRenderHint(QPainter::Antialiasing);
    g.setRenderHint(QPainter::TextAntialiasing);

    int bw = m_backgroundTile.width();
    int bh = m_backgroundTile.height();
    if (bw<1)
    {
        bw=1;
    }
    if (bh<1)
    {
        bh=1;
    }
    int bc = this->width()/bw;
    int br = this->height()/bh;


    for (size_t a1 = 0;a1 <= bc;++a1)
    {
        for (size_t a2 = 0;a2<= br;++a2)
        {
            g.drawImage(QRect(a1*bw,a2*bh,bw,bh),m_backgroundTile);
        }
    }


    g.setRenderHint(QPainter::SmoothPixmapTransform);
    g.setRenderHint(QPainter::Antialiasing);
    g.setRenderHint(QPainter::TextAntialiasing);

    int tw = this->width()/4;
    int th = this->height();

    m_backlogRect    = QRect(0,0,tw,th);
    m_processingRect = QRect(tw,0,tw,th);
    m_testingRect    = QRect(tw*2,0,tw,th);
    m_finishedRect   = QRect(tw*3,0,tw,th);
    this->updateLaneCounts();

    std::set<int> heights;
    std::set<int> fontSizes;
    QTextOption option;
    option.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QString backlogText = (QString::number(m_backlogCount)+" in "+m_backlogTitle);
    QFont backlogFont = getAutoFont(backlogText,tw);
    fontSizes.insert(backlogFont.pointSize());
    QFontMetrics backlogMetrics(backlogFont);
    heights.insert(backlogMetrics.height());

    QString processingText = (QString::number(m_processingCount)+" in "+m_processingTitle);
    QFont processingFont = getAutoFont(processingText,tw);
    fontSizes.insert(processingFont.pointSize());
    QFontMetrics processingMetrics(processingFont);
    heights.insert(processingMetrics.height());

    QString testingText = (QString::number(m_testingCount)+" in "+m_testingTitle);
    QFont testingFont = getAutoFont(testingText,tw);
    fontSizes.insert(testingFont.pointSize());
    QFontMetrics testingMetrics(testingFont);
    heights.insert(testingMetrics.height());

    QString finishedText = (QString::number(m_finishedCount) +" in "+m_finishedTitle);
    QFont finishedFont = getAutoFont(finishedText,tw);
    fontSizes.insert(finishedFont.pointSize());
    QFontMetrics finishedMetrics(finishedFont);
    heights.insert(finishedMetrics.height());

    m_maxTextHeight = (*heights.begin())+8;

    g.setFont(QFont("arial",(*fontSizes.begin())));

    g.fillRect(QRect(0,0,this->width(),m_maxTextHeight),QColor(255,255,255));
    QPen lastPen = g.pen();
    QPen pen;
    pen.setWidth(4);
    pen.setColor(Qt::black);
    g.setPen(pen);
    g.drawRect(QRect(0,0,this->width(),m_maxTextHeight));
    g.setPen(lastPen);
    g.drawText(QRect(m_finishedRect.x(),m_finishedRect.y(),m_finishedRect.width(),m_maxTextHeight),finishedText,option);
    g.drawText(QRect(m_testingRect.x(),m_testingRect.y(),m_testingRect.width(),m_maxTextHeight),testingText,option);
    g.drawText(QRect(m_processingRect.x(),m_processingRect.y(),m_processingRect.width(),m_maxTextHeight),processingText,option);
    g.drawText(QRect(m_backlogRect.x(),m_backlogRect.y(),m_backlogRect.width(),m_maxTextHeight),backlogText,option);

    pen = g.pen();
    pen.setColor(QColor(0,0,0,127));
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(4);
    g.setPen(pen);

    g.drawRect(m_backlogRect);
    g.drawRect(m_processingRect);
    g.drawRect(m_testingRect);
    g.drawRect(m_finishedRect);
    g.end();
}



QFont UIKanSoloBoard::getAutoFont(const QString &text,int width, int maxPointSize) const
{
    QFont font("arial",48);
    while (QFontMetrics(font).width(text) > width)
    {
        font = QFont("arial",font.pointSize()-4);
        if (font.pointSize() < 6)
        {
            break;
        }
        if (font.pointSize() > maxPointSize)
        {
            font.setPointSize(maxPointSize);
        }
    }
    return font;
}


UIKanSoloBoard::~UIKanSoloBoard()
{ 
}


}}}//end namespace

