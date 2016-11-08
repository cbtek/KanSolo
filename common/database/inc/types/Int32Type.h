//#-------------------------------------------------
//#
//# File Int32Type.h created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#ifndef _CBTEK_COMMON_DATABASE_TYPES_INT32TYPE
#define _CBTEK_COMMON_DATABASE_TYPES_INT32TYPE

#include "database/inc/DataType.hpp"

namespace cbtek {
namespace common {
namespace database {
namespace types{

class Int32Type : public DataType
{

public:

    Int32Type(const std::int32_t & value);

    std::int32_t getValue()const;

    Type getType() const;

private:

    std::int32_t m_value;

protected:

};
}}}} //namespace
#endif //_CBTEK_COMMON_DATABASE_TYPES_INT32TYPE
