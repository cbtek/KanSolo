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

#include "KanSoloBoard.h"

#include "utility/inc/DateUtils.hpp"
#include "utility/inc/TimeUtils.hpp"

using namespace cbtek::common::utility;

namespace cbtek {
namespace products {
namespace kan_solo {


KanSoloBoard::KanSoloBoard()
{
    m_processingCount=0;
    m_testingCount=0;
    m_boardDate =DateUtils::getCurrentDate().toDateInteger();
    m_boardTime =TimeUtils::getCurrentTime().toTimeInteger();
}

KanSoloBoard::~KanSoloBoard()
{

}

void KanSoloBoard::setId(const std::string & value)
{
    m_id=value;
}

void KanSoloBoard::setProjectId(const std::string & value)
{
    m_projectId=value;
}

void KanSoloBoard::setTitle(const std::string & value)
{
    m_title=value;
}

void KanSoloBoard::setBacklogTitle(const std::string & value)
{
    m_backlogTitle=value;
}

void KanSoloBoard::setProcessingTitle(const std::string & value)
{
    m_processingTitle=value;
}

void KanSoloBoard::setTestingTitle(const std::string & value)
{
    m_testingTitle=value;
}

void KanSoloBoard::setFinishedTitle(const std::string & value)
{
    m_finishedTitle=value;
}

void KanSoloBoard::setProcessingCount(int value)
{
    m_processingCount=value;
}

void KanSoloBoard::setTestingCount(int value)
{
    m_testingCount=value;
}

void KanSoloBoard::setCreationDate(int value)
{
    m_boardDate=value;
}

void KanSoloBoard::setCreationTime(int value)
{
    m_boardTime=value;
}


const std::string &KanSoloBoard::getId() const
{
    return m_id;
}

const std::string &KanSoloBoard::getProjectId() const
{
    return m_projectId;
}

const std::string &KanSoloBoard::getTitle() const
{
    return m_title;
}

const std::string &KanSoloBoard::getBacklogTitle() const
{
    return m_backlogTitle;
}

const std::string &KanSoloBoard::getProcessingTitle() const
{
    return m_processingTitle;
}

const std::string &KanSoloBoard::getTestingTitle() const
{
    return m_testingTitle;
}

const std::string &KanSoloBoard::getFinishedTitle() const
{
    return m_finishedTitle;
}

int KanSoloBoard::getProcessingCount() const
{
    return m_processingCount;
}

int KanSoloBoard::getTestingCount() const
{
    return m_testingCount;
}

int KanSoloBoard::getCreationDate() const
{
    return m_boardDate;
}

int KanSoloBoard::getCreationTime() const
{
    return m_boardTime;
}


}}}//end namespace


