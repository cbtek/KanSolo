//#-------------------------------------------------
//#
//# File UInt8Type.cpp created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#include "UInt8Type.h"

namespace cbtek {
namespace common {
namespace database {
namespace types{

UInt8Type::UInt8Type(const std::uint8_t &value)
{
    m_value=value;
}

std::uint8_t UInt8Type::getValue() const
{
    return m_value;
}

Type UInt8Type::getType() const
{
    return Type::UINT8;
}
}}}}//namespace
