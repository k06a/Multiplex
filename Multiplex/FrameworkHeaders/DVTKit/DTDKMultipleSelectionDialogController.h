//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <DVTKit/DTDKSelectionDialogController.h>

@class DVTObservingToken, NSArray, NSArrayController, NSSet;

@interface DTDKMultipleSelectionDialogController : DTDKSelectionDialogController
{
    DVTObservingToken *_observingToken;
    NSArray *_tableContents;
    NSSet *_selectedIdentifiers;
    NSArrayController *_arrayController;
}

+ (id)keyPathsForValuesAffectingCanProceed;
+ (id)keyPathsForValuesAffectingTableContents;
+ (id)dialogController;
@property(retain) NSArrayController *arrayController; // @synthesize arrayController=_arrayController;
@property(copy, nonatomic) NSSet *selectedIdentifiers; // @synthesize selectedIdentifiers=_selectedIdentifiers;
@property(copy, nonatomic) NSArray *tableContents; // @synthesize tableContents=_tableContents;
@property(readonly) _Bool canProceed;
- (void)setChoices:(id)arg1;
- (void)loadWindow;
- (void)dealloc;

@end

