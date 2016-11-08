#include "NullType.h"

namespace cbtek {
namespace common {
namespace database {
namespace types{

NullType::NullType()
{

}

Type NullType::getType() const
{
    return Type::NIL;
}

}}}}//namespace
