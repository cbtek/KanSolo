//#-------------------------------------------------
//#
//# File UInt64Type.cpp created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#include "UInt64Type.h"

namespace cbtek {
namespace common {
namespace database {
namespace types{

UInt64Type::UInt64Type(const std::uint64_t &value)
{
    m_value=value;
}

std::uint64_t UInt64Type::getValue() const
{
    return m_value;
}

Type UInt64Type::getType() const
{
    return Type::UINT64;
}

}}}}//namespace
