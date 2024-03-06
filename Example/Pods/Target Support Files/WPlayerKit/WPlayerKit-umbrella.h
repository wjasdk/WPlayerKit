#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "MediaCallBackDelegate.h"
#import "MediaClient.h"
#import "MediaHeader.h"
#import "MessageManager.h"
#import "NetApiManager.h"
#import "P2PPlayManager.h"
#import "P2PRecordVideoManager.h"
#import "PlayerManager.h"
#import "Server.h"
#import "WCommonLink.h"
#import "WCommonMacro.h"
#import "WCommonStream.h"
#import "WMediaControl.h"
#import "WPlayerKit.h"
#import "WVideoCaptureView.h"
#import "WVideoPlayView.h"
#import "WVideoRecorderView.h"
#import "WZoomSuperView.h"
#import "ZDKBeautyControl.h"
#import "ZDKMediaCallBack.h"
#import "ZDKPlayVideoView.h"
#import "ZDKSpeakerVoice.h"

FOUNDATION_EXPORT double WPlayerKitVersionNumber;
FOUNDATION_EXPORT const unsigned char WPlayerKitVersionString[];

