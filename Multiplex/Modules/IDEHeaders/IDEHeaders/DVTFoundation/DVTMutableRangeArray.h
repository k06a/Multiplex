//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@interface DVTMutableRangeArray : NSMutableArray
{
    unsigned long long _count;
    unsigned long long _capacity;
    struct _NSRange *_ranges;
}

+ (void)initialize;
- (void)sort;
- (void)normalize;
- (void)replaceRangeAtIndex:(unsigned long long)arg1 withRange:(struct _NSRange)arg2;
- (void)removeAllRanges;
- (void)removeRangesAtIndexes:(id)arg1;
- (void)removeRangeAtIndex:(unsigned long long)arg1;
- (void)insertRange:(struct _NSRange)arg1 atIndex:(unsigned long long)arg2;
- (void)addRange:(struct _NSRange)arg1;
- (void)setRange:(struct _NSRange)arg1 atIndex:(unsigned long long)arg2;
- (unsigned long long)indexOfRangeContainingOrFollowing:(unsigned long long)arg1;
- (unsigned long long)indexOfRangeContainingOrPreceding:(unsigned long long)arg1;
- (unsigned long long)indexOfRangeFollowing:(unsigned long long)arg1;
- (unsigned long long)indexOfRangePreceding:(unsigned long long)arg1;
- (struct _NSRange)lastRange;
- (struct _NSRange)firstRange;
- (unsigned long long)indexOfRange:(struct _NSRange)arg1;
- (struct _NSRange)rangeAtIndex:(unsigned long long)arg1;
- (void)replaceObjectAtIndex:(unsigned long long)arg1 withObject:(id)arg2;
- (void)removeObjectAtIndex:(unsigned long long)arg1;
- (void)removeLastObject;
- (void)insertObject:(id)arg1 atIndex:(unsigned long long)arg2;
- (void)addObject:(id)arg1;
- (id)objectAtIndex:(unsigned long long)arg1;
- (unsigned long long)count;
- (id)descriptionWithLocale:(id)arg1;
- (id)mutableCopyWithZone:(struct _NSZone *)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (BOOL)isEqualToArray:(id)arg1;
- (unsigned long long)hash;
- (void)dealloc;
- (id)init;
- (id)initWithRanges:(const struct _NSRange *)arg1 count:(unsigned long long)arg2;
- (id)initWithObjects:(const id *)arg1 count:(unsigned long long)arg2;
- (id)initWithCapacity:(unsigned long long)arg1;

@end
