//#-------------------------------------------------
//#
//# File Float64Type.cpp created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#include "Float64Type.h"

namespace cbtek {
namespace common {
namespace database {
namespace types{

Float64Type::Float64Type(const double &value)
{
    m_value=value;
}

double Float64Type::getValue() const
{
    return m_value;
}

Type Float64Type::getType() const
{
    return Type::FLOAT64;
}
}}}}//namespace
