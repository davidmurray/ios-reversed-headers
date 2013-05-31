/*
 * CoreTelephony cellular data plan support.
 */

#ifndef _CTCellularDataPlan_H_
#define _CTCellularDataPlan_H_

#include "CoreHeaders.h"

__BEGIN_DECLS

#pragma mark - API

CFBooleanRef CTCellularDataPlanGetIsEnabled();
void CTCellularDataPlanSetIsEnabled(CFBooleanRef enabled);

__END_DECLS

#endif /* _CTCellularDataPlan_H_ */
