//
//  WVideoCaptureView.h
//  WPlayerKit
//
//  Created by List on 13/3/2023.
//  Copyright © 2023 List. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WPlayerKit/WCommonMacro.h>

NS_ASSUME_NONNULL_BEGIN

@interface WVideoCaptureView : UIView

@property (nonatomic, assign) BOOL cropyuv;         /// 是否自定义宽高裁剪视频，默认为YES
@property (nonatomic, assign) NSInteger cropWidth;  /// 自定义裁剪视频的宽度
@property (nonatomic, assign) NSInteger cropHeight; /// 自定义裁剪视频的高度
@property (nonatomic, assign) NSInteger realFramerate; /// 实际帧率，SDK内部默认15帧

/// 判断是否有相机采集权限
+ (BOOL)isAVCaptureAuthorization;

/// 挂断/拒绝接听
/// - Parameter device: 设备id
+ (void)rejectCallDeviceId:(NSString *)deviceId;

/// 主动向设备发起呼叫
/// - Parameter deviceId: 设备id
/// - Parameter state: 0拒接，1接听，2通话中
/// - Parameter timeout: 超时时间，默认可传60s
/// - Parameter failure: 失败、超时等（不能为空）
+ (void)initiateCallDeviceId:(NSString *)deviceId timeout:(NSInteger)timeout complete:(void(^)(NSInteger state))complete failure:(void(^)(void))failure;

/// 初始化视频采集引擎
/// - Parameter frame:CGRect
/// - Parameter deviceId:设备id
/// - Parameter channel:通道号，默认0即可
/// - Parameter streamType:数据类型 WStreamTypeVideo 视频，默认传WStreamTypeVideo
- (instancetype)initWithFrame:(CGRect)frame deviceId:(NSString *)deviceId channel:(NSInteger)channel streamType:(WStreamType)streamType;
 
/// 前后置摄像头切换，默认前置摄像头
- (void)revertCamera;

/// 开始推流，传到设备端。注意：开启推流前需要打洞成功且加流
/// - Parameter complete: 是否成功
- (void)startPushStreamComplete:(void(^)(BOOL success))complete;

/// 结束推流
- (void)stopPushStream;

/// 开始采集，默认初始化采集器时无手机端预览，需要推流才有预览，如想一开始有预览，可以调用该方法
- (void)startCapture;

/// 停止采集
- (void)stopCapture;

@end

NS_ASSUME_NONNULL_END
