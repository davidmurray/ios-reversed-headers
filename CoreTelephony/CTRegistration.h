/*
 * CoreTelephony registration system support.
 *
 * Copyright (c) 2013, Cykey (David Murray)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
     * It is actually a pointer to a struct that is used as the return value but you can just use 0.
     */

    void CTRegistrationDataCounterGetAllStatistics(int __unknown0, float *bytesSent, float *bytesReceived);
    void CTRegistrationDataCounterGetAllStatisticsForServiceType(int __unknown0, float *bytesSent, float *bytesReceived, CFStringRef serviceType);

    CFArrayRef CTRegistrationCopySupportedDataRates();
    CFStringRef CTRegistrationGetCurrentMaxAllowedDataRate();
    void CTRegistrationSetMaxAllowedDataRate(CFStringRef dataRate);

    CFStringRef CTRegistrationCopyLocalizedOperatorName(CFAllocatorRef allocator);
    CFStringRef CTRegistrationCopyServiceProviderName(CFAllocatorRef allocator);

    /* Equivalent to CTCellularDataPlan functions. */
    void CTRegistrationSetCellularDataIsEnabled(Boolean enabled);
    Boolean CTRegistrationGetCellularDataIsEnabled();

#if __cplusplus
}
#endif

#endif /* CTREGISTRATION_H_ */
