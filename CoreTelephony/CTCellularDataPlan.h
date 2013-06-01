/*
 * CoreTelephony cellular data plan support.
 */

#ifndef CTCELLULARDATAPLAN_H_
#define CTCELLULARDATAPLAN_H_

#include "CoreHeaders.h"

__BEGIN_DECLS

#pragma mark - API

Boolean CTCellularDataPlanGetIsEnabled();
void CTCellularDataPlanSetIsEnabled(Boolean enabled);

__END_DECLS

#endif /* CTCELLULARDATAPLAN_H_ */
