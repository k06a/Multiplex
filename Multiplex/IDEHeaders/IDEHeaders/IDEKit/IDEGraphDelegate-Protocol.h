//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class NSColor, NSEvent, NSGradient, NSNumber, NSString;

@protocol IDEGraphDelegate <NSObject>
- (NSColor *)colorForChartNamed:(NSString *)arg1;

@optional
- (void)userMouseExitedGraph:(id)arg1 event:(NSEvent *)arg2;
- (void)userMousedOverOnGraphEntry:(id)arg1 event:(NSEvent *)arg2;
- (void)userClickedOnGraphEntry:(id)arg1;
- (NSColor *)borderColorForBorder:(NSColor *)arg1;
- (NSGradient *)gradientForColor:(NSColor *)arg1;
- (NSString *)translateValue:(NSNumber *)arg1 keypath:(NSString *)arg2;
- (NSColor *)colorForEntryValue:(NSNumber *)arg1;
@end

