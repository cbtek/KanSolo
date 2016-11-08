#ifndef _CBTEK_COMMON_DATABASE_TYPES_NULLTYPE_H
#define _CBTEK_COMMON_DATABASE_TYPES_NULLTYPE_H

#include "database/inc/DataType.hpp"

namespace cbtek {
namespace common {
namespace database {
namespace types{

class NullType : public DataType
{

public:

    NullType();

    Type getType() const;

private:


protected:

};
}}}} //namespace
#endif // _CBTEK_COMMON_DATABASE_TYPES_NULLTYPE_H
