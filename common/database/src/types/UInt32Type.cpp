//#-------------------------------------------------
//#
//# File UInt32Type.cpp created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#include "UInt32Type.h"

namespace cbtek {
namespace common {
namespace database {
namespace types{

UInt32Type::UInt32Type(const std::uint32_t &value)
{
    m_value=value;
}

std::uint32_t UInt32Type::getValue() const
{
    return m_value;
}

Type UInt32Type::getType() const
{
    return Type::UINT32;
}
}}}}//namespace
