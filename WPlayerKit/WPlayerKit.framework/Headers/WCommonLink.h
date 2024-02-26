//
//  WCommonLink.h
//  WPlayerKit
//
//  Created by List on 30/9/2022.
//  Copyright © 2022 List. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WCommonStream.h"
#import "WCommonMacro.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^WCommonLinkStateChangeBlock)(WCommonLink *_Nonnull link,WCommonLinkStates states,NSDictionary *_Nullable info);

@interface WCommonLink : NSObject
 
@property (nonatomic, copy) NSString *_Nonnull deviceId;
@property (nonatomic, copy) NSString *conType; /// 直连或转发
@property (nonatomic, assign) long  linkId;
@property (nonatomic, assign) int   linkType;
@property (nonatomic, assign) int   creatLinkIndex;

/// 维护连接状态 原子操作
@property (assign) WCommonLinkStates state;
@property (nonatomic, copy) WCommonLinkStateChangeBlock addBlock;
@property (nonatomic, copy) WCommonLinkStateChangeBlock closeBlock;
@property (nonatomic, copy) void(^interruptHandle)(WCommonLinkiInterruptEvent errorCode, ZDKCallBackEvent callBack, WCommonStreamStates states, NSString *playId);
@property (nonatomic, copy) void(^openRecordCompletion)(BOOL);
@property (nonatomic, copy) void(^searchFileCompletion)(NSDictionary *dic,WCommonStreamStates state);
@property (nonatomic, assign) int playId;
@property (nonatomic, assign) int lessFpsCount; /// 低于最低fps的累积次数

/// 添加流
/// @param stream 流对象的channel type必须在调用之前设置
- (void)addStream:(WCommonStream *)stream;


/// 查找连接上添加的数据流
/// @param type 流的类型
/// @param channel 通道编号
/// @return 返回对应的流 如果没有则创建
- (WCommonStream *_Nonnull)streamWithType:(WStreamType)type channel:(long)channel;

/// 获取所有流
- (NSArray <WCommonStream *>*)allStreams;


@end

NS_ASSUME_NONNULL_END
