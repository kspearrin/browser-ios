//
//  ODRefreshControl.h
//  ODRefreshControl
//
//  Created by Fabio Ritrovato on 6/13/12.
//  Copyright (c) 2012 orange in a day. All rights reserved.
//
// https://github.com/Sephiroth87/ODRefreshControl
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

@protocol ODRefreshControlContentView <NSObject>

@property (nonatomic,getter=isEnabled) BOOL enabled;
@property (nonatomic, strong) UIColor *tintColor;
@property (nonatomic, assign) UIActivityIndicatorViewStyle activityIndicatorViewStyle;
@property (nonatomic, strong) UIColor *activityIndicatorViewColor;

- (CGFloat)triggerHeight;
- (CGFloat)openHeight;

- (void)beginRefreshing:(BOOL)animated;
- (void)endRefreshing;

@end

@interface ODRefreshControl : UIControl

@property (nonatomic, readonly, getter=isRefreshing) BOOL refreshing;

#ifdef __IPHONE_5_0
@property (nonatomic, strong) UIColor *tintColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, assign) UIActivityIndicatorViewStyle activityIndicatorViewStyle UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *activityIndicatorViewColor UI_APPEARANCE_SELECTOR; // iOS5 or more
#else
@property (nonatomic, strong) UIColor *tintColor;
@property (nonatomic, assign) UIActivityIndicatorViewStyle activityIndicatorViewStyle;
@property (nonatomic, strong) UIColor *activityIndicatorViewColor; // iOS5 or more
#endif

- (id)initInScrollView:(UIView *)scrollView;

// use custom activity indicator
- (id)initInScrollView:(UIView *)scrollView activityIndicatorView:(UIView *)activity;

-(void)animate;

// Tells the control that a refresh operation was started programmatically
- (void)beginRefreshing;

// Tells the control the refresh operation has ended
- (void)endRefreshing;

@end
