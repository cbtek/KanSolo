#ifndef _CBTEK_COMMON_DATABASE_TYPES_BOOLTYPE_H
#define _CBTEK_COMMON_DATABASE_TYPES_BOOLTYPE_H

#include "database/inc/DataType.hpp"

namespace cbtek {
namespace common {
namespace database {
namespace types{

class BoolType : public DataType
{

public:

    BoolType(const bool & value);

    bool getValue()const;

    Type getType() const;

private:

    bool m_value;

protected:

};
}}}}//namespace
#endif // _CBTEK_COMMON_DATABASE_TYPES_BOOLTYPE_H
