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

#ifndef _CBTEK_PRODUCTS_SOLO_SCRUM_UISOLOAGILETASKTILE_H
#define _CBTEK_PRODUCTS_SOLO_SCRUM_UISOLOAGILETASKTILE_H
#include <QWidget>

#include "KanSoloTask.h"

#include <QPainter>
#include <QMouseEvent>

class Ui_UIKanSoloTaskTile;

namespace cbtek {
namespace products {
namespace kan_solo {


class UIKanSoloTaskTile : public QWidget
{
    Q_OBJECT

public:
	//! Constructor for UIKanSoloTaskTile
	/*!
		Detailed description for UIKanSoloTaskTile
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIKanSoloTaskTile(const KanSoloTask & task, QWidget *parent = 0);
    

    void paintEvent(QPaintEvent * evt);
	//! Descructor for UIKanSoloTaskTile
    ~UIKanSoloTaskTile();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIKanSoloTaskTile *m_ui;

     KanSoloTask m_task;

     QColor m_currentBG;

     int m_currentLane;
     QImage m_currentImage;
     QImage  m_currentScoreImage;
    void mouseDoubleClickEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent * e);

private slots:
    void onDelete();
    void onPromote();
    void onDemote();
    void onEdit();
signals:
    void promote(KanSoloTask task);
    void demote(KanSoloTask task);
    void remove(KanSoloTask task);
    void edit(KanSoloTask task);

};

}}}//end namespace

#endif // _CBTEK_PRODUCTS_SOLO_SCRUM_UISOLOAGILETASKTILE_H
