//
//  ZDKMediaClient.h
//  ZDKMediaFramework
//
//  Created by yanyueya on 2017/6/28.
//  Copyright © 2017年 Mouse. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PlayerManager.h"
#import "MediaCallBackDelegate.h"
#import "P2PPlayManager.h"
#import "P2PRecordVideoManager.h"
#import "Server.h"
#import "MessageManager.h"
#import "NetApiManager.h"

@interface MediaClient : NSObject

/*
 * Get the underlying library version number
 */
@property (nonatomic, strong, readonly) NSString *version;

/*
 * Get the underlying library updates
 */
@property (nonatomic, strong, readonly) NSString *updateInfo;

/*
 *  stream type 0: The main stream 1: The sub stream, Default is 0.
 */ 
@property (nonatomic, assign) NSInteger streamType;

/*
 *  PaaS server domain name
 */
@property (nonatomic, strong, readonly) NSString *paasIoTDomainUrl;

/*
 *  mq server
 */
@property (nonatomic, strong) NSString *mqServerPrefix;

/*
 *  SDK internal use
 */
@property (nonatomic, assign) BOOL isJclink_mobile_Init;

/*
 * Player module( NO P2P)
 */
@property (nonatomic, strong) id<PlayerManager>playerManager;

/*
 * P2PLive
 */
@property (nonatomic, strong) id<P2PPlayManager>p2pManager;

/*
 * P2PRecord
 */
@property (nonatomic, strong) id<P2PRecordVideoManager>p2pRecordManager;
 
/*
* message
*/
@property (nonatomic, strong) id<MessageManager>messageManager;

/*
 * network api
 */
@property (nonatomic, strong) id<NetApiManager>netApiManager;

/*
 * initialization
 */
+ (instancetype)sharedClient;

/**
 rtmp Initialization

 @param server    SDK Service Defaults 0
 @param serverPath SDK Service authentication address

 */
-(NSString*)MediaWithServer:(NSString*)server andWithServerURL:(NSString*)serverPath;

/*
 * Uninitialize
 */
- (void)unInit;

/*
 * Set heartbeat
 * @param PAASHeart Heartbeat address
 * @param PAASPort Heartbeat port
 * @param userID  userID
 */
- (void)setPAASHeart:(NSString *)PAASHeart PAASPort:(NSString *)PAASPort;
/*
 *  Add EventCallBack
 *  @param aDelegate  Delegate
 */
- (void)addEventDelegate:(id<CallBackEventDelegate>)aDelegate;

/*
 *  Remove EventCallBack
 *  @param aDelegate  Delegate
 */
- (void)removeEventDelegate:(id)aDelegate;


/**
 P2P Initialization 
 */
-(NSString*)greatP2P;

/**
 P2P Initialization
 @param server    server config
 */
-(NSString*)greatP2PWithServer:(Server *)server;

/**
releaseP2PUnlink
 */
-(void)releaseP2PUnlink;

/// Turn off log printing, Default is on.
- (void)setLogOFF;

@end
