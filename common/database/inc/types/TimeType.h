//#-------------------------------------------------
//#
//# File TimeType.h created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#ifndef _CBTEK_COMMON_DATABASE_TYPES_TIMETYPE
#define _CBTEK_COMMON_DATABASE_TYPES_TIMETYPE

#include "database/inc/DataType.hpp"
#include "utility/inc/TimeEntity.h"

namespace cbtek {
namespace common {
namespace database {
namespace types{

class TimeType : public DataType
{

public:

    TimeType(const common::utility::TimeEntity & value);

    common::utility::TimeEntity getValue()const;

    Type getType() const;

private:

    common::utility::TimeEntity m_value;

protected:

};
}}}} //namespace
#endif //_CBTEK_COMMON_DATABASE_TYPES_TIMETYPE
