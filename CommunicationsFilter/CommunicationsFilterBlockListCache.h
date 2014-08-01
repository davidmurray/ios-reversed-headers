
@interface CommunicationsFilterBlockListCache : NSObject{
    
}

- (void)setResponse:(Boolean)response forItem:(CommunicationFilterItem *)item;
- (void)removeItemFromCache:(CommunicationFilterItem *)item;
- (long long)cachedResponseForItem:(CommunicationFilterItem *)item;

@end

