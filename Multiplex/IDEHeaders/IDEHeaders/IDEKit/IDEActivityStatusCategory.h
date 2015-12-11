//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class NSImage, NSString;

@interface IDEActivityStatusCategory : NSObject
{
    NSString *_title;
    long long _count;
    NSImage *_image;
    dispatch_block_t _clickHandler;
}

@property(readonly) dispatch_block_t clickHandler; // @synthesize clickHandler=_clickHandler;
@property long long count; // @synthesize count=_count;
@property(retain) NSString *title; // @synthesize title=_title;
@property(retain) NSImage *image; // @synthesize image=_image;
- (id)description;
- (id)initWithTitle:(id)arg1 image:(id)arg2 clickHandler:(dispatch_block_t)arg3;

@end
