//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <DVTFoundation/DVTSourceFileCodeCoverageRange.h>

@interface DVTSourceFileCodeCoverageCoveredRange : DVTSourceFileCodeCoverageRange
{
    int _executionCount;
}

- (int)executionCount;
- (BOOL)isExecutable;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithLine:(unsigned long long)arg1 column:(unsigned long long)arg2 length:(unsigned long long)arg3 executionCount:(int)arg4;

@end

