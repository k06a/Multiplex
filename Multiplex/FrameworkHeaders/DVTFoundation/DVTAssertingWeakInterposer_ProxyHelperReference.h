//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <DVTFoundation/DVTWeakInterposer_ProxyHelperReference.h>

@interface DVTAssertingWeakInterposer_ProxyHelperReference : DVTWeakInterposer_ProxyHelperReference
{
    Class representedObjectClass;
    void *representedObjectAddress;
}

@property void *representedObjectAddress; // @synthesize representedObjectAddress;
@property Class representedObjectClass; // @synthesize representedObjectClass;
- (void)_customSetup;
- (id)representedObject;

@end

