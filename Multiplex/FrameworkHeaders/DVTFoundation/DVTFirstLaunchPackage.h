//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class NSString;

@interface DVTFirstLaunchPackage : NSObject
{
    NSString *_displayName;
    NSString *_description;
    NSString *_path;
}

@property(readonly) NSString *path; // @synthesize path=_path;
@property(readonly) NSString *description; // @synthesize description=_description;
@property(readonly) NSString *displayName; // @synthesize displayName=_displayName;
- (id)_initWithPath:(id)arg1 packageInfo:(id)arg2;

@end

