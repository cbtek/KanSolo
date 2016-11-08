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
#include "KanSoloSprint.h"

namespace cbtek {
namespace products {
namespace kan_solo {


KanSoloSprint::KanSoloSprint()
{

}

KanSoloSprint::~KanSoloSprint()
{

}

void KanSoloSprint::setId(const std::string & value)
{
    m_id=value;
}

void KanSoloSprint::setTitle(const std::string & value)
{
    m_title=value;
}

void KanSoloSprint::setStartDate(int value)
{
    m_startDate=value;
}

void KanSoloSprint::setEndDate(int value)
{
    m_endDate=value;
}

void KanSoloSprint::setBoardId(const std::string & value)
{
    m_boardId=value;
}


const std::string &KanSoloSprint::getId() const
{
    return m_id;
}

const std::string &KanSoloSprint::getTitle() const
{
    return m_title;
}

int KanSoloSprint::getStartDate() const
{
    return m_startDate;
}

int KanSoloSprint::getEndDate() const
{
    return m_endDate;
}

const std::string &KanSoloSprint::getBoardId() const
{
    return m_boardId;
}


}}}//end namespace


