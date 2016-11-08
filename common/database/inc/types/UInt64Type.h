//#-------------------------------------------------
//#
//# File UInt64Type.h created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#ifndef _CBTEK_COMMON_DATABASE_TYPES_UINT64TYPE
#define _CBTEK_COMMON_DATABASE_TYPES_UINT64TYPE

#include "database/inc/DataType.hpp"

namespace cbtek {
namespace common {
namespace database {
namespace types{

class UInt64Type : public DataType
{

public:

    UInt64Type(const std::uint64_t & value);

    std::uint64_t getValue()const;

    Type getType() const;

private:

    std::uint64_t m_value;

protected:

};
}}}} //namespace
#endif //_CBTEK_COMMON_DATABASE_TYPES_UINT64TYPE
