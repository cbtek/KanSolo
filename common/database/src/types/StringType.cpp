//#-------------------------------------------------
//#
//# File StringType.cpp created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#include "StringType.h"

namespace cbtek {
namespace common {
namespace database {
namespace types{
StringType::StringType(const std::string &value)
{
    m_value=value;
}

std::string StringType::getValue() const
{
    return m_value;
}

Type StringType::getType() const
{
    return Type::STRING;
}
}}}}//namespace
