//#-------------------------------------------------
//#
//# File Int16Type.h created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#ifndef _CBTEK_COMMON_DATABASE_TYPES_INT16TYPE
#define _CBTEK_COMMON_DATABASE_TYPES_INT16TYPE

#include "database/inc/DataType.hpp"

namespace cbtek {
namespace common {
namespace database {
namespace types{

class Int16Type : public DataType
{

public:

    Int16Type(const std::int16_t & value);

    std::int16_t getValue()const;

    Type getType() const;

private:

    std::int16_t m_value;

protected:

};
}}}} //namespace
#endif //_CBTEK_COMMON_DATABASE_TYPES_INT16TYPE
