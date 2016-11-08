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
#ifndef _CBTEK_PRODUCTS_KAN_SOLO_MAIN_H
#define _CBTEK_PRODUCTS_KAN_SOLO_MAIN_H

#include <QMainWindow>
#include <QKeyEvent>

#include "KanSoloTheme.h"
#include "UIKanSoloCreateNewTask.h"
#include "UIKanSoloTaskTile.h"
#include "UIKanSoloBoard.h"

#include "utility/inc/Random.h"

class Ui_UIKanSoloMain;

namespace cbtek {
namespace products {
namespace kan_solo {

class UIKanSoloMain : public QMainWindow
{
    Q_OBJECT

public:
    //! Constructor for UIKanSoloMain
	/*!
        Detailed description for UIKanSoloMain
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIKanSoloMain(QWidget *parent = 0);
    
    
    //! Descructor for UIKanSoloMain
    ~UIKanSoloMain();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIKanSoloMain *m_ui;
    std::map<int,size_t> m_laneCount;
    void loadTasks();    
    int getNextPosition(int lane);
    void resizeEvent(QResizeEvent *);
    void keyPressEvent(QKeyEvent * );
    void showEvent(QShowEvent *);   
    QString m_currentBoardId;
    QString m_currentBackgroundUrl;
    bool m_toggleFullScreen;
    UIKanSoloBoard * m_currentBoard;
    QVector<UIKanSoloBoard*> m_boards;
    std::vector<KanSoloTheme>  m_currentThemes;

private slots:

     void onCreateTask();
     void onCreateTask(KanSoloTask task);
     void onEditTask(KanSoloTask task);
     void onRemoveTask(const KanSoloTask &task);     
     void onUpdateTask(KanSoloTask task);     
     void onLoadTasks();

     void onUpdateBoard(const KanSoloBoard &board);
     void onEditBoard(const KanSoloBoard &board);
     void onCreateBoard(const KanSoloBoard &board);
     void onCreateBoard();     
     void onDeleteBoard(const KanSoloBoard &board);

     void onSelectBoard(int index);
     void onSelectTheme(int index);
     void onPopulateBoardList();

     void onClose();

};

}}}//end namespace

#endif // _CBTEK_PRODUCTS_SOLO_SCRUM_UISOLOAGILEBOARD_H
