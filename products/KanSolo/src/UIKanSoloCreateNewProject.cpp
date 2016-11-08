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
#include "UIKanSoloCreateNewProject.h"
#include "ui_UIKanSoloCreateNewProject.h"
#include <QMessageBox>

namespace cbtek {
namespace products {
namespace kan_solo {


UIKanSoloCreateNewProject::UIKanSoloCreateNewProject(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui_UIKanSoloCreateNewProject)
{
    m_ui->setupUi(this);
    connect(m_ui->m_btnCancel,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(m_ui->m_btnSave,SIGNAL(clicked(bool)),this,SLOT(onSave()));
}

UIKanSoloCreateNewProject::~UIKanSoloCreateNewProject()
{
    delete m_ui;
}

void UIKanSoloCreateNewProject::onSave()
{
    if (m_ui->m_txtProjectName->text().trimmed().isEmpty())
    {
        QMessageBox::information(this,"Empty Name?","Please input a valid project name!");
        m_ui->m_txtProjectName->setFocus();
        return;
    }
    emit this->createProject(m_ui->m_txtProjectName->text());
}

}}}//end namespace

