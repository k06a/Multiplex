//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@interface IDEMediaRangeValue : NSObject
{
    double _minValue;
    BOOL _minIsInclusive;
    double _maxValue;
    BOOL _maxIsInclusive;
}

+ (id)rangeWithMinimumValue:(double)arg1 inclusive:(BOOL)arg2 andMaximumValue:(double)arg3 inclusive:(BOOL)arg4;
- (long long)compare:(id)arg1;
- (id)description;
- (BOOL)isEqual:(id)arg1;
- (BOOL)matchesValue:(double)arg1;
- (id)initWithMinimumValue:(double)arg1 inclusive:(BOOL)arg2 andMaximumValue:(double)arg3 inclusive:(BOOL)arg4;

@end

