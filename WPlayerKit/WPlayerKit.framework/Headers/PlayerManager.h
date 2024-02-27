//
//  ZDKPlayerManager.h
//  ZDKMediaFramework
//
//  Created by yanyueya on 2017/6/28.
//  Copyright © 2017年 Mouse. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZDKPlayVideoView.h"

@protocol PlayerManager <NSObject>

@required

/**
 Play
 @param path  Play Address
 @param playView PlayView
 @param videoID  videoID
 @param isLive  isLive
 @param snapPath snapPath 
 @return YES Success NO Fail
 */
- (BOOL)playPath:(NSString *)path playView:(ZDKPlayVideoView *)playView videoID:(NSString *)videoID isLive:(BOOL)isLive snapPath:(NSString *)snapPath;

/**
 Change Play Position
 @param position Change position（seconds）
 */
- (void)changePositionPlayPosition:(int)position;

/**
 Stop Play
 @return YES Success NO Fail
 */
- (BOOL)stopPlay;

/**
 Set the mute
 
 @param enable mute：YES/NO  Default：NO
 @return results
 */
-(BOOL)setMuteControlEnable:(BOOL)enable;


/**
 Split screen stops playing
 @param videoID videoID
 @return YES Success NO Fail
 */
-(BOOL)stopPlayWithVideoID:(NSString*)videoID;
/**
 Compare Play ID
 @param playID playID
 @return   YES Success NO Fail
 */
-(BOOL)isEqualWithplayID:(NSString*)playID;
/**
 Find playView with playID
 @param playID playID
 @return ZDKPlayVideoView
 */
-(ZDKPlayVideoView*)playViewWithplayID:(NSString*)playID;
/**
 Pause Play
 @return YES Success NO Fail
 */
- (BOOL)pausePlay;

/**
 Continue Play
 @return YES Success NO Fail
 */
- (BOOL)resumePlay;

/**
 SnapImage
  @return YES Success NO Fail
 */
- (BOOL)snapImage:(NSString *)saveImagePath videoID:(NSString *)videoID;

/**
 Start recording
 @return YES Success NO Fail
 */
- (BOOL)startRecordVideo:(NSString *)saveVideoPath;

/**
 End recording
 @return YES Success NO Fail
 */
- (BOOL)endRecordVideo;


/**
 Download startTsToMp4File
 @param urlPath  Play Address
 @param sandboxPath The sandbox path to save
 @param videoDuration Video Duration
 */
- (void)downLoadVideoWithUrlPath:(NSString *)urlPath sandboxPath:(NSString *)sandboxPath videoDuration:(int)videoDuration resultCallback:(void(^)(BOOL isSuccess))resultCallback;

/**
 Cancel cancelDownLoadVideo
 */
- (void)cancelDownLoadVideo;


/**
 RTMP multiples play
 @param speed speed 0.5、1、2、4、8
 */
- (void)playMultipleSpeed:(float)speed;


/// Set the rendering mode, defalut 16:9
/// @param adaptiveType 1: 16:9 , 0：fill
-(void)setSurfaceAdaptiveType:(BOOL)adaptiveType;


@end



