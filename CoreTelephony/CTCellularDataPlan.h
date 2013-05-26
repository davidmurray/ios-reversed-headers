/*
 * CoreTelephony cellular data plan support.
 */

#ifndef _CTTelephonyCenter_H_
#define _CTTelephonyCenter_H_

#include "CoreHeaders.h"

__BEGIN_DECLS

#pragma mark - API

Boolean CTCellularDataPlanGetIsEnabled();
void CTCellularDataPlanSetIsEnabled(Boolean enabled);

__END_DECLS

#endif /* _CTTelephonyCenter_H_ */
