//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"


@class NSString;

@interface DVTLocale : NSObject <NSCopying, NSCoding>
{
    NSString *_displayName;
    NSString *_localeIdentifier;
}

+ (id)localeWithLocaleIdentifier:(id)arg1;
+ (id)systemLanguages;
+ (id)availableLocales;
+ (id)globalLocale;
+ (id)baseLocale;
+ (id)autoupdatingCurrentLocale;
+ (id)currentLocale;
+ (id)_xcodeLocale;
+ (id)systemLocale;
@property(readonly) NSString *displayName; // @synthesize displayName=_displayName;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)arg1;
- (BOOL)isEqualToLocale:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)rootLanguage;
- (id)localeComponents;
@property(readonly) NSString *localeIdentifier;
- (id)description;
- (id)_initWithLocaleIdentifier:(id)arg1;
- (id)_initWithLocaleIdentifier:(id)arg1 displayName:(id)arg2;
- (id)init;

@end

