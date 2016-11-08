//#-------------------------------------------------
//#
//# File Float32Type.h created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#ifndef _CBTEK_COMMON_DATABASE_TYPES_FLOAT32TYPE
#define _CBTEK_COMMON_DATABASE_TYPES_FLOAT32TYPE


#include "database/inc/DataType.hpp"

namespace cbtek {
namespace common {
namespace database {
namespace types{

class Float32Type : public DataType
{

public:

    Float32Type(const float & value);

    float getValue()const;

    Type getType() const;

private:

    float m_value;

protected:

};
}}}} //namespace
#endif //_CBTEK_COMMON_DATABASE_TYPES_FLOAT32TYPE
