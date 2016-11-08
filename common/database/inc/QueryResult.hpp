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
#ifndef _CBTEK_COMMON_DATABASE_HPP_QUERYRESULT_HPP_
#define _CBTEK_COMMON_DATABASE_HPP_QUERYRESULT_HPP_

#include <iostream>

#include "ResultDataRow.h"
#include "utility/inc/StringUtils.hpp"

namespace cbtek {
namespace common {
namespace database {

namespace queryTypes{
enum QueryType{
    INSERT
    ,SQLDELETE
    ,SELECT
    ,UPDATE
    ,EXPLAIN
    ,TRUNCATE
    ,CREATE
    ,ALTER
    ,DROP
    ,GRANT
    ,REVOKE
    ,COMMIT
    ,ROLLBACK
    ,SAVEPOINT
    ,SET
    ,CONSTRAINT
    ,UNKNOWN
};


    static inline QueryType getQueryTypeFromString(const std::string & query)
    {
        std::string queryStr = common::utility::StringUtils::toUpperTrimmed(query);
        if (common::utility::StringUtils::startsWith(queryStr,"DELETE"))
        {
            return SQLDELETE;
        }
        else if (common::utility::StringUtils::startsWith(queryStr,"INSERT"))
        {
            return INSERT;
        }
        else if (common::utility::StringUtils::startsWith(queryStr,"SELECT"))
        {
            return SELECT;
        }
        else if (common::utility::StringUtils::startsWith(queryStr,"UPDATE"))
        {
            return UPDATE;
        }
        else if (common::utility::StringUtils::startsWith(queryStr,"EXPLAIN"))
        {
            return  EXPLAIN;
        }
        else if (common::utility::StringUtils::startsWith(queryStr,"TRUNCATE"))
        {
            return TRUNCATE;
        }
        else if (common::utility::StringUtils::startsWith(queryStr,"CREATE"))
        {
            return CREATE;
        }
        else if (common::utility::StringUtils::startsWith(queryStr,"ALTER"))
        {
            return ALTER;
        }
        else if (common::utility::StringUtils::startsWith(queryStr,"DROP"))
        {
            return DROP;
        }
        else if (common::utility::StringUtils::startsWith(queryStr,"GRANT"))
        {
            return GRANT;
        }
        else if (common::utility::StringUtils::startsWith(queryStr,"REVOKE"))
        {
            return REVOKE;
        }
        else if (common::utility::StringUtils::startsWith(queryStr,"COMMIT"))
        {
            return COMMIT;
        }
        else if (common::utility::StringUtils::startsWith(queryStr,"ROLLBACK"))
        {
            return ROLLBACK;
        }
        else if (common::utility::StringUtils::startsWith(queryStr,"SAVEPOINT"))
        {
            return SAVEPOINT;
        }
        else if (common::utility::StringUtils::startsWith(queryStr,"SET"))
        {
            return SET;
        }
        else if (common::utility::StringUtils::startsWith(queryStr,"CONSTRAINT"))
        {
            return CONSTRAINT;
        }

        return queryTypes::UNKNOWN;
    }
}
typedef std::vector<ResultDataRow> ResultDataTable;
class QueryResult
{
public:       

    virtual queryTypes::QueryType getQueryType() const =0;

    virtual bool isValid() const =0;

    virtual size_t getNumResultRows() const =0;

    virtual ResultDataRow getResultRow(const size_t & ndx) const=0;

    virtual std::vector<std::string> getResultHeaders() const=0;
};

typedef std::shared_ptr<QueryResult> QueryResultPtr;

}}}//namespace

#endif // _CBTEK_COMMON_DATABASE_HPP_QUERYRESULT_HPP_
