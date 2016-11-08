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
#include "KanSoloTask.h"

#include "utility/inc/DateUtils.hpp"
#include "utility/inc/TimeUtils.hpp"
#include "utility/inc/StringUtils.hpp"
#include "utility/inc/SystemUtils.hpp"

using namespace cbtek::common::utility;

namespace cbtek {
namespace products {
namespace kan_solo {


KanSoloTask::KanSoloTask()
{
    m_createDate = 0;
    m_createTime = 0;
    m_cardSize = TaskCardSize::SMALL;
    m_priority = TaskPriority::LOW;
    m_state = TaskState::BACKLOG;
    m_score = -2;
    m_updateDate=0;
    m_closeDate=0;
    m_updateTime=0;
    m_closeTime=0;
    m_scaleX=0.;
    m_scaleY=0.;
}

void KanSoloTask::create()
{
    m_createDate=DateUtils::getCurrentDate().toDateInteger();
    m_createTime=TimeUtils::getCurrentTime().toTimeInteger();
    m_id = "TASK-"+StringUtils::createUUID(true);
    m_creator = SystemUtils::getUserName();
}

void KanSoloTask::update()
{
    m_updateDate=DateUtils::getCurrentDate().toDateInteger();
    m_updateTime=TimeUtils::getCurrentTime().toTimeInteger();

}

void KanSoloTask::close()
{
    m_closeDate=DateUtils::getCurrentDate().toDateInteger();
    m_closeTime=TimeUtils::getCurrentTime().toTimeInteger();
}

KanSoloTask::~KanSoloTask()
{

}

void KanSoloTask::setId(const std::string & value)
{
    m_id=value;
}

void KanSoloTask::setTitle(const std::string & value)
{
    m_title=value;
}

void KanSoloTask::setDescription(const std::string & value)
{
    m_description=value;
}

void KanSoloTask::setScore(int value)
{
    m_score=value;
}

void KanSoloTask::setState(TaskState value)
{
    m_state=value;
}

void KanSoloTask::setProjectId(const std::string & value)
{
    m_projectId=value;
}

void KanSoloTask::setBoardId(const std::string & value)
{
    m_boardId=value;
}

void KanSoloTask::setPriority(TaskPriority value)
{
    m_priority=value;
}

void KanSoloTask::setCreator(const std::string & value)
{
    m_creator=value;
}

void KanSoloTask::setAssignee(const std::string & value)
{
    m_assignee=value;
}

void KanSoloTask::setCreationTime(int value)
{
    m_createTime=value;
}

void KanSoloTask::setCreationDate(int value)
{
    m_createDate=value;
}

void KanSoloTask::setUpdateTime(int value)
{
    m_updateTime = value;
}

void KanSoloTask::setUpdateDate(int value)
{
    m_updateDate=value;
}

void KanSoloTask::setCloseTime(int value)
{
    m_closeTime=value;
}

void KanSoloTask::setCloseDate(int value)
{
    m_closeDate=value;
}

void KanSoloTask::setSprintId(const std::string & value)
{
    m_sprintId=value;
}


const std::string &KanSoloTask::getId() const
{
    return m_id;
}

const std::string &KanSoloTask::getTitle() const
{
    return m_title;
}

const std::string &KanSoloTask::getDescription() const
{
    return m_description;
}

int KanSoloTask::getScore() const
{
    return m_score;
}

TaskState KanSoloTask::getState() const
{
    return m_state;
}

const std::string &KanSoloTask::getProjectId() const
{
    return m_projectId;
}

const std::string &KanSoloTask::getBoardId() const
{
    return m_boardId;
}

TaskPriority KanSoloTask::getPriority() const
{
    return m_priority;
}

const std::string &KanSoloTask::getCreator() const
{
    return m_creator;
}

const std::string &KanSoloTask::getAssignee() const
{
    return m_assignee;
}

int KanSoloTask::getCreateDate() const
{
    return m_createDate;
}

int KanSoloTask::getUpdateDate() const
{
    return m_updateDate;
}

int KanSoloTask::getCloseDate() const
{
    return m_closeDate;
}

int KanSoloTask::getCreateTime() const
{
    return m_createTime;
}

int KanSoloTask::getUpdateTime() const
{
    return m_updateTime;
}

int KanSoloTask::getCloseTime() const
{
    return m_closeTime;
}

const std::string &KanSoloTask::getSprintId() const
{
    return m_sprintId;
}

void KanSoloTask::setCardSize(TaskCardSize size)
{
    m_cardSize=size;
}

TaskCardSize KanSoloTask::getCardSize() const
{
    return m_cardSize;
}

double KanSoloTask::getScaleX() const
{
    return m_scaleX;
}

double KanSoloTask::getScaleY() const
{
    return m_scaleY;
}

void KanSoloTask::setScaleX(double scaleX)
{
    m_scaleX=scaleX;
}

void KanSoloTask::setScaleY(double scaleY)
{
    m_scaleY=scaleY;
}


}}}//end namespace


