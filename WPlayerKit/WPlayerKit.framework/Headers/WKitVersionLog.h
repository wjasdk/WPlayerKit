//
//  WKitVersionLog.h
//  WPlayerKit
//
//  Created by List on 14/4/2022.
//  Copyright © 2022 List. All rights reserved.
//

#ifndef WKitVersionLog_h
#define WKitVersionLog_h


#endif /* WKitVersionLog_h */
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V1.5.6_2211111400
编译时间：2022.11.11
更新内容：1、优化WMediaControl、WVideoPlayView等的方法；2、底层ESP32逻辑优化；3、优化鉴权地址的使用
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.2.0_2211141400
编译时间：2022.11.14
更新内容：1、优化内部TF分页逻辑
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.2.0_2211171400
编译时间：2022.11.17
更新内容：1、优化[_MTLCommandBuffer presentDrawable:]问题；2、音频流增删逻辑优化
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.2.0_2211211800
编译时间：2022.11.21
更新内容：1、优化 networkStatusForFlags
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.2.0_2211241800
编译时间：2022.11.24
更新内容：1、4G球机IP解析优化；2、增加自定义缩放WZoomSuperView
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.2.0_2212061000
编译时间：2022.12.06
更新内容：1、内部调整对讲模块方案，增强对讲体验
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.2.0_2212082033
编译时间：2022.12.08
更新内容：1、音频播放兼容采样率不正确的设备，解决部分设备变声问题；2、修复视频卡住、broken时deviceId为空的情况
---------------------------------------------------------------------------------------- 
IOT平台SDK，SDK_P2P_IOS_V2.3.0_2303021200
编译时间：2023.03.02
更新内容：1、调整SDK初始化内部逻辑（goturn）；
        2、新增BaseEvent_Code_Msg_Turn_Authentication_Error、BaseEvent_Code_Msg_Ips_Error、BaseEvent_Code_Msg_Peer_Ips_Error
        3、解决MetalRender问题
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.3.0_2303081530
编译时间：2023.03.08
更新内容：1、修复低概率p2p ping、onData崩溃问题；
        2、客户端信息获取做缓存处理，增强初始化效率
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.3.1_2305121300
编译时间：2023.05.12
更新内容：1、p2p增加双链路模式，增加稳定性
        2、P2P网络探测实时监测
        3、网络切换时不用重新打洞加流
        4、音频播放权限兼容其它第三方APP，不抢占
        5、门锁音频增加放大方法
---------------------------------------------------------------------------------------- 
IOT平台SDK，SDK_P2P_IOS_V2.2.2_2212301030
编译时间：2022.12.30
更新内容：1、增加P2P打洞加流的日志上报；2、P2P解决UDTConnect闪退问题
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.2.2_2301041630
编译时间：2023.01.04
更新内容：1、解决云告警播放低概率花屏问题；2、解决门锁录制视频无法播放问题
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.2.2_2301091630
编译时间：2023.01.09
更新内容：1、修复云回放静音时录制的视频有声音；2、云回放暂停后支持截图
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.4.0_2302202000
编译时间：2023.02.20
更新内容：1、增加倍数播放；2、增加TF卡中的告警视频播放；3、增加网络探测
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.4.0_2303032000
编译时间：2023.03.03
更新内容：1、修复ondata、metalRender闪退问题；2、优化告警下载功能；3、静音模式支持音频播放
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.4.0_2303042230
编译时间：2023.03.04
更新内容：1、云回放开始录制回调事件；2、修复告警播放结束还有声音问题
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.4.0_2303061430
编译时间：2023.03.06
更新内容：1、解决升级接口重复调导致时序乱
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.4.0_2303151200
编译时间：2023.03.15
更新内容：1、对讲模块增加音频数据外抛方法
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.4.0_2303201418
编译时间：2023.03.20
更新内容：1、优化CPU占有率高
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.4.1_2303221039
编译时间：2023.03.22
更新内容：1、优化告警下载速度；2、mjpeg格式播放；3、直播延时优化
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.4.1_2303291730
编译时间：2023.03.29
更新内容：1、mjpeg播放优化，体验更佳；2、增加枚举回调BaseEvent_Code_License_Rule_Failure（设备规则鉴权未通过/设备无流量/设备被禁用）
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.4.3_2304211000
编译时间：2023.04.21
更新内容：1、修复打洞可能出现send data error/Operation timed out的问题；2、优化倍数播放（4倍）；3、TF视频列表增加version==2类型及优化TF播放方式；4、BaseEvent_Code_Msg_Already_Watching_TFcard（卡回放已经有人在观看）
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.5.0_2304201700
编译时间：2023.04.20
更新内容：1、增加WVideoCaptureView双向通话功能
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.5.0_2304251030
编译时间：2023.04.25
更新内容：1、增加设备主动挂断的回调；2、增加拒绝接听的方法
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.5.1_2305081930
编译时间：2023.05.08
更新内容：1、音频权限模式修改为兼容其它APP，不强制抢占音频权限；2、新增tf获取跟播放方式 tf_version==2；3、S3门锁增加音量控制方法 
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.5.1_2305231530
编译时间：2023.05.23
更新内容：1、将coturn最新稳定版本跟goturn稳定版本进行合并；2、解决太空一号云回放音频播放卡顿问题
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.5.1_2305250932
编译时间：2023.05.25
更新内容：1、网络探测增加网络质量net_quality; //1：质量好，2：质量一般 3：质量差
        2、WZoomSuperView增加resetZoomSuperZero
        3、播放器静音状态下录制视频也静音
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.5.1_2305262100
编译时间：2023.05.26
更新内容：1、完善网络探测调用方法 [[MediaClient sharedClient].netApiManager beginNetworkDetectionDeviceId。。。。。。，调用之后返回结果
        2、WZoomSuperView优化放大缩小 
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.5.1_2305321100
编译时间：2023.05.31
更新内容：1、网络探测增加销毁方法，探测过程中关闭要销毁
        2、优化设备近百台同时打洞的稳定性
        3、网络探测json中增加deliveryRate //送达率
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.5.1_2306021700
编译时间：2023.06.02
更新内容：1、解决网络探测回调可能出现乱码的情况
        2、去掉deliveryRate //送达率
        3、修复断网情况下进行网络探测导致的卡住
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.0_2306191800
编译时间：2023.06.19
更新内容：1、emq集群优化；2、初始化SDK时请求客户端信息；3、tf相关获取直接走mqtt；4、设备id支持非纯数字；5、打洞鉴权改为mqtt发起
       6、unlink闪退问题
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.0_2306201500
编译时间：2023.06.20
更新内容：1、解决p2p异常unlink不及时，针对WMediaControl类
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.0_2306261030
编译时间：2023.06.26
更新内容：1、p2p打洞获取外网ip时增加重试机制；2、turn连接失败时自动切换到别的turn；3、修复反初始化可能出现闪退问题； 4、release环境下增加音视频回调的打印
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.0_2306300930
编译时间：2023.06.30
更新内容：1、NetApiManager信令请求成功增加code==4418；2、修复BaseEvent_Code_Msg_Turn_Authentication_Error问题；
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.1_2307061530
编译时间：2023.07.06
更新内容：1、结束录像增加BaseEvent_Code_Record_Finish；2、setSurfaceAdaptiveType增加设置16:9/铺满的方法
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.2_2307241130
编译时间：2023.07.24
更新内容：1、修复告警播放可能没声音的问题；2、增加Q45APP主动呼叫方法initiateCallDeviceId；3、音频播放可切换听筒/扬声器 setAudioCategoryLoudspeaker
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.2_2307251400
编译时间：2023.07.25
更新内容：1、增加获取mq域名的前缀 [MediaClient sharedClient].mqServerPrefix
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.3_2307271800
编译时间：2023.07.27
更新内容：1、手机采集的视频支持裁剪为480*480，默认为yes；2、mq断开策略修改；3、初始化SDK时获取客户端信息的接口改为V2
        4、setstatus/getstatus增加-2状态
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.3_2308111400
编译时间：2023.08.11
更新内容：1、修复MetaCore MetalRender渲染闪退；2、修复卡回放频繁拖动卡死并闪退；3、修复p2pUnlinkTask闪退；4、修复加流成功还会P2P Error；
        5、修复断流时横竖屏切换没有按比例显示；6、修复扬声器/听筒切换时低版本手机兼容性问题
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.3_2309111000；RTC_P2P_IOS_V2.0.9_2308290958
编译时间：2023.09.11
更新内容：1、解决云回放播放结束跟结束录制冲突；2、解决频繁暂停、恢复 云回放导致状态错乱；3、云回放断网播放异常；
        4、音视频信号量机制修改为条件变量；5、playVideoByP2PDevicePwd枚举返回增加 低功耗设备唤醒成功/低功耗设备唤醒失败；6、优化turn列表连接速度
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.3_2309121440；RTC_P2P_IOS_V2.0.9_2308290958
编译时间：2023.09.12
更新内容：1、修复设备离线时异常回调是子线程
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.3_2309151800；RTC_P2P_IOS_V2.0.9_2309151719
编译时间：2023.09.15
更新内容：1、播放器结束录制去掉最小时间；2、解决部分视频播放可能花屏问题
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.3_2310161830；RTC_P2P_IOS_V2.0.10_2310161840
编译时间：2023.10.16
更新内容：1、主动呼叫到设备的协议修改及兼容老固件；2、MQTT增加连接状态的全局通知 WPlayerKitMQTTSessionManagerStateChangeState
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.3_2310171430；RTC_P2P_IOS_V2.0.10_2310161840
编译时间：2023.10.17
更新内容：1、WVideoCaptureView双向视频通话支持自定义裁剪
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.3_2310181700；RTC_P2P_IOS_V2.0.10_2310181640
编译时间：2023.10.18
更新内容：1、解决云回放录像时暂停导致结束录制没有回调；2、音频被占用及恢复的回调优化
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.3_2311011800；RTC_P2P_IOS_V2.0.11_2310311119
编译时间：2023.11.01
更新内容：1、解决门锁G711U无法播放音频；2、增加系统相机录制功能、可自定义裁剪大小WVideoRecorderView；
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.5_2311071450；RTC_P2P_IOS_V2.0.11_2311061002
编译时间：2023.11.07
更新内容：1、修复卡回放播放卡顿时有声音传出（音画不同步）；2、优化P2P unlink逻辑；
        3、WZoomSuperView增加supportStartRollAction 兼容上层手势冲突；4、修复WVideoCaptureView主动呼叫成功后会回调failure
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.6_2311131800；RTC_P2P_IOS_V2.0.14_2311131109
编译时间：2023.11.13
更新内容：1、P2P修复直播卡顿问题；2、设备跟手机处于同一局域网时优先走“直连模式”；3、优化双向视频通话的视频裁剪比例算法，增加稳定性；4、优化P2P网络切换重连机制
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.7_2311241330；RTC_P2P_IOS_V2.0.14_2311241125
编译时间：2023.11.24
更新内容：1、修复卡回放加载过程中出现声音；2、增加打洞的打印；3、优化音频播放初始化逻辑（ADTS头解析）；4、P2P打洞混合模式优化；5、WVideoCaptureView增加提前预览方法
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.7_2311271600；RTC_P2P_IOS_V2.0.14_2311241125
编译时间：2023.11.27
更新内容：1、修复视频通话时切换扬声器无效
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.7_2311281700；RTC_P2P_IOS_V2.0.14_2311241125
编译时间：2023.11.28
更新内容：1、修复低概率打洞线程卡住导致视频打不开
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.7_2311301400；RTC_P2P_IOS_V2.0.14_2311241125
编译时间：2023.11.30
更新内容：1、修复多通道截图对应不上；2、摄像头采集过滤掉首帧黑色问题
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.8_2312021200；RTC_P2P_IOS_V2.0.14_2312021120
编译时间：2023.12.02
更新内容：1、对讲支持多通道传输；2、主动呼叫超时逻辑优化；3、无网到有网网络变化时立马主动尝试mq重连；4、优化手机视频采集、前后置摄像头切换及裁剪逻辑
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.8_2312041900；RTC_P2P_IOS_V2.0.14_2312021120
编译时间：2023.12.04
更新内容：1、解决频繁切换后台跟网路时打不开视频一直转圈
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.8_2312061150；RTC_P2P_IOS_V2.0.14_2312021120
编译时间：2023.12.06
更新内容：1、优化MQTT网络切换重连机制；2、解决网络频繁切换并获取卡回放列表重复问题
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.8_2312111530；RTC_P2P_IOS_V2.0.15_2312111523
编译时间：2023.12.11
更新内容：1、解决分享的用户唤醒低功耗设备时无法获得在线状态；2、解决BaseEvent_Code_Msg_Already_Watching_TFcard没有回调；3、P2P解决unlink时update_events闪退
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.9_2401081000；RTC_P2P_IOS_V2.0.19_2401080947；OTEL_SDK_IOS_V1.0.1_2401051512
编译时间：2024.01.08
更新内容：1、WVideoCaptureView视频采集增加缩放机制和新增实际帧率参数；
        2、OTEL数据上报及日志监控系统数据上报，APP需设置setTalkMode参数；
        3、WVideoRecorderView相机视频录制增加启动成功的回调，避免录制时间不一致和丢声音问题；
        4、WVideoRecorderView录制视频的码率由原来的300改为800，提升清晰度；
        5、开启对讲增加启动完成的回调
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.9_2401081900；RTC_P2P_IOS_V2.0.19_2401080947；OTEL_SDK_IOS_V1.0.1_2401081855
编译时间：2024.01.08
更新内容：1、修复退出登录时otel闪退的问题
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.9_2401151800；RTC_P2P_IOS_V2.0.19_2401080947；OTEL_SDK_IOS_V1.0.1_2401151735
编译时间：2024.01.15
更新内容：1、修复otel卡死主线程导致APP闪退问题；2、优化视频是否播放中的方法
----------------------------------------------------------------------------------------
IOT平台SDK，SDK_P2P_IOS_V2.6.9_2401161730；RTC_P2P_IOS_V2.0.19_2401080947；OTEL_SDK_IOS_V1.0.1_2401161729
编译时间：2024.01.16
更新内容：1、修复退出登录时otel闪退问题
----------------------------------------------------------------------------------------
当前版本
IOT平台SDK，SDK_P2P_IOS_V2.7.0_2401251730；RTC_P2P_IOS_V2.0.20_2401251710；OTEL_SDK_IOS_V1.0.1_2401161729
编译时间：2024.01.25
更新内容：1、优化turnlist获取逻辑，增加成功率（基于订阅成功，海外环境订阅慢）；2、优化杀死APP时otel会上报崩溃日志到bugly；
        3、优化监控系统数据上报低概率崩溃问题；4、P2P优化直播卡顿及延迟
----------------------------------------------------------------------------------------



