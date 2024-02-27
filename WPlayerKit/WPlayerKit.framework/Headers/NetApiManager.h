//
//  NetApiManager.h
//  WPlayerKit
//
//  Created by List on 22/7/2021.
//  Copyright © 2021 List. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "WCommonMacro.h"
#import "MediaCallBackDelegate.h"

typedef void(^DpsSuccess)(id data);
typedef void(^DpsFailure)(id data);

/// Notification of changes in MQTT connection state implementation（MQTT连接状态实现变化的通知）
/// {name = WPlayerKitMQTTSessionManagerStateChangeState; object = MQTTSessionManagerStateConnecting}
#define WPlayerKitMQTTSessionManagerStateChangeState    @"WPlayerKitMQTTSessionManagerStateChangeState"
#define WPlayerKitMQTTSessionManagerStateConnecting     @"MQTTSessionManagerStateConnecting"
#define WPlayerKitMQTTSessionManagerStateConnected      @"MQTTSessionManagerStateConnected"
#define WPlayerKitMQTTSessionManagerStateError          @"MQTTSessionManagerStateError"

@protocol NetApiManager <NSObject>

/// Initialize Token and Topic（初始化token和topic）
/// @param token required
/// @param topic required
/// sdkLoginWithUserToken 登录SDK时已经内部调了该方法，所以开发者无需再调
- (void)initDeviceCtrlWithUserToken:(NSString *)token topic:(NSString *)topic;


///Set the server domain name, not required（设置服务器域名，非必需）
- (void)setDominServerUrl:(NSString *)url;


///Send control instructions to the device （向设备发送控制指令）
/// @param deviceId required
/// @param dpsData  parameter   { "sleep_switch":0, "indicator_switch":0 }
/// @param success Success
/// @param failure The error message
- (void)setStatusWithDeviceId:(NSString *)deviceId dpsData:(NSDictionary *)dpsData success:(DpsSuccess)success failure:(DpsFailure)failure;


/// Read information from the device （从设备读取信息）
/// @param deviceId required
/// @param dpsData  parameter   ["sleep_switch","indicator_switch"]
/// @param success Success
/// @param failure The error message
- (void)getStatusWithDeviceId:(NSString *)deviceId dpsData:(NSDictionary *)dpsData success:(DpsSuccess)success failure:(DpsFailure)failure;


/// Wake up the device（唤醒设备）
/// @param deviceId required
/// @param success success description
/// @param failure failure description
- (void)wakeUpDeviceWithDeviceId:(NSString *)deviceId success:(DpsSuccess)success failure:(DpsFailure)failure;


/// The end of the keep wake（销毁唤醒的轮询）
- (void)closeWakeUpDeviceFind;


/// keep wake the device（维活设备）
/// @param deviceId required
- (void)keepWakeWithDeviceId:(NSString *)deviceId;


/// The end of the keep wake（销毁维活）
- (void)closeKeepWake;


///Check whether the firmware of the device can be upgraded （检查设备固件是否可以升级）
/// @param deviceId required
/// @param language optionals （zh:中文,en:英语:de:德语:fr:法语:ja:日语:ko:韩语:gu:印度语）The default zh
- (void)checkUpgradeWithDevice:(NSString *)deviceId language:(NSString *)language success:(DpsSuccess)success failure:(DpsFailure)failure;


/// Device firmware upgrade （设备固件升级）
/// @param deviceId required
- (void)upgradeWithDevice:(NSString *)deviceId progressBlock:(void(^)(NSString *deviceId, NSInteger updateStatus, NSInteger progress))progressBlock failure:(DpsFailure)failure;


/// Clear device firmware upgrade（清除设备固件升级）
- (void)clearUpgradeDevice;


/// Get the cloud playback timeline （获取云回放时间轴）
/// @param deviceId 设备id
/// @param startTime 开始时间
/// @param endTime 结束时间
/// @param timeZone Time zone offset in the format of -0800; East 9th Zone: +0900 can only recognize the whole time zone (时区偏移量 ，格式为 西八区： -0800 ； 东九区：+0900 只能识别整时区)
- (void)getCloudPlaylistWithDevice:(NSString *)deviceId startTime:(NSString *)startTime endTime:(NSString *)endTime timeZone:(NSString *)timeZone success:(DpsSuccess)success failure:(DpsFailure)failure;


/// Get the device details （获取设备详情）
/// @param deviceId 设备id
/* {
     "code": "0",
     "data": {
         "pact_version":"1",//设备协议版本,小于3为旧版控制协议。适用设备:摄像机Q2、A5、G400。>=3为新版控制协议。
         "alarm_status": "1",//设备云告警开通状态,0:关闭,1:开启。当设备协议版本>=4时此字段废弃
         "ts_status": "1",//设备视频存储开通状态,0:关闭,1:全天存储,2:事件触发时存储,3:图片存储(设备协议版本>=4时"图片存储"状态可用)
         "cloud_status": "0",//RTMP推流状态,0:关闭,1:开启RTMP存储(状态废弃)2:开启直播推流
         "img_status": "0",//图片存储状态,0:关闭,1开启当设备协议版本>=3时此字段废弃
         "is_bind": "1",//当前设备绑定状态
         "mac_address":"",//设备物理地址
         "ip_address":"",//设备IP地址
         "wifi_name":"",//设备WIFI名称
         "firmware_version": "T20X_CN_IOT_TX_V1.09",//固件版本
         "device_status": "1",//在线状态,0:离线,1:在线,2:休眠
         "device_type": "Q1P",//设备产品ID
         "device_model":"Q1Pro"，//设备型号
         "imei":"1234567890987654321",//IMEI
         "imsi":"1234567890987654321",//IMSI
         "iccid":"1234567890987654321",//ICCID
         "operator":1,//物联卡运营商 1/2/3 </br>1联通，2移动，3电信
         "device_ip":"192.168.13.22",//(冗余字段)后续将废弃
         "device_mac": "14:6b:9c:50:1b:20",//(冗余字段)后续将废弃
         "device_version": "T20X_CN_IOT_TX_V1.09"//(冗余字段)后续将废弃
     },
     "message": "ok"
 } */
- (void)getDeviceInfoWithDevice:(NSString *)deviceId success:(DpsSuccess)success failure:(DpsFailure)failure;


/// Get the Event list （获取事件列表）
/// @param deviceId 设备id
/// @param startTime 开始时间
/// @param endTime 结束时间
/// @param page 页码
/// @param pageSize 一页数量
- (void)getEventListWithDevice:(NSString *)deviceId startTime:(NSString *)startTime endTime:(NSString *)endTime page:(NSInteger)page pageSize:(NSInteger)pageSize success:(DpsSuccess)success failure:(DpsFailure)failure;


/// Sends a message to the specified topic（往指定主题发送消息）
/// @param topic required
/// @param message required
- (void)publishToTopic:(NSString *)topic message:(NSString *)message;


/// Cancel subject listening（取消主题监听）
- (void)cancelTopic:(NSString *)topic;


/// Cancel all topics（取消所有主题）
- (void)cancelAllTopic;


/// The system notifies the callback（系统通知回调，json字符串）
- (void)onSystemNotifyBlock:(void(^)(NSString *notify))onSystemNotifyBlock;


/// Device online status changes（设备在线状态变化）
/// 0: Offline,1: Online,2: Sleep（0:离线,1 :在线,2:休眠）
- (void)onOnlineStatusNotifyBlock:(void(^)(NSString *deviceId, NSInteger status))onOnlineStatusNotifyBlock;


/// The state of the device to be bound（待绑定设备的状态）
/// 1:The device can be bound 3: already bound The device 4: already bound by someone else
/// 1:此设备可以绑定 3:已经绑定该设备 4:已经被别人绑定
- (void)onBindStatusNotifyBlock:(void(^)(NSString *deviceId, NSInteger status))onBindStatusNotifyBlock;
 

/// Submission of equipment information（设备消息的上报）
/// resport The message data   （设备消息json字符串）
- (void)onDeviceResportBlock:(void(^)(NSString *deviceId, NSString *resport))onDeviceResportBlock;


///Callbacks to other MQTT messages （其他mqtt消息的回调）
- (void)onMsgArrivedBlock:(void(^)(NSString *topic,NSString *arrivedMsg))onMsgArrivedBlock;
 

/// Destroy mqtt（销毁mqtt）
- (void)disconnectWithDisconnect;
 

/// Network detection: detection of APP network and signaling communication between APP and device （网络探测，探测APP的网络、APP与设备信令通信状况、打洞状况）
/// net_quality:1质量好,2质量一般 ,3质量差 arg_rtt:平均延时, 百分比，losts:丢包率
/// - Parameters:
///   - deviceId: 设备ID
///   - isP2PLink: 是否启动打洞，查看是否能成功
///   - mobilePhoneNetworkBlock: 手机网络传输状况
///   - signallingNetworkBlock: 手机跟设备网络传输状况
///   - p2pConnectStateBlock: P2P打洞传输状况
///   - totalResultFinshBlock: 最终结果，主要是质量跟丢包率
- (void)beginNetworkDetectionDeviceId:(NSString *)deviceId isP2PLink:(BOOL)isP2PLink
              mobilePhoneNetworkBlock:(void(^)(NSDictionary *resultDic))mobilePhoneNetworkBlock
               signallingNetworkBlock:(void(^)(NSDictionary *resultDic))signallingNetworkBlock
                      p2pConnectStateBlock:(void(^)(ZDKCallBackEvent event, NSDictionary *resultDic))p2pConnectStateBlock
                           totalResultFinshBlock:(void(^)(NSDictionary *resultDic))totalResultFinshBlock;


/// 销毁网络探测
- (void)dismissNetworkDetection;

@end
