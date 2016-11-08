//#-------------------------------------------------
//#
//# File Float32Type.cpp created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#include "Float32Type.h"

namespace cbtek {
namespace common {
namespace database {
namespace types{
Float32Type::Float32Type(const float &value)
{
    m_value=value;
}

float Float32Type::getValue() const
{
    return m_value;
}

Type Float32Type::getType() const
{
    return Type::FLOAT32;
}
}}}}//namespace
