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
#include "KanSoloTheme.h"

#include "utility/inc/FileUtils.hpp"

using namespace cbtek::common::utility;

namespace cbtek {
namespace products {
namespace kan_solo {


KanSoloTheme::KanSoloTheme()
{

}

KanSoloTheme::~KanSoloTheme()
{

}

void KanSoloTheme::setBackgroundUrl(const std::string & value)
{
    m_backgroundUrl=value;
}

void KanSoloTheme::setNewTaskButtonUrl(const std::string & value)
{
    m_newTaskButtonUrl=value;
}

void KanSoloTheme::setNewBoardButtonUrl(const std::string & value)
{
    m_newBoardButtonUrl=value;
}

void KanSoloTheme::setExitButtonUrl(const std::string & value)
{
    m_exitButtonUrl=value;
}


const std::string &KanSoloTheme::getBackgroundUrl() const
{
    return m_backgroundUrl;
}

const std::string &KanSoloTheme::getNewTaskButtonUrl() const
{
    return m_newTaskButtonUrl;
}

const std::string &KanSoloTheme::getNewBoardButtonUrl() const
{
    return m_newBoardButtonUrl;
}

const std::string &KanSoloTheme::getExitButtonUrl() const
{
    return m_exitButtonUrl;
}

const std::string &KanSoloTheme::getLogoUrl() const
{
    return m_logoUrl;
}

void KanSoloTheme::setLogoUrl(const std::string &url)
{
    m_logoUrl=url;
}

void KanSoloTheme::setName(const std::string &name)
{
    m_name=name;
}

const std::string &KanSoloTheme::getName() const
{
    return m_name;
}

bool KanSoloTheme::isValid() const
{
    return  !m_backgroundUrl.empty() &&
            !m_newTaskButtonUrl.empty() &&
            !m_newBoardButtonUrl.empty() &&
            !m_exitButtonUrl.empty() &&
            FileUtils::fileExists(m_backgroundUrl) &&
            FileUtils::fileExists(m_newTaskButtonUrl) &&
            FileUtils::fileExists(m_newBoardButtonUrl) &&
            FileUtils::fileExists(m_exitButtonUrl) &&
            FileUtils::fileExists(m_logoUrl);
}


}}}//end namespace


