/*
 * CoreTelephony indicators.
 */

#ifndef CTINDICATORS_H_
#define CTINDICATORS_H_

#include <CoreFoundation/CoreFoundation.h>

#if __cplusplus
extern "C" {
#endif

#pragma mark - API

    /*
     * Use 0 for __unknown0.
     */

    void CTIndicatorsGetSignalStrength(long int *raw, int __unknown0, long int *bars);

#pragma mark - Definitions

    /* For use with the CoreTelephony notification system. */
    extern CFStringRef kCTIndicatorsSignalStrengthNotification;

#if __cplusplus
}
#endif

#endif /* CTINDICATORS_H_ */
