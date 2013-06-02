/*
 * CoreTelephony cellular data plan support.
 */

#ifndef CTCELLULARDATAPLAN_H_
#define CTCELLULARDATAPLAN_H_

#include <CoreFoundation/CoreFoundation.h>

#if __cplusplus
extern "C" {
#endif

#pragma mark - API

    Boolean CTCellularDataPlanGetIsEnabled();
    void CTCellularDataPlanSetIsEnabled(Boolean enabled);

#if __cplusplus
}
#endif

#endif /* CTCELLULARDATAPLAN_H_ */
