//#-------------------------------------------------
//#
//# File UInt32Type.h created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#ifndef _CBTEK_COMMON_DATABASE_TYPES_UINT32TYPE
#define _CBTEK_COMMON_DATABASE_TYPES_UINT32TYPE

#include "database/inc/DataType.hpp"

namespace cbtek {
namespace common {
namespace database {
namespace types{

class UInt32Type : public DataType
{

public:

    UInt32Type(const std::uint32_t & value);

    std::uint32_t getValue()const;

    Type getType() const;

private:

    std::uint32_t m_value;

protected:

};
}}}} //namespace
#endif //_CBTEK_COMMON_DATABASE_TYPES_UINT32TYPE
