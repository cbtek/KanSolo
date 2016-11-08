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

#ifndef _CBTEK_PRODUCTS_KAN_SOLO_UIKANSOLOCREATENEWSPRINT_H
#define _CBTEK_PRODUCTS_KAN_SOLO_UIKANSOLOCREATENEWSPRINT_H
#include <QDialog>

class Ui_UIKanSoloCreateNewSprint;

namespace cbtek {
namespace products {
namespace kan_solo {


class UIKanSoloCreateNewSprint : public QDialog
{
    Q_OBJECT

public:
	//! Constructor for UIKanSoloCreateNewSprint
	/*!
		Detailed description for UIKanSoloCreateNewSprint
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIKanSoloCreateNewSprint(const QString & project,
                                      QWidget *parent = 0);
    
    
	//! Descructor for UIKanSoloCreateNewSprint
    ~UIKanSoloCreateNewSprint();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIKanSoloCreateNewSprint *m_ui;

     QString m_project;
    
};

}}}//end namespace

#endif // _CBTEK_PRODUCTS_KAN_SOLO_UIKANSOLOCREATENEWSPRINT_H
