#include "BoolType.h"

namespace cbtek {
namespace common {
namespace database {
namespace types{

BoolType::BoolType(const bool &value)
{
    m_value=value;
}

bool BoolType::getValue() const
{
    return m_value;
}

Type BoolType::getType() const
{
    return Type::BOOL;
}

}}}}//namespace
