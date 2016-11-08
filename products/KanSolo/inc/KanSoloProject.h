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
#ifndef _CBTEK_PRODUCTS_KAN_SOLO_KANSOLOPROJECT_H
#define _CBTEK_PRODUCTS_KAN_SOLO_KANSOLOPROJECT_H

#include <string>

namespace cbtek {
namespace products {
namespace kan_solo {


class KanSoloProject 
{
public:
    /**
     * @brief Constructor for KanSoloProject
     *  Detailed description for KanSoloProject
     */

    KanSoloProject();
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


    void setCreationDate(int value);

    void setCreationTime(int value);

    int getCreationDate() const;

    int getCreationTime() const;

    //! Destructor
    ~KanSoloProject();	
private:
    int m_creationDate;
    int m_creationTime;
    std::string m_id;
    std::string m_title;
    std::string m_description;

};
}}}//end namespace

#endif // _CBTEK_PRODUCTS_KAN_SOLO_KANSOLOPROJECT_H

