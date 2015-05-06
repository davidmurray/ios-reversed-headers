
@interface CommunicationFilterItemCache : NSObject{
    
}

@property(nonatomic) long long isInList;
- (Boolean)matchesItem:(CommunicationFilterItem *)item;
- (id)initWithFilterItem:(CommunicationFilterItem *)item isInList:(long long)arg2;

@end

