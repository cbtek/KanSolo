//#-------------------------------------------------
//#
//# File DateType.cpp created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#include "DateType.h"

namespace cbtek {
namespace common {
namespace database {
namespace types{
DateType::DateType(const common::utility::DateEntity &value)
{
    m_value=value;
}

common::utility::DateEntity DateType::getValue() const
{
    return m_value;
}

Type DateType::getType() const
{
    return Type::DATE;
}
}}}}//namespace
