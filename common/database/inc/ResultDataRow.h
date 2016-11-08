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
#ifndef _CBTEK_COMMON_DATABASE_RESULTDATAROW_H_
#define _CBTEK_COMMON_DATABASE_RESULTDATAROW_H_
#include <vector>
#include <cstdint>


#include "DataType.hpp"
#include "utility/inc/DateEntity.h"
#include "utility/inc/TimeEntity.h"

#include "database/inc/types/Float32Type.h"
#include "database/inc/types/Float64Type.h"
#include "database/inc/types/Int64Type.h"
#include "database/inc/types/UInt64Type.h"
#include "database/inc/types/Int32Type.h"
#include "database/inc/types/UInt32Type.h"
#include "database/inc/types/Int16Type.h"
#include "database/inc/types/UInt16Type.h"
#include "database/inc/types/Int8Type.h"
#include "database/inc/types/UInt8Type.h"
#include "database/inc/types/BoolType.h"
#include "database/inc/types/NullType.h"
#include "database/inc/types/StringType.h"
#include "database/inc/types/DateType.h"
#include "database/inc/types/TimeType.h"

namespace cbtek {
namespace common {
namespace database {

class ResultDataRow : public std::vector<DataTypePtr>
{
public:
    ResultDataRow();            


    std::int64_t getInteger(const std::string & fieldName) const;

    std::string getText(const std::string & fieldName) const;

    double getNumeric(const std::string & fieldName) const;

    ResultDataRow & operator<<(const types::UInt64Type & value);

    ResultDataRow & operator<<(const types::UInt32Type & value);

    ResultDataRow & operator<<(const types::UInt16Type & value);

    ResultDataRow & operator<<(const types::UInt8Type & value);

    ResultDataRow & operator<<(const types::Int64Type & value);

    ResultDataRow & operator<<(const types::Int32Type & value);

    ResultDataRow & operator<<(const types::Int16Type & value);

    ResultDataRow & operator<<(const types::Int8Type & value);

    ResultDataRow & operator<<(const types::Float64Type & value);

    ResultDataRow & operator<<(const types::Float32Type & value);

    ResultDataRow & operator<<(const std::string & value);

    ResultDataRow & operator<<(const common::utility::DateEntity & value);

    ResultDataRow & operator<<(const common::utility::TimeEntity & value);

    ResultDataRow & operator<<(const types::NullType & value);

    ResultDataRow & operator<<(const bool & value);

    void setHeaders(const std::vector<std::string> & headers);

    void clear();

    ~ResultDataRow();
private:
    std::vector<std::string> m_headers;
};
}}}//namespace
#endif // CBTEK_COMMON_DATABASE_RESULTDATAROW_H_
