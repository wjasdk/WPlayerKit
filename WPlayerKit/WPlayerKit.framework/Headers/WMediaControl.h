//
//  WMediaControl.h
//  WPlayerKit
//
//  Created by List on 11/10/2022.
//  Copyright © 2022 List. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WCommonMacro.h"
#import "WCommonLink.h"
#import "Server.h"
#import "ZDKMediaCallBack.h"
#import "ZDKSpeakerVoice.h"

NS_ASSUME_NONNULL_BEGIN

@class ZDKPlayVideoView;

typedef void(^WMediaResultBlock)(BOOL isSuc,NSString *_Nullable deviceId,NSString *_Nullable connectType);
 
@interface WMediaControl : NSObject

/// 收到该回调，需要重新加载视频。前后台切换及网络变化时会回调该block
@property (nonatomic, copy) void(^_Nullable baseMediaStatusChangeReloadPlayCallback)(void);

/// 音视频方面的枚举回调，可根据不同回调来实现不同的业务逻辑，具体根据不同场景考虑用不用
@property (nonatomic, copy) void(^_Nullable baseMediaEventCallBack)(ZDKCallBackEvent callBack, NSString *deviceId, NSString *playId, NSDictionary *useInfo);

/// 是否正在对讲
@property (nonatomic, assign) BOOL isSpeaking;

/// 打洞鉴权的IoT用户Token，由sdkLogin时传入
@property (nonatomic, copy, readonly) NSString *authToken;

/// 单利方法
+ (instancetype _Nonnull)sharedControl;

/// 初始化SDK
- (void)initSDKWithServer:(Server *_Nonnull)server;

/// 登录SDK、初始化消息模块、初始化服务器请求模块
/// @param token 用户token
- (void)sdkLoginWithToken:(NSString *)token;

/// 退出登录
- (void)sdkLogout;

/// P2P打洞 建立设备连接（预打洞）
/// @param deviceId 设备id
- (void)readyConnectP2PWithDeviceId:(NSString *_Nonnull)deviceId;

/// P2P打洞 判断当前是否P2P连接建立成功，如果没有建立就尝试去建立
/// @param deviceId 设备id
/// @param completion 操作完成之后回调 link对象
- (void)connectIfNeedWithDeviceId:(NSString *_Nullable)deviceId completion:(void(^_Nullable)(WCommonLink *_Nullable link))completion;

/// 关闭所有p2p连接
- (void)closeAllLinkWithEvent:(WCommonLinkiInterruptEvent)event;

/// 断开与设备的连接
/// @param deviceId 设备id
/// @param compltion 操作完成回调   isSuc操作是否成功
- (void)closeLinkWithDeviceId:(NSString *_Nonnull)deviceId completion:(void(^_Nullable)(BOOL isSuc))compltion;
 
/// 添加视频流
/// @param deviceId 设备id
/// @param playView 渲染载体
/// @param channel 通道编号
/// @param type 流类型
/// @param isplay 是否是直播 YES 直播 NO录播
/// @param compltion 操作完成回调
- (void)addVideoStreamWithDeviceId:(NSString *_Nonnull)deviceId devicePwd:(NSString *_Nullable)devicePwd playView:(ZDKPlayVideoView *_Nonnull)playView channel:(long)channel type:(WStreamType)type isPlay:(BOOL)isplay completion:(void(^_Nullable)(BOOL isSuc,NSString *_Nullable deviceId,long playId,WCommonStreamStates state))compltion;
 
/// 添加音频流
/// @param deviceId 设备id
/// @param compltion 操作完成回调
/// @param isplay 是否是直播 YES 直播 NO录播
- (void)addAudioStreamWithDeviceId:(NSString *_Nonnull)deviceId devicePwd:(NSString *_Nullable)devicePwd channel:(long)channel isPlay:(BOOL)isplay completion:(void(^_Nullable)(BOOL isSuc,NSString *_Nullable deviceId,long playId,WCommonStreamStates state))compltion;
 
/// RTMP云回放播放
/// @param url   地址
/// @param start 开始时间
/// @param end   结束时间
/// @param playView 播放载体
/// @param completion 回调函数
- (void)playWithUrl:(NSString *_Nonnull)url startTimeTemp:(NSTimeInterval)start end:(NSTimeInterval)end playView:(ZDKPlayVideoView *_Nonnull)playView completion:(void(^_Nonnull)(BOOL isSuc))completion playProgressBlock:(void(^_Nonnull)(NSInteger playTime))playProgressBlock completionZDKCallBackEvent:(void (^ _Nonnull)(ZDKCallBackEvent callBack))completionZDKCallBackEvent;

/// RTMP 停止播放（关闭播放器）
- (void)stopCloudPlay;

/// RTMP 恢复播放
- (void)resumCloudPlay;

/// RTMP 暂停播放
- (void)pauseCloudPlay;
 
/// 播放RTMP，可用于告警、本地沙盒文件播放
/// @param url 地址
/// @param playView view
/// @param completionZDKCallBackEvent 回调的枚举
- (void)playWithUrl:(NSString *_Nonnull)url playView:(ZDKPlayVideoView *_Nonnull)playView completionZDKCallBackEvent:(void(^_Nonnull)(ZDKCallBackEvent callBack))completionZDKCallBackEvent;


/// 告警、云存储 TS文件下载
/// @param urlPath 播放地址
/// @param sandboxPath 要存储的沙盒地址（下载视频的目标地址）
/// @param videoDuration 文件总时长
/// @param resultCallback 返回成功或者失败，一般失败是如下几个原因：地址错误、该地址无数据、地址过期、文件太大下载超时等等
- (void)startTsToMp4FileUrlPath:(NSString *)urlPath sandboxPath:(NSString *)sandboxPath videoDuration:(int)videoDuration resultCallback:(void(^)(BOOL isSuccess))resultCallback;


/// 取消TS文件下载
- (void)cancelTsToMp4File;

 
/// 添加播放过程中流的数据监听，播放过程中任何流的状态变化都会触发
/// 一般情况下，关注 WCommonLinkiInterruptEvent 就能满足绝大部分需求，ZDKCallBackEvent 是具体的原因
/// @param deviceId 设备号
/// @param handle 回调函数
- (void)interruptListenerWithDeviceId:(NSString *_Nonnull)deviceId handle:(void(^_Nullable)(WCommonLinkiInterruptEvent event, ZDKCallBackEvent callBack, WCommonStreamStates states, NSString * _Nonnull playId))handle;
 

/// 删除该设备号下所有流
/// @param deviceId 设备号
/// @param compltion 操作完成回调
- (void)deleteAllStreamWithDeviceId:(NSString *_Nonnull)deviceId completion:(void(^_Nullable)(BOOL isSuc))compltion;
 
/// 删除该设备号对应通道号下视频流或者音频流
/// @param deviceId 设备号
/// @param channel 通道号
/// @param type 流类型
/// @param compltion 操作完成回调
- (void)deleteStreamWithDeviceId:(NSString *_Nonnull)deviceId channel:(NSInteger)channel type:(WStreamType)type completion:(void(^_Nullable)(BOOL isSuc))compltion;
  
/// 删除音频流
/// @param deviceId 设备号
/// @param channel 通道号
/// @param compltion 操作完成回调
- (void)deleteAudioStreamWithDeviceId:(NSString *_Nonnull)deviceId channel:(long)channel completion:(void(^_Nullable)(BOOL isSuc))compltion;
 
/// p2p静音，主要卡回放
/// @param enable 是否静音
- (void)p2pMuteControlEnable:(BOOL)enable;
 
/// RTMP静音，主要云回放
/// @param enable 是否静音
- (void)rtmpMuteControlEnable:(BOOL)enable;
 
/// 对讲初始化
/// @param deviceId 设备ID
/// @param sampleRate 音频采集率
/// @param isPad 是否是中控iPad（摄像机、门锁这些传NO）
/// @return 对讲对象
- (ZDKSpeakerVoice *_Nullable)speakerWithDeviceId:(NSString *_Nullable)deviceId SampleRate:(NSInteger)sampleRate isPad:(BOOL)isPad;
 
/// 开启对讲
- (void)startSpeaker;

/// 开启对讲
/// @param sampleRate  音频采样率
/// @param fullDuplex  是否进行全双工呼叫，默认是
- (void)startSpeakerWithSampleRate:(NSInteger)sampleRate fullDuplex:(BOOL)fullDuplex;
 
/// 关闭对讲
- (void)endSpeaker;
 
/// @param duration 视频总时长 录制时间达到总时长则保存视频并finish <0的数，默认为5*60s
/// @param deviceId 设备ID
/// @param channel 通道号
/// @param operationType 操作类型，直播/TF卡回放时：WOperationP2P；云回放/告警时：WOperationRTMP
/// @param progress 进度回调  timeStr录制时间字符串mm:ss
/// @param finish   完成录制（到指定时间）回调  path完成录制视频的保存路径
- (void)beginRecordWithDuration:(long)duration deviceId:(NSString *_Nullable)deviceId channel:(NSInteger)channel isLive:(BOOL)isLive operationType:(WOperationType)operationType progress:(void(^_Nonnull)(NSString *_Nonnull timeStr,int timeCount))progress finish:(void(^_Nullable)(NSString *_Nullable path))finish;
 
/// 手动结束录制
/// @params minDuration 最小时长 录制时间小于minDuration 则录制失败
/// @param deviceId 设备ID
/// @param channel 通道号
/// @param operationType 操作类型，直播/TF卡回放时：WOperationP2P；云回放/告警时：WOperationRTMP
/// @param completion   操作成功并保存后回调  path完成录制视频的保存路径
- (void)endRecordMinDuration:(long)minDuration deviceId:(NSString *_Nullable)deviceId channel:(NSInteger)channel isLive:(BOOL)isLive operationType:(WOperationType)operationType completion:(void(^_Nullable)(BOOL isSuc,NSString *_Nullable errInfo,NSString *_Nullable path))completion;
 
/// 截图
/// @param deviceId 设备ID
/// @param channel 通道号
/// @param screenShotPathType 操作类型 P2P或者RTMP
/// @param completion   操作成功并保存后回调  path完成录制视频的保存路径
- (void)screenShotWithDeviceId:(NSString *_Nullable)deviceId screenShotPathType:(WOperationType)screenShotPathType channel:(NSInteger)channel completion:(void(^_Nullable)(BOOL isSuc,NSString *_Nullable path))completion;
 
/// 获取TF卡信息
/// @param deviceId 设备id
/// @param channel 通道号
/// @param devicePwd 设备密码，默认传123456即可
/// @param comepletion 成功后回调
- (void)getTfInfoWithDeviceId:(NSString *_Nullable)deviceId channel:(NSInteger)channel devicePwd:(NSString *_Nullable)devicePwd completion:(void(^_Nullable)(NSDictionary * _Nullable tfInfoDic,WCommonStreamStates state))comepletion;
 
/// 根据设备标识获取设备的连接和加流状态
/// @param deviceId 设备号
/// @param channel 通道号
/// @param type 流类型@return 设备连接状态
- (WP2PCommonLinkState)linkStatesWithDeviceId:(NSString *_Nullable)deviceId channel:(long)channel type:(WStreamType)type;

/// 获取p2p链接
/// @param deviceId 设备号
- (WCommonLink *_Nonnull)linkWithDeviceId:(NSString *)deviceId;

/// 播放TF回放视频
/// @param deviceId 设备号
/// @param channel 通道号
/// @param devicePwd 设备密码 默认123456
/// @param fileName 文件名
/// @param version tf版本，从tf信息获取
/// @param time 从此时间点播起
/// @param completion 成功与失败
/// @param totoalTimeHandel 总时间点
/// @param timeHandle  当前时间点
- (void)playBackWithDeviceId:(NSString *)deviceId channel:(int)channel devicePwd:(NSString *)devicePwd fileName:(NSString *)fileName version:(NSInteger)version playView:(ZDKPlayVideoView *_Nullable)playView time:(NSInteger)time completion:(void(^)(BOOL isSuc))completion totoalTimeHandel:(void(^)(NSTimeInterval totoal))totoalTimeHandel timeHandle:(void(^)(NSTimeInterval current))timeHandle;


/// 播放TF回放视频（优化版本，推荐使用）
/// @param deviceId 设备号
/// @param startTime 开始时间
/// @param endTime 结束时间
/// @param channel 通道号
/// @param devicePwd 设备密码 默认123456
/// @param completion 成功与失败 
/// @param timeHandle  当前时间点
- (void)playBackWithDeviceId:(NSString *)deviceId channel:(int)channel devicePwd:(NSString *)devicePwd startTime:(NSInteger)startTime endTime:(NSInteger)endTime playView:(ZDKPlayVideoView *_Nullable)playView completion:(void(^)(BOOL isSuc))completion timeHandle:(void(^)(NSInteger current))timeHandle;


/**
 播放TF事件告警视频
 @param deviceId 设备id
 @param startTime 文件开始时间点
 @param endTime 文件结束时间点
 */
-(void)playEventVideoWithDeviceId:(NSString*)deviceId devicePwd:(NSString *)devicePwd startTime:(NSInteger)startTime endTime:(NSInteger)endTime andWithPlayView:(ZDKPlayVideoView*)playView channel:(int)channel completion:(void(^)(BOOL isSuc))completion totoalTimeHandel:(void(^)(NSTimeInterval totoal))totoalTimeHandel timeHandle:(void(^)(NSTimeInterval current))timeHandle;


/**
 TF回放视频倍数播放
 @param deviceId 设备id
 @param speed 快放倍数 1、4、8、16; 1倍 4倍 8倍 16倍
 */
-(void)tfMultiplesWithDeviceId:(NSString*)deviceId speed:(int)speed playView:(ZDKPlayVideoView*)playView chnannel:(NSInteger)chnannel;



/// rtmp倍数播放
/// @param speed 0.5、1、2、4、8
- (void)rtmpMultipleSpeed:(float)speed;

 
/// 搜索SD卡视频文件列表
/// @param deviceId deviceId
/// @param start 开始时间  时间戳
/// @param end   结束时间  时间戳
/// @param fileType 0录播视频 1告警视频
/// @param version tf版本
/// @param channel 通道编号
/// @param completion 文件信息字典
- (void)searchGetTFRemoteFileWithDeviceId:(NSString *_Nonnull)deviceId channel:(int)channel devicePwd:(NSString *)devicePwd start:(NSString *)start end:(NSString *)end fileType:(int)fileType version:(NSInteger)version comepltion:(void(^_Nullable)(NSMutableArray *tfFileList,WCommonStreamStates state))completion;


/// 获取某个时间段内有哪几天存在视频文件
/// @param deviceId deviceId
/// @param channel 通道编号
/// @param devicePwd 设备密码 默认123456
/// @param start 开始时间  时间戳
/// @param end   结束时间  时间戳
/// @param fileType 0录播视频 1告警视频
/// @param completion 文件信息字典
- (void)getWhichDayStorageFileWithDeviceId:(NSString *_Nonnull)deviceId channel:(int)channel devicePwd:(NSString *)devicePwd start:(NSString *)start end:(NSString *)end fileType:(int)fileType comepltion:(void(^_Nullable)(NSMutableArray *timeList))completion;

/// 停止播放tf卡回放，重新播要重新Play
/// @param deviceId 设备id
/// @param channel 通道编号
- (void)stopPlayBackWithDeviceId:(NSString *_Nullable)deviceId channel:(int)channel playView:(ZDKPlayVideoView *_Nullable)playView completion:(void(^_Nullable)(BOOL isSuc))completion;

/// tf卡视频恢复播放
/// @param deviceId 设备id
/// @param channel 通道编号
- (void)resumPlayBackWithDeviceId:(NSString *_Nonnull)deviceId channel:(int)channel playView:(ZDKPlayVideoView *_Nonnull)playView completion:(void(^_Nonnull)(BOOL isSuc))completion;

/// tf视频暂停播放
/// @param deviceId 设备id
/// @param channel 通道编号
- (void)pausePlayBackWithDeviceId:(NSString *_Nonnull)deviceId channel:(int)channel playView:(ZDKPlayVideoView *_Nonnull)playView completion:(void(^_Nonnull)(BOOL isSuc))completion;

/// 指定时间点播放
/// @param deviceId 设备id
/// @param channel 通道编号
/// @param time 指定时间
- (void)seekToTimeWithDeviceId:(NSString *_Nullable)deviceId channel:(int)channel time:(NSInteger)time playView:(ZDKPlayVideoView *_Nonnull)playView completion:(void(^_Nonnull)(BOOL isSuc))completion;

- (void)plusRecoredVideoWithDeviceId:(NSString *_Nonnull)deviceId channel:(int)channel CMDValue:(NSString *_Nonnull)CMDValue  playView:(ZDKPlayVideoView * _Nonnull)playView  completion:(void(^_Nonnull)(BOOL isSuc))completion;

- (void)minusRecoredVideoWithDeviceId:(NSString *_Nonnull)deviceId channel:(int)channel CMDValue:(NSString *_Nonnull)CMDValue  playView:(ZDKPlayVideoView *_Nonnull)playView  completion:(void(^_Nonnull)(BOOL isSuc))completion;

 
/// p2p网络探测，会回调结果
/// - Parameter deviceId: deviceid
-(void)p2pNetworkProbeDeviceId:(NSString *)deviceId;

/// 双链路开关
/// - Parameter isOpen: 开关
-(void)p2pMultilinkEnableIsOpen:(BOOL)isOpen;

/// 挂断/拒绝接听
/// - Parameter device: 设备id
- (void)rejectCallDeviceId:(NSString *)deviceId;


/// 关闭SDK日志打印，调用后，SDK内部大部分日志将不会打印
- (void)setLogOFF;

/// 启动日志写文件功能，将收集整个APP的终端打印日志，release环境才会收集，debug不会收集
/// 启动后，xcode的日志终端将无法输出打印，会全部被写日志功能所收集
/// 启动一次会以当时时间点创建一个日志文件，最多不超过5个，最老的将会被最新的所替代
- (void)launchWriteLogToFile;

/// 将触发添加到某个视图上,比如添加某个视图上，连续点击10次即可弹出显示日志文件列表
- (void)addClickFromSuperView:(UIView*)view;

/// 显示日志列表
- (void)showWriteLogView;

@end

NS_ASSUME_NONNULL_END
