//
//  ZDKBeautyControl.h
//  ZDKMediaFramework
//
//  Created by yanyueya on 2017/6/30.
//  Copyright © 2017年 Mouse. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//Beauty settings
typedef NS_ENUM(NSInteger, VideoFilterType) {
    VideoFilter_Original, //normal
    VideoFilter_Beauty //Beauty
};

@interface ZDKBeautyControl : NSObject

@property (nonatomic, strong ) UIView *previewView;

/*
  frame
 */
- (void)initFrame:(CGRect)frame bitRate:(NSString *)bitRate;

/*
  filter
 */
- (void)initFilterVideoWidth:(int)videoWidth videoHeight:(int)videoHeight;

/*
 Set Automatic code rate
 */
- (void)setAutoBitRate:(BOOL)isAuto;

/*
 Beauty effect
 */
- (void)setFilterType:(VideoFilterType)type;

/*
 Beauty Level(1-5)
 */
- (void)setFilterLevel:(int)level;

/*
 Enter video stream
 */
- (void)inputVideoBuffer:(CVPixelBufferRef)videoBuffer;

/*
 Screenshot
 */
- (void *)captureVideo;

/*
UnInit
 */
- (void)unInit;

@end
