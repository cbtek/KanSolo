//#-------------------------------------------------
//#
//# File Float6464Type.h created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#ifndef _CBTEK_COMMON_DATABASE_TYPES_FLOAT64TYPE
#define _CBTEK_COMMON_DATABASE_TYPES_FLOAT64TYPE

#include "database/inc/DataType.hpp"

namespace cbtek {
namespace common {
namespace database {
namespace types{

class Float64Type : public DataType
{

public:

    Float64Type(const double & value);

    double getValue()const;

    Type getType() const;

private:

    double m_value;

protected:

};
}}}} //namespace
#endif //_CBTEK_COMMON_DATABASE_TYPES_FLOAT64TYPE
