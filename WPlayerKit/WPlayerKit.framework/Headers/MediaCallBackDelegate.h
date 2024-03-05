//
//  ZDKMediaCallBackDelegate.h
//  ZDKMediaFramework
//
//  Created by yanyueya on 2017/6/29.
//  Copyright © 2017年 Mouse. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum{
    
    BaseEvent_Nothing                       = 0,                    //不做处理的回调
    
    BaseEvent_CodeNull                      = 0x00, //Encoder Creation Failed
    BaseEvent_Connecting                    = 0x01, //Network Connection
    BaseEvent_ConnectTimeout                = 0x02, //Connection TimeOut
    BaseEvent_ConnectSuc                    = 0x03, //Connection Succeeded
    BaseEvent_ConnectFail                   = 0x04, //Connection Fail
    
    BaseEvent_InvalidUrl                    = 0x0c, //12，Invalid connection address
    BaseEvent_PlayComplete                  = 0x0d, //13，End Of Play
    BaseEvent_UnknowMediaFile               = 0x0e, //14，Unrecognized streaming media files
    BaseEvent_Code_InvalidData_input        = 0x0f, //15，Invalid file input data (data or null)(无效的文件输入数据（数据或为空))
    BaseEvent_SnapSuc                       = 0x1002, //4098，Manual screenshot Success
    BaseEvent_SnapFail                      = 0x1003, //4099，Manual screenshot Failed
    BaseEvent_WaitData                      = 0x1005, //4101，Poor network Waiting for Data
    BaseEvent_CancelWaitData                = 0x1006, //4102，Good network Cancels waiting Data
    
    BaseEvent_ActiveAliveError              = 0x1010, //4112，Heartbeat detection timeout network connection disconnected
    BaseEvent_ActivePushError               = 0x1011, //4113，Live push timeout network disconnected
    BaseEvent_ActivePlayError               = 0x1013, //4115，E_Event_Code_Active_Play_Error
    BaseEvent_NotSuitForLive                = 0x1014, //4116，E_Event_Code_Net_NotSuitForLive
    BaseEvent_LinkTransSuccess              = 0x2001, //8193，Successful P2P Penetration
    BaseEvent_LinkTransFailure              = 0x2002, //8194，Penetration Failed P2P
    BaseEvent_UdtConnectSuccess             = 0x2003, //8195，UDT establishes a successful connection
    BaseEvent_UdtConnectFailure             = 0x2004, //8196，UDT Failed to establish a connection
    BaseEvent_DelStreamResOk                = 0x2005, //8197，Close audio and video streaming successfully
    BaseEvent_CloseLinkResOk                = 0x2006, //8198，Close the P2P connection successfully
    BaseEvent_MaxP2PCount                   = 0x2007, //8199，The number of connections exceeded the maximum. Procedure（超过允许的最大连接数）
    BaseEvent_P2PError                      = 0x2008, //8200，P2P Error
    BaseEvent_HeartbeatError                = 0x2009, //8201，P2P heartbeat connection error
    BaseEvent_Code_Add_Video                = 0x2010, //8208，Add video stream successfully
    BaseEvent_Code_Add_Audio                = 0x2011, //8209，Add audio stream successfully
    
    BaseEvent_RemoteFileSearchSuccess       = 0x3000, //12288，Get recording list successfully
    BaseEvent_RemoteFileSearchFailure       = 0x3001, //12289，Failed to Get List
    BaseEvent_RemoteFileRequestSuccess      = 0x3002, //12290，Choose recording file successfully
    BaseEvent_RemoteFileCtrlPlaySuccess     = 0x3003, //12291，Recording file played successfully
    BaseEvent_RemoteFileCtrlPlayFailure     = 0x3004, //12292，Recording file playback failed
    BaseEvent_RemoteFileCtrlPlayeof         = 0x3005, //12293，End of playing recorded file
    
    BaseEvent_P2PCancelWaitData             = 0x3006, //12294，Start Playing
    BaseEvent_Device_License_check_Failure  = 0x3009, //12297，Authorization Failed（设备授权检查失败(网络连接错误、参数不对））
    BaseEvent_Device_License_expired        = 0x3010, //12304，Expiration of authorization（鉴权过期）
    
//    BaseEvent_Link_Direct_Connected = 36,            //Direct connection
//    BaseEvent_Link_Retweet = 37,                     //Forwarding
    
    BaseEvent_Code_Video_FPS_INFO           = 0x3011, //12305，Dynamic frame rate
    BaseEvent_Code_CameraPWD_Check_Failed   = 0x3012, //12306，camera password check failed
    BaseEvent_Code_License_Token_Error      = 0x3013, //12307， token invalid（token过期）
    BaseEvent_Code_Msg_Search_File_Time_List = 0x3015, //12309， Search tf for the day that video exists
    BaseEvent_Code_Msg_P2P_WaitData         = 0x3016, //12310，Need to wait for loading（3秒未接收到数据启动等待动画）
    BaseEvent_Code_Msg_P2P_DataChannel_Broken = 0x3017, //12311，Transmission interrupt, need to delete the flow and make hole again(启动等待动画20秒后未收到数据，数据通道中断)
    BaseEvent_Code_Msg_P2P_Topic            = 0x3018, //12312，topic(订阅主题)
    BaseEvent_Code_Msg_P2P_CancelTopic      = 0x3019, //12313，cancel topic(取消订阅主题)
    BaseEvent_Code_License_Routine_Error    = 0x3020, //12320，The authentication routine is incorrect（鉴权常规错误）
    BaseEvent_Code_Record_Start             = 0x3021, //12321，The video to start(录像开始)
    BaseEvent_Code_License_Device_OffLine   = 0x3022, //12322，The device is offline(设备不在线)
    BaseEvent_Code_License_Rule_Failure     = 0x3023, //12323，The device rule authentication fails. Procedure(设备规则鉴权未通过/设备无流量/设备被禁用)
    BaseEvent_Code_Open_Push_Stream         = 0x3024, //12324，The push-flow module is started successfully. Procedure（启动推流模块成功）
    BaseEvent_Code_Close_Push_Stream        = 0x3025, //12325，Succeeded in shutting down the push-stream. Procedure（关闭推流成功）
    BaseEvent_Code_Msg_Already_Watching_TFcard = 0x3026, //12326，The card replays are already being watched(卡回放已经有人在观看)
    BaseEvent_Code_Reply_To_Answering_Status = 0x3027, //12327，Active device shutdown (设备主动挂断)
    BaseEvent_Code_Record_Finish            = 0x3028, //12328，End Recording complete（结束录像完成）
    
    
    BaseEvent_Code_Msg_Report_State         = 0x4000, //16384，Network health information callback(实时网络探测状况信息回调) net_quality:(1质量好，2质量一般 3质量差)；losts:丢包率；max_rtt:最大延时(毫秒)；min_rtt:最小延时；arg_rtt:平均延时
    BaseEvent_Code_Msg_Turn_Network_Probe   = 0x4001, //16385，Network probe health information callback(网络探测状况信息回调)
    BaseEvent_Code_Msg_Peer_Ips_Error       = 0x4002, //16386，Failed to obtain the external IP address of the device(打洞失败，获取不到设备的外网IP)
    BaseEvent_Code_Msg_Ips_Error            = 0x4003, //16387，Failed to obtain the external IP address of the mobile phone(打洞失败，获取不到手机的外网IP)
    BaseEvent_Code_Msg_Turn_Authentication_Error = 0x4004, //16388，Turn authentication fails. Holes need to be dug again(Turn鉴权失败需要重新打洞)
     
    
    BaseEvent_Code_Audio_Is_Used_By_Other_Apps_Start = 0x20001, //131073，Audio is used by other apps
    BaseEvent_Code_Audio_Is_Used_By_Other_Apps_End = 0x20002, //131074，Audio is the other end of the APP
    BaseEvent_Code_SDK_MQTT_State_Error       = 0x20003, //131075，mqtt连接状态失败
    BaseEvent_Code_SDK_Authentication_Timeout = 0x20005, //131077，The sdk internal mqtt authentication timeout（sdk内部mqtt鉴权超时）
    BaseEvent_Code_No_Play_Del_Stream         = 0x20013, //131091，If no video is loaded, the stream is automatically shut down（未加载出视频，主动关流）
 
}ZDKCallBackEvent;


@protocol CallBackEventDelegate <NSObject>
@optional
/**
 Event Callback
 
 @param callBack callBack
 @param useInfo useInfo
 */
- (void)zdkCallBackEvent:(ZDKCallBackEvent)callBack andWithInfo:(NSDictionary*)useInfo; ///<

/**
 TF Video Play Progress
 
 @param playBack playBack
 */
-(void)zdkTFVideoProgressCallBackPlay:(NSDictionary*)playBack;

/**
 Cloud Video Play Progress
 
 @param playBack playBack
 */
-(void)zdkCloudVideoProgressCallBackPlay:(NSDictionary*)playBack;

/**
 tfCardInfo
 
 @param tfCardInfo tfCardInfo
 */
-(void)zdkCallBackTFCard:(NSDictionary*)tfCardInfo;

/**
 RemoteFile List
 
 @param remoteFile remoteFile
 */
-(void)zdkCallBackRemoteFile:(NSDictionary*)remoteFile;

/**
 TF Single video file duration
 
 @param totaltime totaltime
 */
-(void)ZDKCallBackTotalTime:(NSDictionary*)totaltime;



/// Receive internal message callback（接受到内部消息回调）
/// @param responseObject 返回值
-(void)ZDKMqttTopicResponseObject:(id)responseObject;

@end
