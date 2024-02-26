//
//  WZoomSuperView.h
//  WPlayerKit
//
//  Created by List on 24/11/2022.
//  Copyright © 2022 List. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZDKPlayVideoView.h"
#import "WCommonMacro.h"

NS_ASSUME_NONNULL_BEGIN

@interface WZoomSuperView : UIView

/***
 如果其它view挡住zoomView的手势，请在view类中重写下面方法即可
 - (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event {
     UIView *responeView = [super hitTest:point withEvent:event];
     if([responeView isKindOfClass:[UIButton class]]){
         return responeView;
     }
     return nil;
 }
 ***/

/// 传入播放器，使播放器具备缩放功能
- (instancetype)initWithPlayVideoView:(ZDKPlayVideoView *)playView;
 
@property (nonatomic, weak) ZDKPlayVideoView *playView;

/// 单击事件回调
@property (nonatomic, copy) void(^tapClickAction)(WZoomSuperView *view);
 
/// 开始滑动、上下左右
@property (nonatomic, copy) void(^startRollAction)(WZoomSuperView *view,WPTZDirection direction);

/// 结束滑动
@property (nonatomic, copy) void(^endRollAction)(WZoomSuperView *view);

/// 回调，1是放大，0是缩小
@property (nonatomic, copy) void(^tureSetCameraZoomBlock)(NSInteger indexType);

/// 清空缩放状态，恢复到默认状态
- (void)resetZoomSuperZero;

/// 用于真实让设备放大缩小的方法, 跟tureSetCameraZoomBlock 配套使用的，一般是用于真实控制设备摄像头变焦，而不是view的缩放，目前设备不支持，该接口为以后预留
- (void)tureSetCameraZoom;

/// 是否支持滑动回调startRollAction，一般用于云台控制
/// - Parameter support: 初始化类时默认支持，不支持可传NO
- (void)supportStartRollAction:(BOOL)support;

@end

NS_ASSUME_NONNULL_END
