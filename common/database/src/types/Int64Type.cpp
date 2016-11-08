//#-------------------------------------------------
//#
//# File Int64Type.cpp created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#include "Int64Type.h"

namespace cbtek {
namespace common {
namespace database {
namespace types{

Int64Type::Int64Type(const std::int64_t &value)
{
    m_value=value;
}

std::int64_t Int64Type::getValue() const
{
    return m_value;
}

Type Int64Type::getType() const
{
    return Type::INT64;
}
}}}}//namespace
