//#-------------------------------------------------
//#
//# File UInt16Type.h created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#ifndef _CBTEK_COMMON_DATABASE_TYPES_UINT16TYPE
#define _CBTEK_COMMON_DATABASE_TYPES_UINT16TYPE

#include "database/inc/DataType.hpp"

namespace cbtek {
namespace common {
namespace database {
namespace types{

class UInt16Type : public DataType
{

public:

    UInt16Type(const std::uint16_t & value);

    std::uint16_t getValue()const;

    Type getType() const;

private:

    std::uint16_t m_value;

protected:

};
}}}} //namespace
#endif //_CBTEK_COMMON_DATABASE_TYPES_UINT16TYPE
