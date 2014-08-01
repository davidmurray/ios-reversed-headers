
@interface CommunicationsFilterBlockList : NSObject{

}

+ (id)sharedInstance;
- (Boolean)isItemInList:(CommunicationFilterItem *)item;
- (NSArray *)copyAllItems;
- (void)removeItemForAllServices:(CommunicationFilterItem *)item;
- (void)addItemForAllServices:(CommunicationFilterItem *)item;

extern NSString *CMFBlockListUpdatedNotification; // Does not post userInfo

@end

