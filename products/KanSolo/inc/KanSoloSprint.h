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

#ifndef _CBTEK_PRODUCTS_KAN_SOLO_KANSOLOSPRINT_H
#define _CBTEK_PRODUCTS_KAN_SOLO_KANSOLOSPRINT_H

#include <string>

namespace cbtek {
namespace products {
namespace kan_solo {


class KanSoloSprint 
{
public:
    /**
     * @brief Constructor for KanSoloSprint
     *  Detailed description for KanSoloSprint
     */

    KanSoloSprint();
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
    * @brief Setter for m_startDate
    * @param Value to replace m_startDate
    */
    void setStartDate(int value);

    /**
    * @brief Setter for m_endDate
    * @param Value to replace m_endDate
    */
    void setEndDate(int value);

    /**
    * @brief Setter for m_boardId
    * @param Value to replace m_boardId
    */
    void setBoardId(const std::string & value);


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
    * @brief Getter for m_startDate
    * @return Return copy of m_startDate
    */
    int getStartDate() const;

    /**
    * @brief Getter for m_endDate
    * @return Return copy of m_endDate
    */
    int getEndDate() const;

    /**
    * @brief Getter for m_boardId
    * @return Return copy of m_boardId
    */
    const std::string & getBoardId() const;



    //! Destructor
    ~KanSoloSprint();	
private:
    std::string m_id;
    std::string m_title;
    int m_startDate;
    int m_endDate;
    std::string m_boardId;

};
}}}//end namespace

#endif // _CBTEK_PRODUCTS_KAN_SOLO_KANSOLOSPRINT_H

