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
//#-------------------------------------------------
//#
//# File DataTypeFactory.h created by cberry on 01-25-2014 at 8:24:12
//# File DataTypeFactory.h updated by cberry on 09-23-2016 at 18:24:20
//#
//#-------------------------------------------------

#ifndef _CBTEK_COMMON_DATABASE_DATATYPEFACTORY_HPP_
#define _CBTEK_COMMON_DATABASE_DATATYPEFACTORY_HPP_


#include <cstdint>

#include "database/inc/DataType.hpp"

#include "utility/inc/DateEntity.h"
#include "utility/inc/TimeEntity.h"

namespace cbtek {
namespace common {
namespace database {

class DataTypeFactory
{

public:

    static std::string createString(DataTypePtr type);

    static double createFloat64(DataTypePtr type);

    static float createFloat32(DataTypePtr type);

    static std::uint8_t createUInt8(DataTypePtr type);

    static std::uint16_t createUInt16(DataTypePtr type);

    static std::uint32_t createUInt32(DataTypePtr type);

    static std::uint64_t createUInt64(DataTypePtr type);

    static std::int8_t createInt8(DataTypePtr type);

    static std::int16_t createInt16(DataTypePtr type);

    static std::int32_t createInt32(DataTypePtr type);

    static std::int64_t createInt64(DataTypePtr type);

    static common::utility::DateEntity createDate(DataTypePtr type);

    static common::utility::TimeEntity createTime(DataTypePtr type);

    static bool createBool(DataTypePtr type);

private:
	DataTypeFactory();
	DataTypeFactory(const DataTypeFactory &);
	DataTypeFactory& operator=(const DataTypeFactory &);

};
}}} //namespace
#endif //_CBTEK_COMMON_DATABASE_DATATYPEFACTORY_HPP_
