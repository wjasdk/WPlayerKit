//
//  ZDKPlayVideoView.h
//  ZDKMediaFramework
//
//  Created by UI design on 2017/4/24.
//  Copyright © 2017年 Mouse. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MetalKit/MetalKit.h>

@interface ZDKPlayVideoView : MTKView

/// 播放器ID，内部生成，可做播放器的唯一标识
@property (nonatomic, copy) NSString *playID;

/// 设备ID
@property (nonatomic, copy) NSString *deviceId;

/// 设置渲染按16:9适配或铺满，默认YES=16:9, NO=铺满
@property (nonatomic, assign) BOOL surfaceAdaptive;

@end
