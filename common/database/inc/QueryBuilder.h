/*
    QueryBuilder.h

    
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

*/

#ifndef _CBTEK_COMMON_DATABASE_QUERYBUILDER_H
#define _CBTEK_COMMON_DATABASE_QUERYBUILDER_H

#include <vector>
#include <string>

#include "DataType.hpp"

#include "utility/inc/StringBuilder.h"
#include <map>

namespace cbtek {
namespace common {
namespace database {

enum class Mode
{

    INSERT,
    SELECT,
    UPDATE,
    CREATE_TABLE,
    SQLDELETE
};

enum DatabaseId
{
    GENERIC,
    SQLITE,
    MYSQL_MARIADB,
    POSTGRE,
    MS_SQLSERVER
};

class QueryBuilder 
{
public:
    /**
     * @brief Constructor for QueryBuilder
     *  Detailed description for QueryBuilder
     */
    QueryBuilder();

    /**
     * @brief operator []
     * @param key
     * @return
     */
    std::string & operator[](const std::string & key);

    /**
     * @brief operator []
     * @param key
     * @return
     */
    const std::string & operator[](const std::string & key) const;

    /**
     * @brief buildQuery
     * @param rawQuery
     * @param caseSensitive
     * @return
     */
    std::string buildQuery(const std::string & rawQuery,
                           bool caseSensitive=true) const;

    void clean(const std::string & strToRemove);

    /**
     * @brief clear
     */
    void clear();

    //! Destructor
    ~QueryBuilder();	
private:

    std::string m_tableName;
    std::map<std::string, std::string> m_strMap;
};
}}}//end namespace

#endif // _CBTEK_COMMON_DATABASE_QUERYBUILDER_H

