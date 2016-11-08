//#-------------------------------------------------
//#
//# File UInt8Type.h created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#ifndef _CBTEK_COMMON_DATABASE_TYPES_UINT8TYPE
#define _CBTEK_COMMON_DATABASE_TYPES_UINT8TYPE

#include "database/inc/DataType.hpp"

namespace cbtek {
namespace common {
namespace database {
namespace types{

class UInt8Type : public DataType
{

public:

    UInt8Type(const std::uint8_t & value);

    std::uint8_t getValue()const;

    Type getType() const;

private:

    std::uint8_t m_value;

protected:

};
}}}} //namespace
#endif //_CBTEK_COMMON_DATABASE_TYPES_UINT8TYPE
