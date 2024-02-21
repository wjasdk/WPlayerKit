//
//  WCommonStream.h
//  WPlayerKit
//
//  Created by List on 30/9/2022.
//  Copyright © 2022 List. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WCommonMacro.h"
#import "ZDKPlayVideoView.h"
  
@class WCommonLink;

NS_ASSUME_NONNULL_BEGIN

@interface WCommonStream : NSObject

/// 下面所有方法仅限SDK内部使用

typedef void(^_Nullable WCommonStreamStateChangeBlock)(WCommonStream *_Nonnull link,WCommonStreamStates states,NSDictionary *_Nullable info);

/// 隶属的P2P连接
@property (nonatomic, weak) WCommonLink *_Nullable superLink;
@property (nonatomic, copy) NSString *_Nonnull deviceId;
@property (nonatomic, assign) long  channel;
@property (nonatomic, assign) BOOL  needPlay;
@property (nonatomic, assign) long  souceStreamType;
@property (nonatomic, assign) long  videoStreamType;
@property (nonatomic, copy) NSString *_Nonnull devicePwd;
@property (nonatomic, assign) BOOL isPad; /// <是否是pad
@property (nonatomic, assign) BOOL isPlay; /// <是否是直播 YES直播NO录播
@property (assign) WCommonStreamStates states;
@property (assign) WStreamType type;
@property (nonatomic, copy) WCommonStreamStateChangeBlock addBlock;
@property (nonatomic, copy) WCommonStreamStateChangeBlock addSoundAudioBlock;  // 加声音的回调
@property (nonatomic, copy) WCommonStreamStateChangeBlock addVideoBlock;       // 加视频的回调
@property (nonatomic, copy) WCommonStreamStateChangeBlock deletBlock;
@property (nonatomic, weak) ZDKPlayVideoView *playView;
@property (nonatomic, strong) NSTimer  * _Nonnull renderObserveTimer;
@property (nonatomic, assign) NSTimeInterval  lastestFrameTimetemp;
@property (nonatomic, assign) BOOL isSilent;


/// 指定构造器
/// @param type 流的类型
/// @param channel 通道
/// @return 新对象
- (instancetype)initWithType:(WStreamType)type channel:(long)channel;


@end

NS_ASSUME_NONNULL_END
