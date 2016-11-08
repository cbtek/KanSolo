///
/// CBTek LLC ("COMPANY") CONFIDENTIAL
/// Copyright (c) 2016 CBTek, All Rights Reserved.
///
/// NOTICE:  All information contained herein is, and remains the property of COMPANY. The intellectual and technical concepts contained
/// herein are proprietary to COMPANY and may be covered by U.S. and Foreign Patents, patents in process, and are protected by trade secret or copyright law.
/// Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
/// from COMPANY.  Access to the source code contained herein is hereby forbidden to anyone except current COMPANY employees, managers or contractors who have executed
/// Confidentiality and Non-disclosure agreements explicitly covering such access.
///
/// The copyright notice above does not evidence any actual or intended publication or disclosure  of  this source code, which includes
/// information that is confidential and/or proprietary, and is a trade secret, of  COMPANY.   ANY REPRODUCTION, MODIFICATION, DISTRIBUTION, PUBLIC  PERFORMANCE,
/// OR PUBLIC DISPLAY OF OR THROUGH USE  OF THIS  SOURCE CODE  WITHOUT  THE EXPRESS WRITTEN CONSENT OF COMPANY IS STRICTLY PROHIBITED, AND IN VIOLATION OF APPLICABLE
/// LAWS AND INTERNATIONAL TREATIES.  THE RECEIPT OR POSSESSION OF  THIS SOURCE CODE AND/OR RELATED INFORMATION DOES NOT CONVEY OR IMPLY ANY RIGHTS
/// TO REPRODUCE, DISCLOSE OR DISTRIBUTE ITS CONTENTS, OR TO MANUFACTURE, USE, OR SELL ANYTHING THAT IT  MAY DESCRIBE, IN WHOLE OR IN PART.
///

#ifndef _CBTEK_COMMON_UTILITY_STRINGBUILDER_H
#define _CBTEK_COMMON_UTILITY_STRINGBUILDER_H

#include "UtilityCommon.hpp"

#include <string>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <sstream>

namespace cbtek {
namespace common {
namespace utility {

class CBTEK_UTILS_DLL StringBuilder
{
    public:
    //! Constructor for StringBuilder
    /*!
        Detailed description for StringBuilder
    */
    StringBuilder(size_t floatingPointPrecision = c_DEFAULT_FLOATING_PRECISION);


    /**
     * @brief StringBuilder
     * @param values
     * @param floatingPointPrecision
     */
    StringBuilder(const std::vector<std::string> & values,
                  size_t floatingPointPrecision = c_DEFAULT_FLOATING_PRECISION);

    /**
     * @brief StringBuilder
     * @param values
     * @param floatingPointPrecision
     */
    StringBuilder(const std::list<std::string> & values,
                  size_t floatingPointPrecision = c_DEFAULT_FLOATING_PRECISION);


    /**
     * @brief StringBuilder
     * @param values
     * @param floatingPointPrecision
     */
    StringBuilder(const std::set<std::string> & values,
                  size_t floatingPointPrecision = c_DEFAULT_FLOATING_PRECISION);

    /**
     * @brief StringBuilder
     * @param values
     * @param floatingPointPrecision
     */
    StringBuilder(const std::deque<std::string> & values,
                  size_t floatingPointPrecision = c_DEFAULT_FLOATING_PRECISION);

    /**
     * @brief StringBuilder
     * @param values
     * @param floatingPointPrecision
     */
    StringBuilder(const std::stack<std::string> & values,
                  size_t floatingPointPrecision = c_DEFAULT_FLOATING_PRECISION);

    /**
     * @brief StringBuilder
     * @param values
     * @param floatingPointPrecision
     */
    StringBuilder(const std::queue<std::string> & values,
                  size_t floatingPointPrecision = c_DEFAULT_FLOATING_PRECISION);



    /**
     * @brief operator <<
     * @param value
     * @return
     */
    template <typename T>
    StringBuilder & operator <<(const T & value);

    /**
     * @brief operator <<
     * @param value
     * @return
     */
    StringBuilder & operator <<(double value);

    /**
     * @brief size
     * @return
     */
    size_t size() const;

    /**
     * @brief toList
     * @return
     */
    std::list<std::string> toList() const;

    /**
     * @brief toSet
     * @return
     */
    std::set<std::string> toSet() const;

    /**
     * @brief toVector
     * @return
     */
    std::vector<std::string> toVector() const;

    /**
     * @brief toDeque
     * @return
     */
    std::deque<std::string> toDeque() const;

    /**
     * @brief toStack
     * @return
     */
    std::stack<std::string> toStack() const;


    /**
     * @brief toQueue
     * @return
     */
    std::queue<std::string> toQueue() const;

    /**
     * @brief toList
     * @param listOut
     */
    void toList(std::list<std::string> & listOut) const;

    /**
     * @brief toVector
     * @param vecOut
     */
    void toVector(std::vector<std::string> &vecOut) const;

    /**
     * @brief toSet
     * @param setOut
     */
    void toSet(std::set<std::string> & setOut) const;

    /**
     * @brief toDeque
     * @param deqOut
     */
    void toDeque(std::deque<std::string> & deqOut) const;

    /**
     * @brief toQueue
     * @param queOut
     */
    void toQueue(std::queue<std::string> & queOut) const;

    /**
     * @brief toStack
     * @param stackOut
     */
    void toStack(std::stack<std::string> & stackOut) const;

    /**
     * @brief clear
     */
    void clear();


    /**
     * @brief toString
     * @param seperator
     * @return
     */
    std::string toString(const std::string & seperator="") const;

    /**
     * @brief toString
     * @param prefixString
     * @param postFixString
     * @param seperator
     * @return
     */
    std::string toString(const std::string & prefixString,
                         const std::string & postFixString,
                         const std::string &seperator="") const;
    //! Destructor
    ~StringBuilder();    

private:
    size_t m_floatingPointPrecision;   
    std::list<std::string> m_stringItems;
};

template <typename T>
StringBuilder & StringBuilder::operator << (const T & value)
{
    std::ostringstream out;
    out << value;
    m_stringItems.push_back(out.str());
    return (*this);
}
}}}//end namespace

#endif // _CBTEK_COMMON_UTILITY_STRINGBUILDER_H

