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
#include "ResultDataRow.h"

#include "utility/inc/StringUtils.hpp"
#include "utility/inc/Exception.hpp"


using namespace cbtek::common::utility;

namespace cbtek {
namespace common {
namespace database {

CREATE_EXCEPTION(ResultDataRowException, "ResultDataRow exception")

ResultDataRow::ResultDataRow()
{
}

int64_t ResultDataRow::getInteger(const std::string &fieldName) const
{
    size_t index = StringUtils::indexOf(fieldName,m_headers,false);
    if (index != std::string::npos && index < this->size())
    {
        DataTypePtr valueType = this->at(index);
        if (!valueType.get())
        {
            throw ResultDataRowException(EXCEPTION_TAG+"NULL value type detected for \""+fieldName+"\"");
        }
        switch (valueType->getType())
        {
            case Type::INT8: return (dynamic_cast<types::Int8Type*>(valueType.get()))->getValue();
            case Type::INT16:return (dynamic_cast<types::Int16Type*>(valueType.get()))->getValue();
            case Type::INT32:return (dynamic_cast<types::Int32Type*>(valueType.get()))->getValue();
            case Type::INT64:return (dynamic_cast<types::Int64Type*>(valueType.get()))->getValue();
            case Type::UINT8:return  static_cast<std::int64_t>((dynamic_cast<types::UInt8Type*>(valueType.get()))->getValue());
            case Type::UINT16:return static_cast<std::int64_t>((dynamic_cast<types::UInt16Type*>(valueType.get()))->getValue());
            case Type::UINT32:return static_cast<std::int64_t>((dynamic_cast<types::UInt32Type*>(valueType.get()))->getValue());
            case Type::UINT64:return static_cast<std::int64_t>((dynamic_cast<types::UInt64Type*>(valueType.get()))->getValue());
            default:break;
        }
        throw ResultDataRowException(EXCEPTION_TAG+"Invalid value type detected for \""+fieldName+"\"");
    }
    else
    {
        throw ResultDataRowException(EXCEPTION_TAG+"Value type could not be found with name = \""+fieldName+"\" in this data row!");
    }
}

std::string ResultDataRow::getText(const std::string &fieldName) const
{
    if (m_headers.size() == 0)
    {
        return "";
    }
    size_t index = StringUtils::indexOf(fieldName,m_headers,false);
    if (index != std::string::npos && index < this->size())
    {
        DataTypePtr valueType = this->at(index);
        if (!valueType.get())
        {
            throw ResultDataRowException(EXCEPTION_TAG+"NULL value type detected for \""+fieldName+"\"");
        }
        switch (valueType->getType())
        {
            case Type::STRING : return (dynamic_cast<types::StringType*>(valueType.get()))->getValue();
            case Type::DATE : return StringUtils::toString((dynamic_cast<types::DateType*>(valueType.get()))->getValue().toDateInteger());
            case Type::TIME : return StringUtils::toString((dynamic_cast<types::TimeType*>(valueType.get()))->getValue().toTimeInteger());
            case Type::BOOL : return ((dynamic_cast<types::BoolType*>(valueType.get()))->getValue()?"true":"false");
            case Type::NIL : return "";
            case Type::FLOAT32:return StringUtils::toString((dynamic_cast<types::Float32Type*>(valueType.get()))->getValue());
            case Type::FLOAT64:return StringUtils::toString((dynamic_cast<types::Float64Type*>(valueType.get()))->getValue());
            case Type::INT8: return StringUtils::toString((dynamic_cast<types::Int8Type*>(valueType.get()))->getValue());
            case Type::INT16:return StringUtils::toString((dynamic_cast<types::Int16Type*>(valueType.get()))->getValue());
            case Type::INT32:return StringUtils::toString((dynamic_cast<types::Int32Type*>(valueType.get()))->getValue());
            case Type::INT64:return StringUtils::toString((dynamic_cast<types::Int64Type*>(valueType.get()))->getValue());
            case Type::UINT8:return  StringUtils::toString((dynamic_cast<types::UInt8Type*>(valueType.get()))->getValue());
            case Type::UINT16:return StringUtils::toString((dynamic_cast<types::UInt16Type*>(valueType.get()))->getValue());
            case Type::UINT32:return StringUtils::toString((dynamic_cast<types::UInt32Type*>(valueType.get()))->getValue());
            case Type::UINT64:return StringUtils::toString((dynamic_cast<types::UInt64Type*>(valueType.get()))->getValue());
            default:break;
        }
        throw ResultDataRowException(EXCEPTION_TAG+"Invalid value type detected for \""+fieldName+"\"");
    }
    else
    {
        throw ResultDataRowException(EXCEPTION_TAG+"Value type could not be found with name = \""+fieldName+"\" in this data row!");
    }
}

double ResultDataRow::getNumeric(const std::string &fieldName) const
{
    size_t index = StringUtils::indexOf(fieldName,m_headers,false);
    if (index != std::string::npos && index < this->size())
    {
        DataTypePtr valueType = this->at(index);
        if (!valueType.get())
        {
            throw ResultDataRowException(EXCEPTION_TAG+"NULL value type detected for \""+fieldName+"\"");
        }
        switch (valueType->getType())
        {
            case Type::FLOAT32:return (dynamic_cast<types::Float32Type*>(valueType.get()))->getValue();
            case Type::FLOAT64:return (dynamic_cast<types::Float64Type*>(valueType.get()))->getValue();
            case Type::INT8: return static_cast<double>((dynamic_cast<types::Int8Type*>(valueType.get()))->getValue());
            case Type::INT16:return static_cast<double>((dynamic_cast<types::Int16Type*>(valueType.get()))->getValue());
            case Type::INT32:return static_cast<double>((dynamic_cast<types::Int32Type*>(valueType.get()))->getValue());
            case Type::INT64:return static_cast<double>((dynamic_cast<types::Int64Type*>(valueType.get()))->getValue());
            case Type::UINT8:return  static_cast<double>((dynamic_cast<types::UInt8Type*>(valueType.get()))->getValue());
            case Type::UINT16:return static_cast<double>((dynamic_cast<types::UInt16Type*>(valueType.get()))->getValue());
            case Type::UINT32:return static_cast<double>((dynamic_cast<types::UInt32Type*>(valueType.get()))->getValue());
            case Type::UINT64:return static_cast<double>((dynamic_cast<types::UInt64Type*>(valueType.get()))->getValue());
            default:break;
        }
        throw ResultDataRowException(EXCEPTION_TAG+"Invalid value type detected for \""+fieldName+"\"");
    }
    else
    {
        throw ResultDataRowException(EXCEPTION_TAG+"Value type could not be found with name = \""+fieldName+"\" in this data row!");
    }
}

ResultDataRow &ResultDataRow::operator<<(const types::UInt64Type &value)
{
    push_back(std::make_shared<types::UInt64Type>(value));
    return (*this);
}

ResultDataRow &ResultDataRow::operator<<(const types::UInt32Type &value)
{
    push_back(std::make_shared<types::UInt32Type>(value));
    return (*this);
}

ResultDataRow &ResultDataRow::operator<<(const types::UInt16Type &value)
{
    push_back(std::make_shared<types::UInt16Type>(value));
    return (*this);
}

ResultDataRow &ResultDataRow::operator<<(const types::UInt8Type &value)
{
    push_back(std::make_shared<types::UInt8Type>(value));
    return (*this);
}

ResultDataRow &ResultDataRow::operator<<(const types::Int64Type &value)
{
    push_back(std::make_shared<types::Int64Type>(value));
    return (*this);
}

ResultDataRow &ResultDataRow::operator<<(const types::Int32Type &value)
{
    push_back(std::make_shared<types::Int32Type>(value));
    return (*this);
}

ResultDataRow &ResultDataRow::operator<<(const types::Int16Type &value)
{
    push_back(std::make_shared<types::Int16Type>(value));
    return (*this);
}

ResultDataRow &ResultDataRow::operator<<(const types::Int8Type &value)
{
    push_back(std::make_shared<types::Int8Type>(value));
    return (*this);
}

ResultDataRow &ResultDataRow::operator<<(const types::Float64Type &value)
{
    push_back(std::make_shared<types::Float64Type>(value));
    return (*this);
}

ResultDataRow &ResultDataRow::operator<<(const types::Float32Type &value)
{
    push_back(std::make_shared<types::Float32Type>(value));
    return (*this);
}

ResultDataRow &ResultDataRow::operator<<(const std::string &value)
{
    push_back(std::make_shared<types::StringType>(value));
    return (*this);
}

ResultDataRow &ResultDataRow::operator<<(const utility::DateEntity &value)
{
    push_back(std::make_shared<types::DateType>(value));
    return (*this);
}

ResultDataRow &ResultDataRow::operator<<(const utility::TimeEntity &value)
{
    push_back(std::make_shared<types::TimeType>(value));
    return (*this);
}

ResultDataRow &ResultDataRow::operator<<(const types::NullType &value)
{
    push_back(std::make_shared<types::NullType>(value));
    return (*this);
}

ResultDataRow &ResultDataRow::operator<<(const bool &value)
{
    push_back(std::make_shared<types::BoolType>(value));
    return (*this);
}

void ResultDataRow::setHeaders(const std::vector<std::string> &headers)
{
    m_headers=headers;
}

void ResultDataRow::clear()
{    
    std::vector<DataTypePtr>::clear();
}

ResultDataRow::~ResultDataRow()
{
    clear();
}
}}}//namespace
