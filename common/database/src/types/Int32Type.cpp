//#-------------------------------------------------
//#
//# File Int32Type.cpp created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#include "Int32Type.h"

namespace cbtek {
namespace common {
namespace database {
namespace types{

Int32Type::Int32Type(const std::int32_t &value)
{
    m_value=value;
}

std::int32_t Int32Type::getValue() const
{
    return m_value;
}

Type Int32Type::getType() const
{
    return Type::UINT32;
}
}}}}//namespace
