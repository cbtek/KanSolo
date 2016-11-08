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

#ifndef _CBTEK_PRODUCTS_KAN_SOLO_KANSOLOBOARD_H
#define _CBTEK_PRODUCTS_KAN_SOLO_KANSOLOBOARD_H

#include <string>

namespace cbtek {
namespace products {
namespace kan_solo {


class KanSoloBoard 
{
public:
    /**
     * @brief Constructor for KanSoloBoard
     *  Detailed description for KanSoloBoard
     */

    KanSoloBoard();
    /**
    * @brief Setter for m_id
    * @param Value to replace m_id
    */
    void setId(const std::string & value);

    /**
    * @brief Setter for m_projectId
    * @param Value to replace m_projectId
    */
    void setProjectId(const std::string & value);

    /**
    * @brief Setter for m_title
    * @param Value to replace m_title
    */
    void setTitle(const std::string & value);

    /**
    * @brief Setter for m_backlogTitle
    * @param Value to replace m_backlogTitle
    */
    void setBacklogTitle(const std::string & value);

    /**
    * @brief Setter for m_processingTitle
    * @param Value to replace m_processingTitle
    */
    void setProcessingTitle(const std::string & value);

    /**
    * @brief Setter for m_testingTitle
    * @param Value to replace m_testingTitle
    */
    void setTestingTitle(const std::string & value);

    /**
    * @brief Setter for m_finishedTitle
    * @param Value to replace m_finishedTitle
    */
    void setFinishedTitle(const std::string & value);

    /**
    * @brief Setter for m_processingCount
    * @param Value to replace m_processingCount
    */
    void setProcessingCount(int value);

    /**
    * @brief Setter for m_testingCount
    * @param Value to replace m_testingCount
    */
    void setTestingCount(int value);

    /**
    * @brief Setter for m_boardDate
    * @param Value to replace m_boardDate
    */
    void setCreationDate(int value);

    /**
    * @brief Setter for m_boardTime
    * @param Value to replace m_boardTime
    */
    void setCreationTime(int value);


    /**
    * @brief Getter for m_id
    * @return Return copy of m_id
    */
    const std::string & getId() const;

    /**
    * @brief Getter for m_projectId
    * @return Return copy of m_projectId
    */
    const std::string & getProjectId() const;

    /**
    * @brief Getter for m_title
    * @return Return copy of m_title
    */
    const std::string & getTitle() const;

    /**
    * @brief Getter for m_backlogTitle
    * @return Return copy of m_backlogTitle
    */
    const std::string & getBacklogTitle() const;

    /**
    * @brief Getter for m_processingTitle
    * @return Return copy of m_processingTitle
    */
    const std::string & getProcessingTitle() const;

    /**
    * @brief Getter for m_testingTitle
    * @return Return copy of m_testingTitle
    */
    const std::string & getTestingTitle() const;

    /**
    * @brief Getter for m_finishedTitle
    * @return Return copy of m_finishedTitle
    */
    const std::string & getFinishedTitle() const;

    /**
    * @brief Getter for m_processingCount
    * @return Return copy of m_processingCount
    */
    int getProcessingCount() const;

    /**
    * @brief Getter for m_testingCount
    * @return Return copy of m_testingCount
    */
    int getTestingCount() const;

    /**
    * @brief Getter for m_boardDate
    * @return Return copy of m_boardDate
    */
    int getCreationDate() const;

    /**
    * @brief Getter for m_boardTime
    * @return Return copy of m_boardTime
    */
    int getCreationTime() const;



    //! Destructor
    ~KanSoloBoard();	
private:
    std::string m_id;
    std::string m_projectId;
    std::string m_title;
    std::string m_backlogTitle;
    std::string m_processingTitle;
    std::string m_testingTitle;
    std::string m_finishedTitle;
    int m_processingCount;
    int m_testingCount;
    int m_boardDate;
    int m_boardTime;

};
}}}//end namespace

#endif // _CBTEK_PRODUCTS_KAN_SOLO_KANSOLOBOARD_H

