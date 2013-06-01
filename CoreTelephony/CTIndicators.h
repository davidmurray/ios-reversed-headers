/*
 * CoreTelephony indicators.
 */

#ifndef CTINDICATORS_H_
#define CTINDICATORS_H_

#include "CoreHeaders.h"

__BEGIN_DECLS

#pragma mark - API

/*
 * Use 0 for __unknown0.
 */

void CTIndicatorsGetSignalStrength(long int *raw, int __unknown0, long int *bars);

/* For use with the CoreTelephony notification system. */
extern CFStringRef kCTIndicatorsSignalStrengthNotification;

__END_DECLS

#endif /* CTINDICATORS_H_ */
