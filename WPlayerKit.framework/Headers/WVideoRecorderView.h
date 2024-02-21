//
//  WVideoRecorderView.h
//  WPlayerKit
//
//  Created by List on 20/10/2023.
//  Copyright © 2023 List. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WVideoRecorderView : UIView

@property (nonatomic, assign) BOOL cropyuv;         /// 是否自定义宽高裁剪视频，默认为YES
@property (nonatomic, assign) NSInteger cropWidth;  /// 自定义裁剪视频的宽度，默认为480
@property (nonatomic, assign) NSInteger cropHeight; /// 自定义裁剪视频的高度，默认为640
@property (nonatomic, assign) NSInteger audioSampleRate; /// 音频采样率,默认16000,录制前设置才生效

/// 录制回调，取出视频后，注意要把沙盒路径里的文件清除，否则会一直堆积在沙盒里 [[NSFileManager defaultManager] removeItemAtPath:filePath error:nil];
@property (nonatomic, copy) void (^recordFinishBlock)(NSString *filePath);

/// 判断是否有相机采集权限
+ (BOOL)isAVCaptureAuthorization;

/// 判断是否有麦克风采集权限
+ (BOOL)isMicrophoneAuthorization;

/// 初始化视频采集引擎
/// - Parameter frame:CGRect
- (instancetype)initWithFrame:(CGRect)frame;

/// 前后置摄像头切换，默认后置摄像头
- (void)revertCamera;

/// 手电筒补光模式
- (void)setTorchMode:(AVCaptureTorchMode)torchMode;

/// 启动画面渲染
- (void)startRuning;

/// 暂停画面渲染
- (void)stopRuning;

/// 开始录制视频
/// - Parameter complete: 启动完成，开始倒计时
- (void)startRecorderVideoComplete:(void(^)(void))complete;

/// 结束录制视频
- (void)stopRecorderVideo;

@end

NS_ASSUME_NONNULL_END
