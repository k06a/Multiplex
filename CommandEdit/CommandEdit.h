//
//  CommandEdit.h
//  CommandEdit
//
//  Created by Kolin Krewinkel on 3/9/14.
//  Copyright (c) 2014 Kolin Krewinkel. All rights reserved.
//

#import <AppKit/AppKit.h>

@interface CommandEdit : NSObject

+ (instancetype)sharedPlugin;

- (BOOL)pluginEnabled;

@end