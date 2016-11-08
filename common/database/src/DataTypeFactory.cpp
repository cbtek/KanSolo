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
//# File DataTypeFactory.cpp created by shadowefusion on 01-25-2014 at 8:24:12
//#
//#-------------------------------------------------

#include "DataTypeFactory.h"
#include "Float32Type.h"
#include "Float64Type.h"
#include "Int64Type.h"
#include "UInt64Type.h"
#include "Int32Type.h"
#include "UInt32Type.h"
#include "Int16Type.h"
#include "UInt16Type.h"
#include "Int8Type.h"
#include "UInt8Type.h"

#include "BoolType.h"
#include "NullType.h"
#include "StringType.h"
#include "DateType.h"
#include "TimeType.h"

namespace cbtek {
namespace common {
namespace database {

std::string DataTypeFactory::createString(DataTypePtr type)
{
    typedef types::StringType ConversionType;
    if (type->getType()==Type::STRING)
    {
        ConversionType * value=dynamic_cast<ConversionType*>(type.get());
        if (value)
        {
            return value->getValue();
        }
    }
    return "";
}

double DataTypeFactory::createFloat64(DataTypePtr type)
{
    typedef types::Float64Type ConversionType;
    if (type->getType()==Type::FLOAT64)
    {
        ConversionType * value=dynamic_cast<ConversionType*>(type.get());
        if (value)
        {
            return value->getValue();
        }
    }
    return 0.;
}

float DataTypeFactory::createFloat32(DataTypePtr type)
{
    typedef types::Float32Type ConversionType;
    if (type->getType()==Type::FLOAT32)
    {
        ConversionType * value=dynamic_cast<ConversionType*>(type.get());
        if (value)
        {
            return value->getValue();
        }
    }
    return 0.;
}

std::uint8_t DataTypeFactory::createUInt8(DataTypePtr type)
{
    typedef types::UInt8Type ConversionType;
    if (type->getType()==Type::UINT8)
    {
        ConversionType * value=dynamic_cast<ConversionType*>(type.get());
        if (value)
        {
            return value->getValue();
        }
    }
    return 0;
}

std::uint16_t DataTypeFactory::createUInt16(DataTypePtr type)
{
    typedef types::UInt16Type ConversionType;
    if (type->getType()==Type::UINT16)
    {
        ConversionType * value=dynamic_cast<ConversionType*>(type.get());
        if (value)
        {
            return value->getValue();
        }
    }
    return 0;
}

std::uint32_t DataTypeFactory::createUInt32(DataTypePtr type)
{
    typedef types::UInt32Type ConversionType;
    if (type->getType()==Type::UINT32)
    {
        ConversionType * value=dynamic_cast<ConversionType*>(type.get());
        if (value)
        {
            return value->getValue();
        }
    }
    return 0;
}

std::uint64_t DataTypeFactory::createUInt64(DataTypePtr type)
{
    typedef types::UInt64Type ConversionType;
    if (type->getType()==Type::UINT64)
    {
        ConversionType * value=dynamic_cast<ConversionType*>(type.get());
        if (value)
        {
            return value->getValue();
        }
    }
    return 0;
}

std::int8_t DataTypeFactory::createInt8(DataTypePtr type)
{
    typedef types::Int8Type ConversionType;
    if (type->getType()==Type::INT8)
    {
        ConversionType * value=dynamic_cast<ConversionType*>(type.get());
        if (value)
        {
            return value->getValue();
        }
    }
    return 0;
}

std::int16_t DataTypeFactory::createInt16(DataTypePtr type)
{
    typedef types::Int16Type ConversionType;
    if (type->getType()==Type::INT16)
    {
        ConversionType * value=dynamic_cast<ConversionType*>(type.get());
        if (value)
        {
            return value->getValue();
        }
    }
    return 0;
}

std::int32_t DataTypeFactory::createInt32(DataTypePtr type)
{
    typedef types::Int32Type ConversionType;
    if (type->getType()==Type::INT32)
    {
        ConversionType * value=dynamic_cast<ConversionType*>(type.get());
        if (value)
        {
            return value->getValue();
        }
    }
    return 0;
}

std::int64_t DataTypeFactory::createInt64(DataTypePtr type)
{
    typedef types::Int64Type ConversionType;
    if (type->getType()==Type::INT64)
    {
        ConversionType * value=dynamic_cast<ConversionType*>(type.get());
        if (value)
        {
            return value->getValue();
        }
    }
    return 0;
}

utility::DateEntity DataTypeFactory::createDate(DataTypePtr type)
{
    typedef types::DateType ConversionType;
    if (type->getType()==Type::DATE)
    {
        ConversionType * value=dynamic_cast<ConversionType*>(type.get());
        if (value)
        {
            return value->getValue();
        }
    }
    return utility::DateEntity();
}

utility::TimeEntity DataTypeFactory::createTime(DataTypePtr type)
{
    typedef types::TimeType ConversionType;
    if (type->getType()==Type::TIME)
    {
        ConversionType * value=dynamic_cast<ConversionType*>(type.get());
        if (value)
        {
            return value->getValue();
        }
    }
    return utility::TimeEntity();
}

bool DataTypeFactory::createBool(DataTypePtr type)
{
    typedef types::BoolType ConversionType;
    if (type->getType()==Type::BOOL)
    {
        ConversionType * value=dynamic_cast<ConversionType*>(type.get());
        if (value)
        {
            return value->getValue();
        }
    }
    return false;
}

}}} //namespace
