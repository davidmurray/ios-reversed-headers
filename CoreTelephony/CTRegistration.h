/*
 * CoreTelephony registration system support.
 *
 * Copyright (c) 2013-2014 Cykey (David Murray)
 * All rights reserved.
 */

#ifndef CTREGISTRATION_H_
#define CTREGISTRATION_H_

#include <CoreFoundation/CoreFoundation.h>

#if __cplusplus
extern "C" {
#endif

#pragma mark - Definitions

    /* For use with the CoreTelephony notification system. */
    extern CFStringRef kCTRegistrationStatusChangedNotification;
    extern CFStringRef kCTRegistrationStateDurationReportNotification;
    extern CFStringRef kCTRegistrationServiceProviderNameChangedNotification;
    extern CFStringRef kCTRegistrationOperatorNameChangedNotification;
    extern CFStringRef kCTRegistrationNewServingNetworkNotification;
    extern CFStringRef kCTRegistrationDataStatusChangedNotification;
    extern CFStringRef kCTRegistrationDataActivateFailedNotification;
    extern CFStringRef kCTRegistrationCellularDataPlanHideIndicatorNotification;
    extern CFStringRef kCTRegistrationCellularDataPlanActivateFailedNotification;
    extern CFStringRef kCTRegistrationCustomerServiceProfileUpdateNotification;
    extern CFStringRef kCTRegistrationCellChangedNotification;
    extern CFStringRef kCTRegistrationCauseCodeNotification;

    /* Service types. */
    extern CFStringRef kCTDataConnectionServiceType3GFaceTimeAuthentication;
    extern CFStringRef kCTDataConnectionServiceType3GFaceTimeTraffic;
    extern CFStringRef kCTDataConnectionServiceTypeAppleWirelessDiagnostics;
    extern CFStringRef kCTDataConnectionServiceTypeCellularDataPlanProvisioning;
    extern CFStringRef kCTDataConnectionServiceTypeDataTest;
    extern CFStringRef kCTDataConnectionServiceTypeEntitlementTraffic;
    extern CFStringRef kCTDataConnectionServiceTypeInternalDataProbe;
    extern CFStringRef kCTDataConnectionServiceTypeInternet;
    extern CFStringRef kCTDataConnectionServiceTypeMMS;
    extern CFStringRef kCTDataConnectionServiceTypeOMADM;
    extern CFStringRef kCTDataConnectionServiceTypeOTAActivation;
    extern CFStringRef kCTDataConnectionServiceTypeOTAInternet;
    extern CFStringRef kCTDataConnectionServiceTypePushEmail;
    extern CFStringRef kCTDataConnectionServiceTypeVVM;
    extern CFStringRef kCTDataConnectionServiceTypeWirelessModemAuthentication;
    extern CFStringRef kCTDataConnectionServiceTypeWirelessModemTraffic;
    extern CFStringRef kCTDataConnectionServiceTypeZeroRated;

    /* Data rates. */
    extern CFStringRef const kCTRegistrationDataRateUnknown;
    extern CFStringRef const kCTRegistrationDataRate2G;
    extern CFStringRef const kCTRegistrationDataRate3G;
    extern CFStringRef const kCTRegistrationDataRate4G;

#pragma mark - API

    /*
     * Use 0 for __unknown0.
     * It is actually a pointer to a struct that is used as the return value but you can just use 0 (NULL).
     */

    void CTRegistrationDataCounterGetAllStatistics(int __unknown0, float *bytesSent, float *bytesReceived);
    void CTRegistrationDataCounterGetAllStatisticsForServiceType(int __unknown0, float *bytesSent, float *bytesReceived, CFStringRef serviceType);

    void CTRegistrationDataCounterReset();

    /*
     * Returns the number of seconds since 1 January 2001, GMT.
     * Use +[NSDate dateWithTimeIntervalSinceReferenceDate:].
     */

    double CTRegistrationDataCounterGetLastResetTime();

    CFArrayRef CTRegistrationCopySupportedDataRates();
    CFStringRef CTRegistrationGetCurrentMaxAllowedDataRate();
    void CTRegistrationSetMaxAllowedDataRate(CFStringRef dataRate);

    /* Use 0 for __unknown0. */
    Boolean CTRegistrationGetDataContextActive(int __unknown0);

    CFStringRef CTRegistrationCopyLocalizedOperatorName(CFAllocatorRef allocator);
    CFStringRef CTRegistrationCopyServiceProviderName(CFAllocatorRef allocator);

    /* Equivalent to CTCellularDataPlan functions. */
    void CTRegistrationSetCellularDataIsEnabled(Boolean enabled);
    Boolean CTRegistrationGetCellularDataIsEnabled();

#if __cplusplus
}
#endif

#endif /* CTREGISTRATION_H_ */
