//#-------------------------------------------------
//#
//# File TimeType.cpp created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#include "TimeType.h"

namespace cbtek {
namespace common {
namespace database {
namespace types{
TimeType::TimeType(const common::utility::TimeEntity &value)
{
    m_value=value;
}

common::utility::TimeEntity TimeType::getValue() const
{
    return m_value;
}

Type TimeType::getType() const
{
    return Type::TIME;
}
}}}}//namespace
