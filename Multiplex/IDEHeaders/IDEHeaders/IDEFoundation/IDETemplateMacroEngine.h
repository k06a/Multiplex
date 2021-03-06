//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class NSMutableDictionary;

@interface IDETemplateMacroEngine : NSObject
{
    NSMutableDictionary *_macroSubstitutions;
}

+ (id)standardSubstitutionsForMacrosWithWorkspaceName:(id)arg1 projectName:(id)arg2 packageName:(id)arg3 targetName:(id)arg4 productName:(id)arg5 fileName:(id)arg6 organizationName:(id)arg7;
+ (id)substitutionsForMacrosWithWorkspaceName:(id)arg1 projectName:(id)arg2 packageName:(id)arg3 targetName:(id)arg4 productName:(id)arg5 fileName:(id)arg6;
+ (id)multiSubstitutionsForSubstitution:(id)arg1 forMacro:(id)arg2;
- (void)setMultiSubstitution:(id)arg1 forMacro:(id)arg2;
- (BOOL)createFileAtURL:(id)arg1 usingEncoding:(unsigned long long)arg2 substitutingMacrosInFileAtURL:(id)arg3 error:(id *)arg4;
- (id)stringBySubstitutingMacrosInString:(id)arg1;
- (id)allMacros;
- (void)setSubstitutionsForMacros:(id)arg1;
- (id)substitutionForMacro:(id)arg1;
- (void)setSubstitution:(id)arg1 forMacro:(id)arg2;
- (id)init;

@end

