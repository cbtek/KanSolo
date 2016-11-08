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

#ifndef _CBTEK_PRODUCTS_RAGE_UIKANSOLOCREATENEWBOARD_H
#define _CBTEK_PRODUCTS_RAGE_UIKANSOLOCREATENEWBOARD_H

#include <QDialog>

#include "KanSoloBoard.h"

class Ui_UIKanSoloCreateNewBoard;

namespace cbtek {
namespace products {
namespace kan_solo {


class UIKanSoloCreateNewBoard : public QDialog
{
    Q_OBJECT

public:
    //! Constructor for UIKanSoloCreateNewBoard
	/*!
        Detailed description for UIKanSoloCreateNewBoard
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIKanSoloCreateNewBoard(QWidget *parent = 0);
    

    explicit UIKanSoloCreateNewBoard(const KanSoloBoard & board,
                                     QWidget *parent = 0);
    
    //! Descructor for UIKanSoloCreateNewBoard
    ~UIKanSoloCreateNewBoard();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIKanSoloCreateNewBoard *m_ui;     

     bool m_isUpdate;
     KanSoloBoard m_board;
private slots:
    void onSave();

signals:
     void boardCreated(const KanSoloBoard &board);
     void boardUpdated(const KanSoloBoard &board);
    
};

}}}//end namespace

#endif // _CBTEK_PRODUCTS_RAGE_UINEWBOARD_H
