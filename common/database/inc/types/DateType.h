//#-------------------------------------------------
//#
//# File DateType.h created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#ifndef _CBTEK_COMMON_DATABASE_TYPES_DATETYPE
#define _CBTEK_COMMON_DATABASE_TYPES_DATETYPE

#include "database/inc/DataType.hpp"
#include "utility/inc/DateEntity.h"

namespace cbtek {
namespace common {
namespace database {
namespace types{

class DateType : public DataType
{

public:

    DateType(const common::utility::DateEntity & value);

    common::utility::DateEntity getValue()const;

    Type getType() const;

private:

    common::utility::DateEntity m_value;

protected:

};
}}}} //namespace
#endif //_CBTEK_COMMON_DATABASE_TYPES_DATETYPE
