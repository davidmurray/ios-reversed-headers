typedef struct __CFPhoneNumber* CFPhoneNumberRef;

#pragma mark CommunicationFilterItem

@interface CommunicationFilterItem : NSObject{
    
}

@property(readonly, nonatomic) NSString *emailAddress;
@property(readonly, nonatomic) CFPhoneNumberRef *phoneNumber;
- (id)dictionaryRepresentation;
- (Boolean)matchesFilterItem:(CommunicationFilterItem *)item; // a la -isEqualTo
@property(readonly, nonatomic) NSString *unformattedID;
- (Boolean)isPhoneNumber;
- (id)initWithDictionaryRepresentation:(NSDictionary *)dictionaryRepresentation; // A dictionary should consist of constants described here

- (id)initWithEmailAddress:(NSString *)emailAddress;
- (id)initWithPhoneNumber:(CFPhoneNumberRef)phoneNumber; // Seems like phoneNumber has to be normalized like "+000 (000) 00 000"

@end

CommunicationFilterItem *CreateCMFItemFromString(CFStringRef string); // Can be email or phone number (e.g. +00000000000)

#pragma mark Constants


#define kCMFItemPhoneNumberCountryCodeKey CFSTR("__kCMFItemPhoneNumberCountryCodeKey") // Depends on current locale rather than phone number
#define kCMFItemPhoneNumberUnformattedKey CFSTR("__kCMFItemPhoneNumberUnformattedKey")
#define kCMFItemTypeKey CFSTR("__kCMFItemTypeKey") // 0 – phone; 1 – email
#define kCMFItemVersionKey CFSTR ("__kCMFItemVersionKey") // Unused
#define kCMFItemEmailUnformattedKey CFSTR("__kCMFItemEmailUnformattedKey")