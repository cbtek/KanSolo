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

#ifndef _CBTEK_PRODUCTS_KAN_SOLO_KANSOLOTHEME_H
#define _CBTEK_PRODUCTS_KAN_SOLO_KANSOLOTHEME_H

#include <string>

namespace cbtek {
namespace products {
namespace kan_solo {


class KanSoloTheme 
{
public:
    /**
     * @brief Constructor for KanSoloTheme
     *  Detailed description for KanSoloTheme
     */

    KanSoloTheme();
    /**
    * @brief Setter for m_backgroundUrl
    * @param Value to replace m_backgroundUrl
    */
    void setBackgroundUrl(const std::string & value);

    /**
    * @brief Setter for m_newTaskButtonUrl
    * @param Value to replace m_newTaskButtonUrl
    */
    void setNewTaskButtonUrl(const std::string & value);

    /**
    * @brief Setter for m_newBoardButtonUrl
    * @param Value to replace m_newBoardButtonUrl
    */
    void setNewBoardButtonUrl(const std::string & value);

    /**
    * @brief Setter for m_exitButtonUrl
    * @param Value to replace m_exitButtonUrl
    */
    void setExitButtonUrl(const std::string & value);


    /**
    * @brief Getter for m_backgroundUrl
    * @return Return copy of m_backgroundUrl
    */
    const std::string & getBackgroundUrl() const;

    /**
    * @brief Getter for m_newTaskButtonUrl
    * @return Return copy of m_newTaskButtonUrl
    */
    const std::string & getNewTaskButtonUrl() const;

    /**
    * @brief Getter for m_newBoardButtonUrl
    * @return Return copy of m_newBoardButtonUrl
    */
    const std::string & getNewBoardButtonUrl() const;

    /**
    * @brief Getter for m_exitButtonUrl
    * @return Return copy of m_exitButtonUrl
    */
    const std::string & getExitButtonUrl() const;

    const std::string & getLogoUrl() const;

    void setLogoUrl(const std::string & url);

    void setName(const std::string & name);

    const std::string & getName() const;

    bool isValid() const;

    //! Destructor
    ~KanSoloTheme();	
private:
    std::string m_name;
    std::string m_backgroundUrl;
    std::string m_newTaskButtonUrl;
    std::string m_newBoardButtonUrl;
    std::string m_exitButtonUrl;
    std::string m_logoUrl;

};
}}}//end namespace

#endif // _CBTEK_PRODUCTS_KAN_SOLO_KANSOLOTHEME_H

