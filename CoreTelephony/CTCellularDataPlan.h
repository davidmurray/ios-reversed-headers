/*
 * CoreTelephony cellular data plan support.
 *
 * Copyright (c) 2013, Cykey (David Murray)
 * All rights reserved.
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
