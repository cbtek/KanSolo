//#-------------------------------------------------
//#
//# File Int16Type.cpp created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#include "Int16Type.h"

namespace cbtek {
namespace common {
namespace database {
namespace types{

Int16Type::Int16Type(const std::int16_t &value)
{
    m_value=value;
}

std::int16_t Int16Type::getValue() const
{
    return m_value;
}

Type Int16Type::getType() const
{
    return Type::UINT16;
}
}}}}//namespace
