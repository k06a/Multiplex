//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class NSFont, NSString;

@interface DVTTextViewWithPlaceholder : NSTextView
{
    NSString *_centeredPlaceholderString;
    BOOL _didDrawPlaceholder;
    NSFont *_placeholderFont;
}

@property(retain, nonatomic) NSFont *placeholderFont; // @synthesize placeholderFont=_placeholderFont;
@property(copy) NSString *centeredPlaceholderString; // @synthesize centeredPlaceholderString=_centeredPlaceholderString;
- (void)didChangeText;
- (void)drawViewBackgroundInRect:(struct CGRect)arg1;

@end

