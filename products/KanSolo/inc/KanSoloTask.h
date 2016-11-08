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

#ifndef _CBTEK_PRODUCTS_KAN_SOLO_KANSOLOTASK_H
#define _CBTEK_PRODUCTS_KAN_SOLO_KANSOLOTASK_H

#include <string>

namespace cbtek {
namespace products {
namespace kan_solo {

enum class TaskCardSize
{
    SMALL,
    MEDIUM,
    LARGE
};

enum class TaskState
{    
    BACKLOG,
    PROCESSING,
    TESTING,
    FINISHED
};

enum class TaskPriority
{
    LOW,
    NORMAL,
    HIGH
};

class KanSoloTask 
{
public:
    /**
     * @brief Constructor for KanSoloTask
     *  Detailed description for KanSoloTask
     */

    KanSoloTask();

    void create();

    void update();

    void close();
    /**
    * @brief Setter for m_id
    * @param Value to replace m_id
    */
    void setId(const std::string & value);

    /**
    * @brief Setter for m_title
    * @param Value to replace m_title
    */
    void setTitle(const std::string & value);

    /**
    * @brief Setter for m_description
    * @param Value to replace m_description
    */
    void setDescription(const std::string & value);

    /**
    * @brief Setter for m_score
    * @param Value to replace m_score
    */
    void setScore(int value);

    /**
    * @brief Setter for m_state
    * @param Value to replace m_state
    */
    void setState(TaskState value);

    /**
    * @brief Setter for m_projectId
    * @param Value to replace m_projectId
    */
    void setProjectId(const std::string & value);

    /**
    * @brief Setter for m_boardId
    * @param Value to replace m_boardId
    */
    void setBoardId(const std::string & value);

    /**
    * @brief Setter for m_priority
    * @param Value to replace m_priority
    */
    void setPriority(TaskPriority value);

    /**
    * @brief Setter for m_creator
    * @param Value to replace m_creator
    */
    void setCreator(const std::string & value);

    /**
    * @brief Setter for m_assignee
    * @param Value to replace m_assignee
    */
    void setAssignee(const std::string & value);

    /**
    * @brief Setter for m_createTime
    * @param Value to replace m_createTime
    */
    void setCreationTime(int value);

    /**
    * @brief Setter for m_createDate
    * @param Value to replace m_createDate
    */
    void setCreationDate(int value);

    /**
    * @brief Setter for m_updateTime
    * @param Value to replace m_updateTime
    */
    void setUpdateTime(int value);


    /**
    * @brief Setter for m_updateDate
    * @param Value to replace m_updateDate
    */
    void setUpdateDate(int value);

    /**
    * @brief Setter for m_closeDate
    * @param Value to replace m_closeDate
    */
    void setCloseDate(int value);

    /**
    * @brief Setter for m_sprintId
    * @param Value to replace m_sprintId
    */
    void setSprintId(const std::string & value);


    /**
    * @brief Getter for m_id
    * @return Return copy of m_id
    */
    const std::string & getId() const;

    /**
    * @brief Getter for m_title
    * @return Return copy of m_title
    */
    const std::string & getTitle() const;

    /**
    * @brief Getter for m_description
    * @return Return copy of m_description
    */
    const std::string & getDescription() const;

    /**
    * @brief Getter for m_score
    * @return Return copy of m_score
    */
    int getScore() const;

    /**
    * @brief Getter for m_state
    * @return Return copy of m_state
    */
    TaskState getState() const;

    /**
    * @brief Getter for m_projectId
    * @return Return copy of m_projectId
    */
    const std::string & getProjectId() const;

    /**
    * @brief Getter for m_boardId
    * @return Return copy of m_boardId
    */
    const std::string & getBoardId() const;

    /**
    * @brief Getter for m_priority
    * @return Return copy of m_priority
    */
    TaskPriority getPriority() const;

    /**
    * @brief Getter for m_creator
    * @return Return copy of m_creator
    */
    const std::string & getCreator() const;

    /**
    * @brief Getter for m_assignee
    * @return Return copy of m_assignee
    */
    const std::string & getAssignee() const;

    /**
    * @brief Getter for m_createDate
    * @return Return copy of m_createDate
    */
    int getCreateDate() const;

    /**
    * @brief Getter for m_updateDate
    * @return Return copy of m_updateDate
    */
    int getUpdateDate() const;

    /**
    * @brief Getter for m_closeDate
    * @return Return copy of m_closeDate
    */
    int getCloseDate() const;


    /**
    * @brief Getter for m_createTime
    * @return Return copy of m_createTime
    */
    int getCreateTime() const;

    /**
    * @brief Getter for m_updateTime
    * @return Return copy of m_updateTime
    */
    int getUpdateTime() const;

    /**
    * @brief Getter for m_closeTime
    * @return Return copy of m_closeTime
    */
    int getCloseTime() const;

    void setCloseTime(int value);

    /**
    * @brief Getter for m_sprintId
    * @return Return copy of m_sprintId
    */
    const std::string & getSprintId() const;


    void setCardSize(TaskCardSize size);

    TaskCardSize getCardSize() const;

    double getScaleX() const;

    double getScaleY() const;

    void setScaleX(double scaleX);

    void setScaleY(double scaleY);

    //! Destructor
    ~KanSoloTask();	

private:
    std::string m_id;
    std::string m_title;
    std::string m_description;
    int m_score;
    TaskState m_state;
    std::string m_projectId;
    std::string m_boardId;
    TaskPriority m_priority;
    std::string m_creator;
    std::string m_assignee;
    int m_createDate;
    int m_updateDate;
    int m_closeDate;
    int m_createTime;
    int m_updateTime;
    int m_closeTime;
    TaskCardSize m_cardSize;
    double m_scaleX;
    double m_scaleY;
    std::string m_sprintId;

};
}}}//end namespace

#endif // _CBTEK_PRODUCTS_KAN_SOLO_KANSOLOTASK_H

