//#-------------------------------------------------
//#
//# File Int64Type.h created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#ifndef _CBTEK_COMMON_DATABASE_TYPES_INT64TYPE
#define _CBTEK_COMMON_DATABASE_TYPES_INT64TYPE

#include "database/inc/DataType.hpp"

namespace cbtek {
namespace common {
namespace database {
namespace types{

class Int64Type : public DataType
{

public:

    Int64Type(const std::int64_t & value);

    std::int64_t getValue()const;

    Type getType() const;

private:

    std::int64_t m_value;

protected:

};
}}}} //namespace
#endif //_CBTEK_COMMON_DATABASE_TYPES_INT64TYPE
