//#-------------------------------------------------
//#
//# File Int8Type.cpp created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#include "Int8Type.h"

namespace cbtek {
namespace common {
namespace database {
namespace types{

Int8Type::Int8Type(const std::int8_t &value)
{
    m_value=value;
}

std::int8_t Int8Type::getValue() const
{
    return m_value;
}

Type Int8Type::getType() const
{
    return Type::INT8;
}
}}}}//namespace
