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

#ifndef _CBTEK_PRODUCTS_SOLO_SCRUM_UISOLOAGILETASK_H
#define _CBTEK_PRODUCTS_SOLO_SCRUM_UISOLOAGILETASK_H

#include <QDialog>
#include <QTableWidgetItem>

#include "KanSoloTask.h"
class Ui_UIKanSoloCreateNewTask;
class QLabel;

namespace cbtek {
namespace products {
namespace kan_solo {


class UIKanSoloCreateNewTask : public QDialog
{
    Q_OBJECT

public:
    //! Constructor for UIKanSoloCreateNewTask
	/*!
        Detailed description for UIKanSoloCreateNewTask
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIKanSoloCreateNewTask(QWidget *parent = 0);

    explicit UIKanSoloCreateNewTask(const KanSoloTask & task,
                             QWidget *parent = 0);

    
    KanSoloTask onEditTaskExec() const;

    //! Descructor for UIKanSoloCreateNewTask
    ~UIKanSoloCreateNewTask();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIKanSoloCreateNewTask *m_ui;
     KanSoloTask m_task;
     TaskPriority getPriority() const;
     int getScore() const;
     void setPriority(TaskPriority priority);
     void setScore(int score);
     TaskCardSize getCardSize() const;
     void setCardSize(TaskCardSize size);
    QString m_boardId;
    void setupScoreList();
    void setupPriorityList();
    void setupSizeList();
    QMap<int,QLabel *> m_scoreItemMap;
    QMap<TaskPriority,QLabel*>m_priorityItemMap;
    QMap<TaskCardSize,QLabel*>m_sizeItemMap;

private slots:
     void onSave();
     void onSaveNew();
     void onSaveExisting();
     void onCancel();
signals:
     void taskUpdated(KanSoloTask task);
     void taskCreated(KanSoloTask task);
    
};

}}}//end namespace

#endif // _CBTEK_PRODUCTS_SOLO_SCRUM_UISOLOAGILETASK_H
