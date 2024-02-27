//
//  WCommonMacro.h
//  WPlayerKit
//
//  Created by List on 30/9/2022.
//  Copyright © 2022 List. All rights reserved.
//

#ifndef WCommonMacro_h
#define WCommonMacro_h
#import "MediaCallBackDelegate.h"


/**
 操作类型，P2P或者RTMP
 */
typedef NS_ENUM(NSUInteger, WOperationType) {
    /** 直播和卡回放操作（p2p） */
    WOperationP2P,
    
    /** RTMP操作(告警、云回放) */
    WOperationRTMP
};
  

typedef NS_ENUM(NSUInteger, WP2PCommonLinkState) {
    WP2PCommonLinkStateUnLink         =  0,
    WP2PCommonLinkStateHasLink        =  1,
    WP2PCommonLinkStateLoding         =  1<<2,       // 正在添加数据流
    WP2PCommonLinkStateHasViedoStream =  1<<5,     // 存在音频流
    WP2PCommonLinkStateHasAudioStream =  1<<6      // 存在视频流
};

typedef NS_ENUM(NSUInteger, WCommonLinkStates) {
    WCommonLinkStatesUnkown,
    WCommonLinkStatesConnecting,
    WCommonLinkStatesConnectSuccess,
    WCommonLinkStatesConnectFalse
};

typedef NS_ENUM(NSUInteger, WCommonLinkiInterruptEvent) {
    WCommonLinkiEventUnkown = 0,
    WCommonLinkiEventP2PError,                  // P2P播放错误
    WCommonLinkiEventWaitBufferFinish,          // P2P视频恢复播放
    WCommonLinkiEventWaitBuffering,             // 视频缓冲中，有点不流畅
    WCommonLinkiEventP2PPlaybackEnd,            // TF回放文件播放结束
};


typedef NS_ENUM(NSUInteger, WCommonStreamStates) {
    WCommonStreamStatesUnkown,
    WCommonStreamStatesConnecting,              //加流中
    WCommonStreamStatesLinkSuccess,             //加流成功
    WCommonStreamStatesLinkFalse,               //加流失败
    WCommonStreamStatesWakeUpSuccess,           //低功耗设备唤醒成功
    WCommonStreamStatesWakeUpFailure,           //低功耗设备唤醒失败
    WCommonStreamStatesPWDCheckFailed           //设备密码错误
};

/// 0:主码流 1:次码流  2: 音频流  3:录播视频  4:录播音频
/// NVR/XVR设备切换分辨率时对应的值为 WStreamTypeVideo : 高清，WStreamTypeAttachVideo ：标清
typedef NS_ENUM(NSUInteger, WStreamType) {
    WStreamTypeVideo        =  0,
    WStreamTypeAttachVideo  =  1,
    WStreamTypeAudio        =  2,
    WStreamTypeRecordVideo  =  3,
    WStreamTypeRecordAudio  =  4,
    WStreamTypeVideoStop    =  100
};


/// 云台控制
typedef NS_ENUM(NSUInteger, WPTZDirection) {
    WPTZDirectionStop               = 0,    /* 停止，持续长按某个方向后需调此方法来停止转动 endRollAction专属*/
    WPTZDirectionTopShortPress      = 1,    /* 向上一步，短按 */
    WPTZDirectionBottomShortPress   = 2,    /* 向下一步，短按 */
    WPTZDirectionLeftShortPress     = 3,    /* 向左一步，短按 */
    WPTZDirectionRightShortPress    = 4,    /* 向右一步，短按 */
    WPTZDirectionTopLongPress       = 5,    /* 持续向上，长按 */
    WPTZDirectionBottomLongPress    = 6,    /* 持续向下，长按 */
    WPTZDirectionLeftLongPress      = 7,    /* 持续向左，长按 */
    WPTZDirectionRightLongPress     = 8,    /* 持续向右，长按 */
};

/// 分辨率
typedef NS_ENUM(NSUInteger, WVideoQuality) {
    WVideoQualitySD =  0,    /* 流畅 */
    WVideoQualityHD,         /* 高清 */
    WVideoQualitySHD,        /* 超清 */
};

/// 视频呼叫模式
/// 0:实时预览 1:语音对讲 2 视频对讲 3卡回放
typedef NS_ENUM(NSUInteger, WTalkMode) {
    WTalkModeLive =  0,            /* 实时直播预览 */
    WTalkModeVoiceCall = 1,        /* 语音对讲通话 */
    WTalkModeVideoCall = 2,        /* 视频双向通话 */
    WTalkModeTFBackVideo = 3,      /* TF卡视频回放 */
};

#endif /* WCommonMacro_h */
