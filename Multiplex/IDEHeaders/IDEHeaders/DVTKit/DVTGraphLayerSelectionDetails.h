//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class NSString;

@interface DVTGraphLayerSelectionDetails : NSObject
{
    NSString *_description;
    struct CGPoint _modelAnchorPoint;
}

@property(readonly) struct CGPoint modelAnchorPoint; // @synthesize modelAnchorPoint=_modelAnchorPoint;
@property(readonly) NSString *description; // @synthesize description=_description;
- (id)initWithDescriptionString:(id)arg1 anchorPoint:(struct CGPoint)arg2;

@end

