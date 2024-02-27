//
//  ZDKMediaCallBackDelegate.h
//  ZDKMediaFramework
//
//  Created by yanyueya on 2017/6/29.
//  Copyright © 2017年 Mouse. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum{
    
    BaseEvent_Nothing = 0,                //不做处理的回调
    
    BaseEvent_CodeNull = 1,                  //Encoder Creation Failed
    BaseEvent_Connecting = 2,                //Network Connection
    BaseEvent_ConnectSuc = 3,                //Connection Succeeded
    BaseEvent_ConnectFail = 4,               //Connection Fail
    BaseEvent_ConnectTimeout = 5,            //Connection TimeOut
    
    BaseEvent_InvalidUrl = 6,                //Invalid connection address
    BaseEvent_UnknowMediaFile = 7,           //Unrecognized streaming media files
    BaseEvent_WaitData = 8,                  //Poor network Waiting for Data
    BaseEvent_CancelWaitData = 9,            //Good network Cancels waiting Data
    
    BaseEvent_ActiveAliveError = 10,          //Heartbeat detection timeout network connection disconnected
    BaseEvent_ActivePushError = 11,           //Live push timeout network disconnected
    BaseEvent_ActivePlayError = 12,           //E_Event_Code_Active_Play_Error
    BaseEvent_NotSuitForLive = 13,            //E_Event_Code_Net_NotSuitForLive
    
    BaseEvent_FirstSnapSuc = 14,              //First screenshot success
    BaseEvent_SnapSuc = 15,                   //Manual screenshot Success
    BaseEvent_SnapFail = 16,                  //Manual screenshot Failed
    BaseEvent_PlayComplete = 17,              //End Of Play
    
    BaseEvent_LinkTransSuccess = 18,          //Successful P2P Penetration
    BaseEvent_LinkTransFailure = 19,          //Penetration Failed P2P
    BaseEvent_UdtConnectSuccess = 20,         //UDT establishes a successful connection
    BaseEvent_UdtConnectFailure = 21,         //UDT Failed to establish a connection
    BaseEvent_DelStreamResOk = 22,            //Close audio and video streaming successfully
    BaseEvent_CloseLinkResOk = 23,            //Close the P2P connection successfully
    BaseEvent_MaxP2PCount = 24,               //The number of connections exceeded the maximum. Procedure（超过允许的最大连接数）
    BaseEvent_P2PError = 25,                  //P2P Error
    BaseEvent_RemoteFileSearchSuccess = 26,   //Get recording list successfully
    BaseEvent_RemoteFileSearchFailure = 27,   //Failed to Get List
    BaseEvent_RemoteFileRequestSuccess = 28,  //Choose recording file successfully
    BaseEvent_RemoteFileCtrlPlaySuccess = 29, //Recording file played successfully
    BaseEvent_RemoteFileCtrlPlayFailure = 30, //Recording file playback failed
    BaseEvent_RemoteFileCtrlPlayeof = 31,     //End of playing recorded file
    BaseEvent_HeartbeatError = 32,            //P2P heartbeat connection error
    BaseEvent_P2PCancelWaitData = 33,         //Start Playing
    BaseEvent_Device_License_check_Failure = 34,     //Authorization Failed
    BaseEvent_Device_License_expired = 35,           //Expiration of authorization（鉴权过期）
    BaseEvent_Link_Direct_Connected = 36,            //Direct connection
    BaseEvent_Link_Retweet = 37,                     //Forwarding
    BaseEvent_Code_Video_FPS_INFO = 38,        //Dynamic frame rate
    BaseEvent_Code_Add_Video = 39,             //Add video stream successfully
    BaseEvent_Code_Add_Audio = 40,              //Add audio stream successfully
    BaseEvent_Code_CameraPWD_Check_Failed = 41,   //camera password check failed
    BaseEvent_Code_Msg_Search_File_Time_List = 42, // Search tf for the day that video exists
    BaseEvent_Code_Audio_Is_Used_By_Other_Apps_Start = 43,   //Audio is used by other apps
    BaseEvent_Code_Audio_Is_Used_By_Other_Apps_End = 44,      //Audio is the other end of the APP
    BaseEvent_Code_Msg_P2P_WaitData = 45,                    //Need to wait for loading（3秒未接收到数据启动等待动画）
    BaseEvent_Code_Msg_P2P_DataChannel_Broken = 46,           //Transmission interrupt, need to delete the flow and make hole again(启动等待动画20秒后未收到数据，数据通道中断)
    BaseEvent_Code_InvalidData_input = 47,   //Invalid file input data (data or null)(无效的文件输入数据（数据或为空))
    BaseEvent_Code_Msg_P2P_Topic = 48,           //topic(订阅主题)
    BaseEvent_Code_Msg_P2P_CancelTopic = 49,       //cancel topic(取消订阅主题)
    BaseEvent_Code_License_Token_Error = 50,     // token invalid（token过期）
    BaseEvent_Code_License_Routine_Error = 51,     // The authentication routine is incorrect（鉴权常规错误）
    BaseEvent_Code_Record_Start = 52,               // The video to start(录像开始)
    BaseEvent_Code_License_Device_OffLine = 53,      // The device is offline(设备不在线)
    BaseEvent_Code_Msg_Report_State = 54,            // Network health information callback(实时网络探测状况信息回调) net_quality:(1质量好，2质量一般 3质量差)；losts:丢包率；max_rtt:最大延时(毫秒)；min_rtt:最小延时；arg_rtt:平均延时
    BaseEvent_Code_Msg_Turn_Network_Probe = 55,        // Network probe health information callback(网络探测状况信息回调)
    BaseEvent_Code_License_Rule_Failure = 56,          // The device rule authentication fails. Procedure(设备规则鉴权未通过/设备无流量/设备被禁用)
    BaseEvent_Code_SDK_Authentication_Timeout = 57,    // The sdk internal mqtt authentication timeout（sdk内部mqtt鉴权超时）
    BaseEvent_Code_Open_Push_Stream = 58,              // The push-flow module is started successfully. Procedure（启动推流模块成功）
    BaseEvent_Code_Close_Push_Stream = 59,             // Succeeded in shutting down the push-stream. Procedure（关闭推流成功）
    BaseEvent_Code_Reply_To_Answering_Status = 60,     // Active device shutdown (设备主动挂断)
    BaseEvent_Code_Msg_Already_Watching_TFcard = 61,          // The card replays are already being watched(卡回放已经有人在观看)
     
    BaseEvent_Code_Msg_Peer_Ips_Error = 62,      // Failed to obtain the external IP address of the device(打洞失败，获取不到设备的外网IP)
    BaseEvent_Code_Msg_Ips_Error = 63,             // Failed to obtain the external IP address of the mobile phone(打洞失败，获取不到手机的外网IP)
    BaseEvent_Code_Msg_Turn_Authentication_Error = 64,             // Turn authentication fails. Holes need to be dug again(Turn鉴权失败需要重新打洞)
 
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
