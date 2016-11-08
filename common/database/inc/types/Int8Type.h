//#-------------------------------------------------
//#
//# File Int8Type.h created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#ifndef _CBTEK_COMMON_DATABASE_TYPES_INT8TYPE
#define _CBTEK_COMMON_DATABASE_TYPES_INT8TYPE

#include "database/inc/DataType.hpp"

namespace cbtek {
namespace common {
namespace database {
namespace types{

class Int8Type : public DataType
{

public:

    Int8Type(const std::int8_t & value);

    std::int8_t getValue()const;

    Type getType() const;

private:

    std::int8_t m_value;

protected:

};
}}}} //namespace
#endif //_CBTEK_COMMON_DATABASE_TYPES_INT8TYPE
