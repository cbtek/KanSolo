/*
    DatabaseUtils.h
    
///
/// CBTek LLC ("COMPANY") CONFIDENTIAL
/// Copyright (c) 2016 CBTek, All Rights Reserved.
///
/// NOTICE:  All information contained herein is, and remains the property of COMPANY. The intellectual and technical concepts contained
/// herein are proprietary to COMPANY and may be covered by U.S. and Foreign Patents, patents in process, and are protected by trade secret or copyright law.
/// Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
/// from COMPANY.  Access to the source code contained herein is hereby forbidden to anyone except current COMPANY employees, managers or contractors who have executed
/// Confidentiality and Non-disclosure agreements explicitly covering such access.
///
/// The copyright notice above does not evidence any actual or intended publication or disclosure  of  this source code, which includes
/// information that is confidential and/or proprietary, and is a trade secret, of  COMPANY.   ANY REPRODUCTION, MODIFICATION, DISTRIBUTION, PUBLIC  PERFORMANCE,
/// OR PUBLIC DISPLAY OF OR THROUGH USE  OF THIS  SOURCE CODE  WITHOUT  THE EXPRESS WRITTEN CONSENT OF COMPANY IS STRICTLY PROHIBITED, AND IN VIOLATION OF APPLICABLE
/// LAWS AND INTERNATIONAL TREATIES.  THE RECEIPT OR POSSESSION OF  THIS SOURCE CODE AND/OR RELATED INFORMATION DOES NOT CONVEY OR IMPLY ANY RIGHTS
/// TO REPRODUCE, DISCLOSE OR DISTRIBUTE ITS CONTENTS, OR TO MANUFACTURE, USE, OR SELL ANYTHING THAT IT  MAY DESCRIBE, IN WHOLE OR IN PART.
///

*/

#ifndef _CBTEK_COMMON_DATABASE_DATABASEUTILS_H
#define _CBTEK_COMMON_DATABASE_DATABASEUTILS_H

#include <cstdint>
#include <string>

#include "database/inc/QueryResult.hpp"
#include "database/inc/ResultDataRow.h"

namespace cbtek {
namespace common {
namespace database {


class DatabaseUtils 
{
	public:


    private:
    //! Private constructor for DatabaseUtils
	DatabaseUtils();

    //! Private copy constructor for DatabaseUtils
	DatabaseUtils(const DatabaseUtils &);

	//! Private destructor for DatabaseUtils
	~DatabaseUtils();	
};
}}}//end namespace

#endif

