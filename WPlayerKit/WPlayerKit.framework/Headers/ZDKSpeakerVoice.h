//
//  ZDKSpeakerVoice.h
//  ZDKMediaFramework
//
//  Created by UI design on 2017/5/31.
//  Copyright © 2017年 Mouse. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol ZDKSpeakerVoiceDelegate <NSObject>

/// 手机麦克风音频采集回调，使用场景：APP对音频做特殊处理
/// - Parameters:
///   - bufferData: 音频数据
///   - data_size: 音频大小
- (void)callbackAudioBufferData:(uint8_t*)bufferData dataSize:(size_t)dataSize;

@end

@interface ZDKSpeakerVoice : NSObject

/** 代理 默认不使用delegate，如果APP要做音频变声之类的功能才会使用到 */
@property (nonatomic, weak) id<ZDKSpeakerVoiceDelegate> delegate;

/**
 Initialize voice intercom

 @param cameraID cameraID
 @param sampleRate sampleRate
 @param type  Type 2 RTMP 4 P2P
 @param isPad isPad
 @return ZDKSpeakerVoice 
 */
- (id)initSpeakVoiceCameraID:(NSString *)cameraID SampleRate:(NSInteger)sampleRate andWithType:(NSString*)type isPad:(BOOL)isPad;
 
/// Open to talk
- (void)start;
 
/// Open to talk
/// @param sampleRate  sampleRate
/// @param fullDuplex  Whether to make a full-duplex call，The default yes
- (void)startWithSampleRate:(NSInteger)sampleRate fullDuplex:(BOOL)fullDuplex;

/// Open to talk
/// @param sampleRate  sampleRate
/// @param fullDuplex  Whether to make a full-duplex call，The default yes
/// @param channel  channel, The default 0
- (void)startWithSampleRate:(NSInteger)sampleRate fullDuplex:(BOOL)fullDuplex channel:(NSInteger)channel;

/// Open to talk
/// @param sampleRate  sampleRate
/// @param fullDuplex  Whether to make a full-duplex call，The default yes
/// @param channel  channel, The default 0
/// @param complete Initialization complete
- (void)startWithSampleRate:(NSInteger)sampleRate fullDuplex:(BOOL)fullDuplex channel:(NSInteger)channel complete:(void (^)(void))complete;

/// Close to talk
- (void)stop;

/// Incoming audio data stream to device (传入音频数据流，传给设备)
/// @param bufferData 音频数据
/// @param dataSize 音频大小
- (void)inputAudioBufferData:(uint8_t*)bufferData dataSize:(size_t)dataSize;

@end
