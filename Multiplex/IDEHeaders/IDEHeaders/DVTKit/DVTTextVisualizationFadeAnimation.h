//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class DVTTextVisualization;

@interface DVTTextVisualizationFadeAnimation : NSAnimation
{
    double _initialOpacity;
    DVTTextVisualization *_visualization;
    double _targetOpacity;
    dispatch_block_t _completionBlock;
}

@property(copy) dispatch_block_t completionBlock; // @synthesize completionBlock=_completionBlock;
@property double targetOpacity; // @synthesize targetOpacity=_targetOpacity;
@property(retain) DVTTextVisualization *visualization; // @synthesize visualization=_visualization;
- (void)setCurrentProgress:(float)arg1;
- (id)initWithVisualization:(id)arg1;

@end

