//
//  ZDKP2PRecordVideoManager.h
//  ZDKMediaFramework
//
//  Created by UI design on 2017/7/11.
//  Copyright © 2017年 Mouse. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ZDKPlayVideoView.h"
@protocol P2PRecordVideoManager <NSObject>


/**
 Open File
 @param cameraID cameraID
 @param name name
 @param chnannel chnannel
 
 */
-(void)p2pRecoredVideoOpenTheFileWithCameraID:(NSString*)cameraID andWithFileName:(NSString*)name chnannel:(NSInteger)chnannel;

/**
 Open File
 @param cameraID cameraID
 @param name name
 @param chnannel chnannel
 @param version version
 */
-(void)p2pRecoredVideoOpenTheFileWithCameraID:(NSString*)cameraID andWithFileName:(NSString*)name chnannel:(NSInteger)chnannel version:(NSInteger)version;


/**
 Start
 @param cameraID cameraID
 */

-(void)p2pPlayRecoredVideoWithCameraID:(NSString*)cameraID andWithPlayView:(ZDKPlayVideoView*)playView chnannel:(NSInteger)chnannel;

/**
 Start play（Recommended new methods）
 @param cameraID cameraID
 @param startTime startTime
 @param endTime endTime
 */

-(void)p2pPlayRecoredVideoWithCameraID:(NSString*)cameraID playView:(ZDKPlayVideoView*)playView chnannel:(NSInteger)chnannel startTime:(NSInteger)startTime endTime:(NSInteger)endTime;

/**
 Stop
 @param cameraID cameraID
 */

-(void)p2pStopRecoredVideoWithCameraID:(NSString*)cameraID andWithPlayView:(ZDKPlayVideoView*)playView chnannel:(NSInteger)chnannel;
/**
 Pause
 @param cameraID cameraID
 */

-(void)p2pPauseRecoredVideoWithCameraID:(NSString*)cameraID andWithPlayView:(ZDKPlayVideoView*)playView chnannel:(NSInteger)chnannel;
/**
 Continue
 @param cameraID cameraID
 */
-(void)p2pResumeRecoredVideoWithCameraID:(NSString*)cameraID andWithPlayView:(ZDKPlayVideoView*)playView chnannel:(NSInteger)chnannel;


/**
 Quick play
 @param cameraID cameraID
 @param cmdValue Quick play multiples  1、4、8、16  multiples
 */
-(void)p2pPlusRecoredVideoWithCameraID:(NSString*)cameraID andWithCMDValue:(NSString*)cmdValue andWithPlayView:(ZDKPlayVideoView*)playView chnannel:(NSInteger)chnannel;

/**
 Slow playback
 @param cameraID 设备ID
 @param cmdValue Slow play multiples 2=1/2 4=1/4 6=1/6
 */
-(void)p2pMinusRecoredVideoWithCameraID:(NSString*)cameraID andWithCMDValue:(NSString*)cmdValue andWithPlayView:(ZDKPlayVideoView*)playView chnannel:(NSInteger)chnannel;

/**
 Progress playback
 @param cameraID cameraID
 @param time Time  millisecond
 */
-(void)p2pSeekToRecoredVideoWithCameraID:(NSString*)cameraID andWithTime:(NSInteger)time andWithPlayView:(ZDKPlayVideoView*)playView chnannel:(NSInteger)chnannel;

/**
 Event video playback
 @param cameraID cameraID
 @param startTime start Time
 @param endTime end Time
 */
-(void)p2pPlayEventVideoWithCameraID:(NSString*)cameraID startTime:(NSInteger)startTime endTime:(NSInteger)endTime andWithPlayView:(ZDKPlayVideoView*)playView chnannel:(NSInteger)chnannel;


@end
