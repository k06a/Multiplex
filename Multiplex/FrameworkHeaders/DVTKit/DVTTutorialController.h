//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"


@class DVTPageController, DVTTutorialViewController, NSStoryboard, NSString, NSView;

@interface DVTTutorialController : NSObject <NSPageControllerDelegate>
{
    DVTPageController *_pageController;
    NSStoryboard *_storyboard;
    DVTTutorialViewController *_tutorialViewController;
}

+ (id)linkColor;
@property(retain) DVTTutorialViewController *tutorialViewController; // @synthesize tutorialViewController=_tutorialViewController;
@property(retain) NSStoryboard *storyboard; // @synthesize storyboard=_storyboard;
@property(retain) DVTPageController *pageController; // @synthesize pageController=_pageController;
- (void)pageController:(id)arg1 didTransitionToObject:(id)arg2;
- (void)pageControllerDidEndLiveTransition:(id)arg1;
- (void)_ensureNavigationIsOnTop;
- (id)pageController:(id)arg1 viewControllerForIdentifier:(id)arg2;
- (id)pageController:(id)arg1 identifierForObject:(id)arg2;
- (id)init;
- (id)identifierForPageController;
- (id)identifiersForPagesInStoryboard;
@property(readonly) NSView *tutorialView;
- (void)previousPage;
- (void)nextPage;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

