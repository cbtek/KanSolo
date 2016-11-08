//#-------------------------------------------------
//#
//# File StringType.h created by shadowefusion on 01-11-2014 at 2:34:0
//#
//#-------------------------------------------------

#ifndef _CBTEK_COMMON_DATABASE_TYPES_STRINGTYPE
#define _CBTEK_COMMON_DATABASE_TYPES_STRINGTYPE

#include <iostream>

#include "database/inc/DataType.hpp"

namespace cbtek {
namespace common {
namespace database {
namespace types{

class StringType : public DataType
{

public:

    StringType(const std::string & value);

    std::string getValue()const;

    Type getType() const;

private:

    std::string m_value;

protected:

};
}}}} //namespace
#endif //_CBTEK_COMMON_DATABASE_TYPES_STRINGTYPE
