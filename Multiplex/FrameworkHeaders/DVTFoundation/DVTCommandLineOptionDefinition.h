//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class NSString;

@interface DVTCommandLineOptionDefinition : NSObject
{
    NSString *_name;
    NSString *_usageName;
    NSString *_usageDescription;
    long long _argumentType;
    NSString *_argumentKey;
    dispatch_block_t _handlerBlock;
}

+ (id)optionDefinitionWithName:(id)arg1 usageName:(id)arg2 usageDescription:(id)arg3 argumentType:(long long)arg4 argumentKey:(id)arg5 handlerBlock:(dispatch_block_t)arg6;
@property(copy) dispatch_block_t handlerBlock; // @synthesize handlerBlock=_handlerBlock;
@property(copy) NSString *argumentKey; // @synthesize argumentKey=_argumentKey;
@property long long argumentType; // @synthesize argumentType=_argumentType;
@property(copy) NSString *usageDescription; // @synthesize usageDescription=_usageDescription;
@property(copy) NSString *usageName; // @synthesize usageName=_usageName;
@property(copy) NSString *name; // @synthesize name=_name;
- (BOOL)handleArgument:(id)arg1 remainingArguments:(id)arg2 options:(id)arg3 status:(char *)arg4 error:(id *)arg5;
- (BOOL)matchesArgument:(id)arg1;
- (id)description;
- (id)initWithName:(id)arg1 usageName:(id)arg2 usageDescription:(id)arg3 argumentType:(long long)arg4 argumentKey:(id)arg5 handlerBlock:(dispatch_block_t)arg6;

@end

