//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

#import "IDEGeniusResultNavigableRepresentedObject-Protocol.h"
#import "IDEKeyDrivenNavigableItemRepresentedObject-Protocol.h"

@class DVTDocumentLocation, DVTFileDataType, IDEFileReference, NSImage, NSString, NSURL;

@interface IDECoverageDocumentItem : NSObject <IDEGeniusResultNavigableRepresentedObject, IDEKeyDrivenNavigableItemRepresentedObject>
{
    NSString *_name;
    DVTDocumentLocation *_location;
    DVTFileDataType *_type;
    NSURL *_fileURL;
}

@property(readonly) DVTFileDataType *type; // @synthesize type=_type;
@property(readonly) DVTDocumentLocation *documentLocation; // @synthesize documentLocation=_location;
@property(readonly) NSURL *originalFileURL; // @synthesize originalFileURL=_fileURL;
- (id)geniusResult_identifierForManualCategory;
- (id)geniusResult_identifierForGeniusCategory;
@property(readonly) DVTDocumentLocation *navigableItem_contentDocumentLocation;
@property(readonly) DVTFileDataType *navigableItem_documentType;
@property(readonly) NSImage *navigableItem_image;
@property(readonly) NSString *navigableItem_name;
- (id)initWithName:(id)arg1 originalFileURL:(id)arg2 generatedContentLocation:(id)arg3 type:(id)arg4;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) IDEFileReference *navigableItem_fileReference;
@property(readonly) NSString *navigableItem_groupIdentifier;
@property(readonly) BOOL navigableItem_isLeaf;
@property(readonly) BOOL navigableItem_isMajorGroup;
@property(readonly) NSString *navigableItem_toolTip;
@property(readonly) Class superclass;

@end

