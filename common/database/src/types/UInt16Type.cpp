//#-------------------------------------------------
//#
//# File UInt16Type.cpp created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#include "UInt16Type.h"

namespace cbtek {
namespace common {
namespace database {
namespace types{

UInt16Type::UInt16Type(const std::uint16_t &value)
{
    m_value=value;
}

std::uint16_t UInt16Type::getValue() const
{
    return m_value;
}

Type UInt16Type::getType() const
{
    return Type::UINT16;
}
}}}}//namespace
