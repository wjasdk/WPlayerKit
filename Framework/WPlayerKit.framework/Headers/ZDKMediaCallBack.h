//
//  ZDKMediaCallBack.h
//  ZDKMediaFramework
//
//  Created by yanyueya on 2017/6/30.
//  Copyright © 2017年 Mouse. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MediaCallBackDelegate.h"

@interface ZDKMediaCallBack : NSObject

//Low-level event callbacks
@property (nonatomic, weak) id<CallBackEventDelegate>eventDelegate;

//shareIntance
+ (ZDKMediaCallBack *)shareIntance;

@property (nonatomic, assign) int play_id;
@property (nonatomic, copy) void(^downLoadVideoPlayCompleteBlock)(void);
@property (nonatomic, copy) void(^turnAuthenticationErrorBlock)(void);  
@property (nonatomic, copy) void(^privateEventCompleteBlock)(ZDKCallBackEvent callBack, NSDictionary *infoDic);
@property (nonatomic, copy) void(^privateEventOpenStreamBlock)(ZDKCallBackEvent callBack, NSDictionary *infoDic, NSString *privateDeviceId);
@property (nonatomic, copy) void(^privateEventP2PMsgReportStateBlock)(ZDKCallBackEvent callBack, NSDictionary *infoDic, NSString *privateDeviceId);

//Add Event Callbacks
- (void)addEventCallback;

//Video Progress Callback
- (void)addPlayProgressCallback;

//TF card information Callback
- (void)addTFCallback;

// Mqtt Theme callback
- (void)addMqttTopicCallBack;

// Set the publish function
- (void)addP2PSendMsgCallback;

- (void)callbackEvent:(NSDictionary*)dic;

@end
