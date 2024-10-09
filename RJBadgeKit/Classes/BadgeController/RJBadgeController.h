//
//  RJBadgeController.h
//  RJBadgeKit
//
//  Created by Ryan Jin on 06/12/2017.
//

#import <Foundation/Foundation.h>
#import "RJBadgeView.h"
#import "RJBadge.h"

#ifndef RJBadgeKeyPath
#define RJBadgeKeyPath(KEYPATH) \
        @(((void)(NO && ((void)KEYPATH, NO)), strchr(#KEYPATH, '.') + 1))
#endif

#ifndef RJBadgeClassKeyPath
#define RJBadgeClassKeyPath(CLASS, KEYPATH) \
        @(((void)(NO && ((void)((CLASS *)(nil)).KEYPATH, NO)), #KEYPATH))
#endif

NS_ASSUME_NONNULL_BEGIN

extern NSString * const RJBadgePathKey;
extern NSString * const RJBadgeCountKey;
extern NSString * const RJBadgeShowKey;

typedef void (^RJBadgeNotificationBlock)(id observer, NSDictionary<NSString *, id> *info);

NS_SWIFT_NAME(BadgeController)
@interface RJBadgeController<Observer> : NSObject

/**
 The observer notified on badge change. Specified on initialization.
 */
@property (nullable, nonatomic, weak, readonly) Observer observer;

#pragma mark - Initialize

+ (instancetype)controllerWithObserver:(nullable Observer)observer;

- (instancetype)initWithObserver:(nullable Observer)observer NS_DESIGNATED_INITIALIZER;

/**
 @abstract Initializes a new instance.
 @warning  This method is unavaialble. Use 'initWithObserver:' instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 @abstract Initializes a new instance.
 @warning  This method is unavaialble. Use 'initWithObserver:' instead.
 */
- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Observe

- (void)observePath:(NSString *)keyPath block:(void (^ _Nullable)(Observer observer, NSDictionary<NSString *, id> *info))block;

- (void)observePath:(NSString *)keyPath badgeView:(nullable id<RJBadgeView>)badgeView block:(void (^_Nullable)(Observer observer, NSDictionary<NSString *, id> *info))block;

- (void)observePaths:(NSArray<NSString *> *)keyPaths block:(void (^_Nullable)(Observer observer, NSDictionary<NSString *, id> *info))block;

#pragma mark - Unobserve

- (void)unobservePath:(NSString *)keyPath;

- (void)unobserveAll;

#pragma mark - Operation

/**
 refresh all badge views associated with current -observer,
 aim to deal with situations / issue linked to auto-layout,
 e.g. set 'setBadgeForKeyPath' when layout hasn't done yet.
 */
- (void)refreshBadgeView;

+ (void)setBadgeForKeyPath:(NSString *)keyPath;
+ (void)setBadgeForKeyPath:(NSString *)keyPath count:(NSUInteger)count;

+ (void)clearBadgeForKeyPath:(NSString *)keyPath;
+ (void)clearBadgeForKeyPath:(NSString *)keyPath forced:(BOOL)forced;

+ (BOOL)statusForKeyPath:(NSString *)keyPath;

+ (NSUInteger)countForKeyPath:(NSString *)keyPath;

@end

NS_ASSUME_NONNULL_END
