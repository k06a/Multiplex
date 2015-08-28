//
//  DVTSourceTextView+MPXEditorClipboardSupport.m
//  Multiplex
//
//  Created by Kolin Krewinkel on 8/26/15.
//  Copyright © 2015 Kolin Krewinkel. All rights reserved.
//

#import "DVTSourceTextView+MPXEditorSelectionVisualization.h"

@import MPXSelectionCore;

@implementation DVTSourceTextView (MPXEditorSelectionVisualization)
@synthesizeAssociation(DVTSourceTextView, mpx_textViewSelectionDecorator);

- (void)mpx_viewWillMoveToWindow:(NSWindow *)window
{
    [self mpx_viewWillMoveToWindow:window];

    // Observe the window's state while the view resides in it
    if (window) {
        [[NSNotificationCenter defaultCenter] addObserver:self.mpx_textViewSelectionDecorator
                                                 selector:@selector(startBlinking)
                                                     name:NSWindowDidBecomeKeyNotification
                                                   object:window];

        [[NSNotificationCenter defaultCenter] addObserver:self.mpx_textViewSelectionDecorator
                                                 selector:@selector(stopBlinking)
                                                     name:NSWindowDidResignKeyNotification
                                                   object:window];
    } else {
        [[NSNotificationCenter defaultCenter] removeObserver:self name:NSWindowDidBecomeKeyNotification object:nil];
        [[NSNotificationCenter defaultCenter] removeObserver:self name:NSWindowDidResignKeyNotification object:nil];
    }
}

- (void)_drawInsertionPointInRect:(CGRect)rect color:(NSColor *)color
{
    // Intentionally no-op to prevent display of the original insertion point.
}

@end
