//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class DVTSourceTextView;

@interface DVTSourceTextSelectionAccessibilityProxy : NSObject
{
    DVTSourceTextView *_parent;
}

@property(retain) DVTSourceTextView *parent; // @synthesize parent=_parent;
- (id)accessibilityAttributeValue:(id)arg1;
- (id)accessibilityAttributeNames;
- (id)accessibilityHitTest:(struct CGPoint)arg1;
- (BOOL)accessibilityIsIgnored;
- (struct CGRect)frameForProxy;
- (id)initWithParent:(id)arg1;

@end

