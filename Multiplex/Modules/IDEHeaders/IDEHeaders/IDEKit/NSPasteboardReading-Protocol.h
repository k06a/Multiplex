//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class NSArray, NSPasteboard, NSString;

@protocol NSPasteboardReading <NSObject>
+ (NSArray *)readableTypesForPasteboard:(NSPasteboard *)arg1;

@optional
+ (unsigned long long)readingOptionsForType:(NSString *)arg1 pasteboard:(NSPasteboard *)arg2;
- (id)initWithPasteboardPropertyList:(id)arg1 ofType:(NSString *)arg2;
@end
