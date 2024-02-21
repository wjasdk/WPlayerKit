//
//  ZDKP2PPlayManager.h
//  ZDKMediaFramework
//
//  Created by UI design on 2017/7/11.
//  Copyright © 2017年 Mouse. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WPlayerKit/WCommonMacro.h>

@protocol P2PPlayManager <NSObject>

@property (nonatomic, assign, readonly) BOOL privateAudioCategoryLoudspeaker;

/**
 P2P Token Create a video connection
 
 @param cameraid  cameraid
 @param token  token
 @param numberType  Connection method
 0 Just connect directly
 1 Direct connection or forwarding
 2 Just forward
 */
-(long)connectionP2PWithCameraID:(NSString*)cameraid andWithToken:(NSString*)token andWithNumberType:(NSInteger)numberType;

/**
 P2P Accesskey SecretKey Create a video connection

 @param cameraid  cameraid
 @param accesskey accesskey
 @param secretKey secretKey
 @param platformUserId  platformUserId
 @param numberType  Connection method
 0 Just connect directly
 1 Direct connection or forwarding
 2 Just forward
 */
-(long)connectionP2PWithCameraID:(NSString*)cameraid andWithAccesskey:(NSString*)accesskey andWithSecretKey:(NSString*)secretKey andWithPlatformUserId:(NSString*)platformUserId andWithNumberType:(NSInteger)numberType;


/**
 P2P Add Audio Stream
 
 
 @param chnannel Audio Channels 0  First Channel
 @param cameraID cameraID
 @param linkHandle Establish connection function return value
 @param isplay    Play Type  YES Live NO Record
 @param password  password  the length <= 6
 @param isPad pad
 @return Video Channel Value
 */
-(long)connectionP2PAudioWithChnannel:(NSInteger)chnannel andWithCameraID:(NSString*)cameraID andWithLinkHandle:(long)linkHandle isPlay:(BOOL)isplay password:(NSString *)password isPad:(BOOL)isPad;


/**
 P2P Add Video Stream

 @param chnannel  chnannel Video Channels 0  First Channel
 @param cameraID   cameraID
 @param linkHandle Establish connection function return value
 @param isplay    Play Type  YES Live NO Record
 @param password  password  the length <= 6
 @return Video Channel Value
 */
-(long)connectionP2PVideoWithChnannel:(NSInteger)chnannel andWithCameraID:(NSString*)cameraID andWithLinkHandle:(long)linkHandle isPlay:(BOOL)isplay password:(NSString *)password;


/**
 Create Player

 @param playView playView
 @param cameraID cameraID
 */
- (void)setP2PSurfaceWithPlayView:(ZDKPlayVideoView*)playView andWithCameraID:(NSString*)cameraID;
/**
 Create Player

 @param playView playView
 @param cameraID cameraID
 @param channel  channel
 */
- (void)setP2PSurfaceWithPlayView:(ZDKPlayVideoView*)playView andWithCameraID:(NSString*)cameraID channel:(NSInteger)channel;

/// Set the rendering mode, defalut 16:9
/// @param adaptiveType 1: 16:9 , 0：fill
/// @param cameraID cameraID
/// @param channel Video channel value
-(void)setSurfaceAdaptiveType:(BOOL)adaptiveType cameraID:(NSString*)cameraID channel:(NSInteger)channel;

/**
 
 Close Audio
 
 @param linkHandle Audio channel value
 */
-(void)getP2PAudioDeletWithLinkHandle:(long)linkHandle;
/**
 Close Video
 @param linkHandle Video channel value
 */
-(void)getP2PVideoDeletWithLinkHandle:(long)linkHandle;
/**
 Close the connection
 
 
 @param linkHandle Establish connection function return value
 */
-(void)closeP2PMobileUnlinkLinkHandle:(long)linkHandle;


/**
 p2p Screenshots
 @param filePath filePath
 @param chnannel chnannel
 */
-(void)p2pShootScreenWithFilePath:(NSString*)filePath chnannel:(NSInteger)chnannel;

/**
 p2p Screenshots
 @param filePath filePath
 @param cameraID cameraID
 @param chnannel chnannel
 */
-(void)p2pShootScreenWithFilePath:(NSString*)filePath cameraID:(NSString*)cameraID andWithisPlay:(BOOL)isPlay chnannel:(NSInteger)chnannel;

/**
 p2p Record
 @param recordctr control commands(1、Start 2、Pause3、Close)
 @param filename filename
 @param isPlay  Whether to play when recording
 @param chnannel  chnannel   0~
 */
-(void)p2pLiveRecordRecordCtr:(NSString*)recordctr andWithFileName:(NSString*)filename andWithisPlay:(BOOL)isPlay chnannel:(NSInteger)chnannel;

/**
 p2p Record
 @param recordctr control commands(1、Start 2、Pause3、Close)
 @param filename filename
 @param isPlay  Whether to play when recording
 @param cameraID cameraID
 @param chnannel  chnannel   0~
 */
-(void)p2pLiveRecordRecordCtr:(NSString*)recordctr andWithFileName:(NSString*)filename andWithisPlay:(BOOL)isPlay cameraID:(NSString*)cameraID chnannel:(NSInteger)chnannel;


/**
 Set the mute
 
 @param enable mute：YES/NO  Default：NO
 @return results
 */
-(BOOL)setP2PMuteControlEnable:(BOOL)enable;

/**
 Sets the player volume multiple
 
 @param volume volume defalut 1.0
 @param cameraID cameraID
 @param chnannel  chnannel   0~
 @param isPlay  Whether to play when recording
 */
-(void)setP2PAudioFactorVolume:(float)volume cameraID:(NSString*)cameraID chnannel:(NSInteger)chnannel isPlay:(BOOL)isPlay;



/**
 
 1、获取TF卡信息
 动作：GET_TF_INFO_LIST
 {"ACTION": "GET_TF_INFO_LIST","VALUE":{"channel":"0","password":"123456",device_id:@"xxxx"}}
 
 返回值：
 device_id
 tf_name//tf卡名称
 tf_status//TF卡状态 0：未插卡 1：正常插卡，并且为可用状态 2：不支持的状态，需格式化
 tf_file_system//文件系统，NTFS/FAT32
 tf_free_size//空闲空间 单位MB
 tf_use_size//已用空间 单位MB
 tf_total_size//总空间 单位MB
 tf_version //版本号 等于1 使用新版获取卡文件和播放
 
 2、获取TF卡文件列表
 动作：GET_TF_FILE_LIST
 值：
 device_id//设备ID
 current_page//当前页码
 channel//当前通道
 file_name//文件名称
 file_type//文件类型 0:7X24小时录制 1：告警视频片段
 file_start_time//开始时间戳
 file_end_time//结束时间戳
 
 设置示例：{"ACTION": "GET_TF_FILE_LIST","VALUE":{"channel":"0","file_type":"0","start_time":"1234566","end_time":"1234567","page":"1","page_num":"1","password":"123456"}}
 返回示例：{"ACTION": "GET_TF_FILE_LIST","VALUE":{"device_id":"0123456","current_page":"1","channel":"0",tf_file_list:[{"file_name":"XXXXXXXXXX","file_type":"0","file_start_time":"1234566","file_end_time":"1234567"}]}}
 
 
 3、检查一段时间内那一天存在文件
 动作：GET_WHICH_DAY_STORAGE_FILE
 设置示例：{"ACTION": "GET_WHICH_DAY_STORAGE_FILE","VALUE":{"device_id":"123456","channel":"0","file_type":"0","start_time":"1234566","end_time":"1234567","password":"123456"}}
 返回示例：{"ACTION": "GET_WHICH_DAY_STORAGE_FILE","VALUE":{"device_id":"0123456","channel":"0",have_file_list:["1234567890","1234567890"]}}
 
 */
-(void)p2pGetDeviceInformationFromParameter:(NSDictionary*)parameter;

/// p2p网络探测，会回调结果
/// - Parameter deviceId: deviceid
-(void)p2pNetworkProbeDeviceId:(NSString *)deviceId;

/// 双链路开关
/// - Parameter isOpen: 开关
-(void)p2pMultilinkEnableIsOpen:(BOOL)isOpen;

/// p2p 音频播放模式，默认为扬声器播放，设置为NO可切换成听筒
/// - Parameter loudspeaker: YES 扬声器，NO 听筒
- (void)setAudioCategoryLoudspeaker:(BOOL)loudspeaker;

/// 设置当前视频模式 ，用于数据上报到监控系统，具体看枚举值WTalkMode
/// - Parameter talkMode
- (void)setTalkMode:(WTalkMode)talkMode deviceId:(NSString *)deviceId;

@end
