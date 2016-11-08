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
#ifndef _CBTEK_PRODUCTS_KANSOLO_UIKANSOLOBOARD_H
#define _CBTEK_PRODUCTS_KANSOLO_UIKANSOLOBOARD_H
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMouseEvent>

#include "utility/inc/ObjectList.hpp"
#include "utility/inc/Color.h"
#include "utility/inc/Font.h"

#include "KanSoloTask.h"
#include "KanSoloBoard.h"

namespace cbtek {
namespace products {
namespace kan_solo {

struct TaskCard
{
    std::string title,desc,id;
    QImage scoreImage;
    common::utility::Color bgColor;
    common::utility::Color fgColor;
    common::utility::Font titleFont;
    common::utility::Font descFont;
    bool hover;
    int x,y,w,h;
    int lx,ly;
    int laneOffsetX;
    int laneOffsetY;
    int iconW,iconH,titleH;
    int parentW,parentH;
    int noDescIconW,noDescIconH;
    QImage image;
    TaskState state;
};

class UIKanSoloBoard : public QWidget
{
    Q_OBJECT

public:
    //! Constructor for UIKanSoloBoard
	/*!
        Detailed description for UIKanSoloBoard
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIKanSoloBoard(const KanSoloBoard & board, const QString &defaultBoardBackground,
                       QWidget *parent = 0);


    KanSoloBoard getBoard() const;
    void addTask(KanSoloTask task);
    void updateTask(KanSoloTask task);
    void updateBoard(const KanSoloBoard & board);
    void updateBackgroundUrl(const QString & url);
    void clearTasks();
    //! Descructor for UIKanSoloBoard
    ~UIKanSoloBoard();
protected:
    void mouseDoubleClickEvent(QMouseEvent * e);
    void mouseMoveEvent(QMouseEvent * e);
    void mousePressEvent(QMouseEvent * e);
    void mouseReleaseEvent(QMouseEvent * e);
    void paintEvent(QPaintEvent *);
    void updateCardQueue(size_t currentCard);
    void updateBuffer(QPainter &g);
    void resizeEvent(QResizeEvent *);
    void updateLaneCounts();
    void updateLaneLabels();
    void updateTaskPositions();
    void rebuildTaskCache();    
    void rebuildBackground();    
    void bindTaskToCard(const KanSoloTask & task,
                        TaskCard & card);

    QFont getAutoFont(const QString &text,
                      int width,
                      int maxPointSize=32) const;

private:

    std::vector<TaskCard> m_cards;
    bool m_isCardMoving;
    int m_currentCard;
    int m_frameCount;
    int m_timeout;
    common::utility::SizeTList m_cardQueue;        
    common::utility::Font m_defaultTitleFont;
    common::utility::Font m_defaultDescriptionFont;
    size_t m_defaultWidth;
    size_t m_defaultHeight;
    size_t m_defaultIconWidth;
    size_t m_defaultIconHeight;
    size_t m_defaultTitleHeight;
    QFont m_defaultLaneFont;
    QString m_backlogTitle;
    QString m_processingTitle;
    QString m_testingTitle;
    QString m_finishedTitle;    
    int m_timerId;
    int m_fps;
    int m_mx;
    int m_my;
    int m_backlogCount;
    int m_processingCount;
    int m_testingCount;
    int m_finishedCount;
    int m_cardOffsetX;
    int m_cardOffsetY;
    int m_maxTextHeight;
    int m_defaultBorderWidth;
    common::utility::Random m_rnd;

    bool m_rebuildBackgroundEvent;    
    bool m_rebuildTaskCacheEvent;
    bool m_updateTaskPositionsEvent;

    QRect m_backlogRect;
    QRect m_processingRect;
    QRect m_testingRect;
    QRect m_finishedRect;

    QImage m_defaultPushpin;
    QImage m_defaultEditButtonIcon;
    QImage m_DefaultNewButtonIcon;
    QImage m_defaultDeleteButtonIcon;


    QImage m_buffer;
    QImage m_background;
    QImage m_backgroundTile;

    bool m_resized;
    std::map<int, QImage> m_scoreImageMap;
    KanSoloBoard m_board;
    std::map<std::string,KanSoloTask> m_taskMap;
signals:
    void taskUpdated(const KanSoloTask & task);
    void taskEdited(const KanSoloTask & task);
    void taskDeleted(const KanSoloTask & task);
    void boardEdited(const KanSoloBoard & board);
    void boardDeleted(const KanSoloBoard & board);
};



}}}//end namespace

#endif // _CBTEK_PRODUCTS_KANSOLO_UIKANSOLOBOARD_H
