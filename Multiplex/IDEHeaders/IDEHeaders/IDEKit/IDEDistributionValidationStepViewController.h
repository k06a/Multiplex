//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <IDEKit/IDEDistributionStepViewController.h>

@interface IDEDistributionValidationStepViewController : IDEDistributionStepViewController
{
    BOOL _validateForDirectDistribution;
}

+ (BOOL)skipStepForContext:(id)arg1 assistantDirection:(int)arg2;
@property(readonly) BOOL validateForDirectDistribution; // @synthesize validateForDirectDistribution=_validateForDirectDistribution;
- (void)viewDidInstall;
- (id)providedOutputContextPropertyNames;
- (id)requiredInputContextPropertyNames;
- (BOOL)canGoPrevious;
- (BOOL)canGoNext;
- (id)title;
- (id)nibName;

@end

