//
//  WVideoCaptureView.h
//  WPlayerKit
//
//  Created by List on 13/3/2023.
//  Copyright © 2023 List. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WCommonMacro.h"

NS_ASSUME_NONNULL_BEGIN

@interface WVideoCaptureView : UIView

/// 判断是否有相机采集权限
+ (BOOL)isAVCaptureAuthorization;

/// 挂断/拒绝接听
/// - Parameter device: 设备id
+ (void)rejectCallDeviceId:(NSString *)deviceId;

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


@end

NS_ASSUME_NONNULL_END
