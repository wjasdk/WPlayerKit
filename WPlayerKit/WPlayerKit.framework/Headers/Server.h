//
//  Server.h
//  ZDKMediaFramework
//
//  Created by xianjun on 2018/6/15.
//  Copyright © 2018年 Mouse. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 Server environment enumeration

 - ServerConfigRelease: China Public Cloud / (中国公有云)
 - ServerConfigDebug: test
 ServerConfigReleaseAS：Public cloud in Asia (Asia Pacific, excluding China) / (亚洲公有云(亚太地区,不含中国))
 ServerConfigReleaseNA：North American public cloud / (北美)
 ServerConfigReleaseEU：European public clouds / (欧洲公有云)
 ServerConfigReleaseIN：Public clouds in India / (印度公有云)
 */
typedef NS_ENUM(NSUInteger, ServerConfig) {
    ServerConfigRelease,
    ServerConfigDebug,
    ServerConfigReleaseAS,
    ServerConfigReleaseNA,
    ServerConfigReleaseEU,
    ServerConfigReleaseIN,
};

extern NSString *const kUserDefaultsServerKey;

@interface Server : NSObject

@property (nonatomic, copy) NSString *paasDomain; ///< paas服务器域名

@property (nonatomic, assign) NSInteger paasPort; ///< paas服务器端口

@property (nonatomic, copy) NSString *turnDomain; ///< turn服务器域名

@property (nonatomic, assign) NSInteger turnPort; ///< turn服务器端口

@property (nonatomic, assign) NSInteger serverEnv; ///< 服务器环境

@property (nonatomic, copy) NSString *token; ///< 用户token

@property (nonatomic, copy) NSString *objIdentify; ///< 标识，没什么特别作用

@property (nonatomic, copy) NSString *authServerUrl; ///< 鉴权地址

@property (nonatomic, copy) NSString *access_key;

@property (nonatomic, copy) NSString *secret_key;

@property (nonatomic, copy) NSString *appid;

@property (nonatomic, copy) NSString *wmqS;

/**
 initialization

 @return server config   default is ServerConfigRelease
 */
- (instancetype)init;

/**
 initialization

 @param serverConfig   default is ServerConfigRelease
 @return server config
 */
- (instancetype)initWithServerConfig:(ServerConfig)serverConfig;


/**
 initialization

 @param paasDomain paas domain
 @param paasPort paas port
 @param turnDomain turn domain
 @param turnPort turn port
 @param authServerUrl auth server url
 @param token user token
 @return server config
 */
- (instancetype)initWithPaasDomain:(NSString *)paasDomain paasPort:(NSInteger)paasPort turnDomain:(NSString *)turnDomain turnPort:(NSInteger)turnPort authServerUrl:(NSString *)authServerUrl token:(NSString *)token;

- (instancetype)initWithPaasDomain:(NSString *)paasDomain
                          paasPort:(NSInteger)paasPort
                        turnDomain:(NSString *)turnDomain
                          turnPort:(NSInteger)turnPort
                     authServerUrl:(NSString *)authServerUrl 
                        regionName:(NSString *)regionName
                         accessKey:(NSString *)access_key
                         secretKey:(NSString *)secret_key
                             appId:(NSString *)appId;

@end
