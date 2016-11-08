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
#ifndef SQLITECONNECTION_H
#define SQLITECONNECTION_H

#include "DatabaseConnection.hpp"
#include "SQLiteQueryResult.h"


#include "contrib/sqlite/sqlite3.h"


namespace cbtek {
namespace common {
namespace database {
namespace connections {

class SQLiteConnection : public DatabaseConnection
{
public:    
    SQLiteConnection();

    SQLiteConnection(const std::string &connectionURL,
                     const std::string & userName="",
                     const std::string & password="");

    bool connect(const std::string &connectionURL,
                 const std::string & userName="",
                 const std::string & password="");

    void disconnect();

    QueryResultPtr query(const std::string & query, const std::uint64_t &ndx);

    QueryResultPtr query(const std::string & query);

    void getQueryEnclosureFormatStrings(QueryEnclosureFormatType type,
                                        std::string & beginOut,
                                        std::string & endOut);

private:


    results::SQLiteQueryResult m_result;

    void checkErrorCode(const int & errorCode);

    std::string m_username,m_password;

    sqlite3 *m_database;
    std::string m_currentQuery;
    std::string m_currentConnectionString;

};
}}}}//namespace
#endif // SQLITECONNECTION_H
