//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <DVTFoundation/DVTSourceScanner.h>

@interface DVTPythonScanner : DVTSourceScanner
{
}

- (long long)parseOneIncludedRule:(id)arg1 inTree:(id)arg2 withContext:(id)arg3 initialToken:(long long)arg4 inputStream:(id)arg5 range:(struct _NSRange)arg6 dirtyRange:(struct _NSRange *)arg7 isLexing:(BOOL)arg8 reusedToken:(char *)arg9;
- (void)computeContext:(id)arg1 inString:(id)arg2 forLocation:(unsigned long long)arg3;
- (unsigned long long)nextIndentForlocation:(unsigned long long)arg1 inString:(id)arg2;
- (long long)_indentForLineWithRange:(struct _NSRange)arg1 inString:(id)arg2;

@end
