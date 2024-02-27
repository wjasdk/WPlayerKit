//
//  WCommonVideoPlayer.h
//  WPlayerKit
//
//  Created by chenlei on 2022/10/10.
//  Copyright © 2022 List. All rights reserved.
//

#import "ZDKPlayVideoView.h"
#import "Server.h"
#import "WCommonMacro.h"
#import "MediaCallBackDelegate.h"
#import "WMediaControl.h"

NS_ASSUME_NONNULL_BEGIN

@interface WVideoPlayView : ZDKPlayVideoView

/// 创建播放器
/// @param frame 宽高大小
/// @param deviceId 设备ID
- (instancetype)initWithFrame:(CGRect)frame deviceId:(NSString *)deviceId;

#pragma mark ------------------------ P2P直播、卡回放相关操作方法 ----------------------------------

/// 播放直播视频采用p2p，打开音频流、视频流均调用此方法
/// @param devicePwd 设备密码(默认是123456)
/// @param channel 通道(默认为0)
/// @param streamType 需要打开的音视频流
/// @param isWakeUp 是否需要唤醒，用于门锁、猫眼、可视门铃等，一般摄像机传NO
- (void)playVideoByP2PDevicePwd:(NSString *)devicePwd channel:(int)channel streamType:(WStreamType)streamType isWakeUp:(BOOL)isWakeUp completion:(void(^)(BOOL isSuc,NSString *deviceId,long playId,WCommonStreamStates state))compltion;


/// 播放TF卡回放视频
/// @param devicePwd 设备密码 (默认是123456)
/// @param channel 通道(默认为0)
/// @param fileName 文件名称
/// @param version tf版本 0：旧   1：新,  tfInfo中的tf_version
/// @param time time
/// @param completion 回调
/// @param totoalTimeHandel 回调
/// @param timeHandle 回调 int currentTime  = [weakSelf.current_fileModel.file_start_time intValue] + current/1000; NSString *rulerValue = [Util stGetTimeFromTimesTamp:currentTime model:@"HH:mm:ss"];
- (void)playVideoByP2PDevicePwd:(NSString *)devicePwd channel:(int)channel fileName:(NSString *)fileName version:(NSInteger)version time:(NSInteger)time completion:(void(^)(BOOL isSuc))completion totoalTimeHandel:(void(^)(NSTimeInterval totoal))totoalTimeHandel timeHandle:(void(^)(NSTimeInterval current))timeHandle;


/// 播放TF卡回放视频(优化版本，推荐)
/// @param devicePwd 设备密码 (默认是123456)
/// @param channel 通道(默认为0)
/// @param startTime 开始时间
/// @param endTime 结束时间
/// @param completion 回调
/// @param timeHandle 回调
- (void)playVideoByP2PDevicePwd:(NSString *)devicePwd startTime:(NSInteger)startTime endTime:(NSInteger)endTime channel:(int)channel completion:(void(^)(BOOL isSuc))completion timeHandle:(void(^)(NSInteger current))timeHandle;
 

/// 播放TF事件告警视频
/// @param devicePwd 设备密码 (默认是123456)
/// @param startTime 文件开始时间点
/// @param endTime 文件结束时间点
/// @param completion 回调
/// @param totoalTimeHandel 回调
/// @param timeHandle 回调
-(void)playEventRecordVideoDevicePwd:(NSString *)devicePwd startTime:(NSInteger)startTime endTime:(NSInteger)endTime channel:(int)channel completion:(void(^)(BOOL isSuc))completion totoalTimeHandel:(void(^)(NSTimeInterval totoal))totoalTimeHandel timeHandle:(void(^)(NSTimeInterval current))timeHandle;

  
/// TF回放视频倍数播放
/// @param speed 快放倍数 1、4、8、16; 1倍 4倍 8倍 16倍
-(void)playTFMultiplesSpeed:(int)speed;


/// rtmp倍数播放
/// @param speed 倍数 0.5、1、2、4、8
- (void)playRTMPMultipleSpeed:(float)speed;


/// 播放时进行视频录制
/// @param recordSwitch YES:开始录制 NO:结束录制
/// @param duration 时长(max:300s  min:5s)
/// @param channel 通道(默认为0)
/// @param operationType 操作类型，直播/TF卡回放时：WOperationP2P；云回放/告警时：WOperationRTMP
/// @param progress 进度
/// @param completion 回调
- (void)playRecordVideoOnOff:(BOOL)recordSwitch duration:(NSInteger)duration channel:(NSInteger)channel operationType:(WOperationType)operationType progress:(void(^_Nonnull)(NSString *_Nonnull timeStr,int timeCount))progress completion:(void(^_Nullable)(BOOL isSuc,NSString *_Nullable errInfo,NSString *_Nullable path))completion;


/// 销毁直播、卡回放视频，关闭播放器
- (void)stopVideoP2P;


/// 播放暂停(仅限于卡回放)
- (void)playVideoPauseP2P;


/// 暂停后恢复播放(仅限于卡回放)
- (void)playVideoResumeP2P;


/// 是否打开声音（加音频流）
/// @param isOpen  是否打开
/// @param completion 回调
- (void)setIsOpenAudio:(BOOL)isOpen completion:(void(^_Nullable)(BOOL isSuc))completion;


/// P2P播放器是否静音
/// @param mute  是否静音
- (void)setP2PVideoMute:(BOOL)mute;


/// 播放截图(适用于P2P,RTMP)
/// @param screenShotPathType 截图类型
/// @param channel 通道(默认为0)
/// @param completion 回调
- (void)playVideoScreenshot:(WOperationType)screenShotPathType channel:(NSInteger)channel completion:(void(^)(BOOL isSuc,NSString *path))completion;


/// 用于获取当前是否正在播放中
/// @param channel 通道(默认为0)
/// @param type StreamType
- (BOOL)isPlayingChannel:(NSInteger)channel streamType:(WStreamType)type;


/// 用于获取当前视频是否进行了暂停操作，通常用于录播（普通视频文件）
- (BOOL)isPause;


/// 云台控制
/// @param direction 方向枚举
/// @param complete 返回成功或失败
- (void)ptzDirection:(WPTZDirection)direction complete:(void(^)(BOOL isSuccess))complete;
 

/// 获取当前设备的分辨率
/// @param complete 返回成功或失败，分辨率枚举
- (void)getVideoQualityComplete:(void(^)(BOOL isSuccess, WVideoQuality quality))complete;


/// 切换当前设备的分辨率
/// @param videoQuality 分辨率枚举
/// @param complete 返回成功或失败
- (void)setVideoQuality:(WVideoQuality)videoQuality complete:(void(^)(BOOL isSuccess))complete;


/// 开启对讲
/// @param sampleRate  音频采样率
/// @param fullDuplex  是否进行全双工呼叫，默认传是
- (void)startSpeakerWithSampleRate:(NSInteger)sampleRate fullDuplex:(BOOL)fullDuplex;
 

/// 关闭对讲
- (void)endSpeaker;


#pragma mark ----------------------------- RTMP云回放、告警播放相关操作方法 -------------------------------

/// 播放视频，采用RTMP
/// @param url 播放地址
/// @param startTime 开始时间 没有就传0
/// @param endTime 结束时间  没有就传0
/// @param completion 回调
/// @param playProgressBlock 回调
/// @param completionZDKCallBackEvent 回调
- (void)playVideoByRTMP:(NSString *_Nonnull)url startTime:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime completion:(void(^_Nonnull)(BOOL isSuc))completion playProgressBlock:(void(^_Nonnull)(NSInteger playTime))playProgressBlock completionZDKCallBackEvent:(void (^ _Nonnull)(ZDKCallBackEvent))completionZDKCallBackEvent;


/// 播放视频，采用RTMP
/// @param url 播放地址
- (void)playVideoByRTMP:(NSString *)url completionZDKCallBackEvent:(void(^_Nonnull)(ZDKCallBackEvent callBack))completionZDKCallBackEvent;
 

/// RTMP播放器是否静音（声音开启跟关闭）
/// @param mute  是否静音
- (void)setRTMPVideoMute:(BOOL)mute;
 

/// RTMP-停止播放，并销毁
- (void)playVideoStopRTMP;

/// 播放暂停(适用于RTMP)
- (void)playVideoPauseRTMP;

/// 暂停后恢复播放(适用于RTMP)
- (void)playVideoResumeRTMP;

/// 更改播放进度(适用于RTMP)
/// @param position 播放进度,第几秒，比如第10秒就传10
- (void)changePlayPositionRTMP:(int)position completion:(void(^)(BOOL isSuc))completion;

@end

NS_ASSUME_NONNULL_END
