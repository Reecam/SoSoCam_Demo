//
//  IPCamMgr.h
//  SoSoCamSDK
//
//  Created by Maverick Gao on 15-1-3.
//  Copyright (c) 2015年 reecam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IPCam.h"

typedef enum {
    IPCAMMGR_NETWORK_DOWN,
    IPCAMMGR_NETWORK_WIFI,
    IPCAMMGR_NETWORK_MOBILE,
} IPCAMMGR_NETWORK_TYPE;

@protocol IPCamMgrDelegate

-(void)on_camera_added:(NSString *)camera_id;

-(void)on_camera_removed:(NSString *)camera_id;

-(void)on_cameras_cleared;

@end


@interface IPCamMgr : NSObject

+(IPCamMgr *)get_share;

+(void)release_share;

-(void)start;

-(void)stop;

//  every element in NSArray returned is type of NSDictionary
//  key/value:
//  camera_id/NSString *
//  id_type/NSNumber * /int32_t
//  alias/NSString *
//  fw_version/NSString *
//  ui_version/NSString *
//  model/NSNumber */int32_t
//  dhcp/NSNumber */BOOL
//  ip/NSString *
//  mask/NSString *
//  gateway/NSString *
//  dns1/NSString *
//  dns2/NSString *
//  current_ip/NSString *
//  current_mask/NSString *
//  port/NSNumber */int
//  https/NSNumber */BOOL
//  used/NSNumber */BOOL
-(NSArray *)get_discovered_cameras_list;

//  every element in NSArray returned is type of IPCam *
-(NSArray *)get_cameras_list;

-(IPCam *)get_camera:(NSString *)camera_id;

-(IPCam *)add_camera:(NSString *)camera_id
               alias:(NSString *)alias
                user:(NSString *)user
                 pwd:(NSString *)pwd
               https:(BOOL)https;

-(IPCam *)remove_camera:(NSString *)camera_id;

-(void)clear_cameras_list;

-(void)reset_camera:(NSString *)camera_id;

-(void)update_camera_user:(NSString *)camera_id
                     user:(NSString *)user;
-(void)update_camera_pwd:(NSString *)camera_id
                     pwd:(NSString *)pwd;

-(void)add_delegate:(id<IPCamMgrDelegate>)delegate;

-(void)remove_delegate:(id<IPCamMgrDelegate>)delegate;

-(IPCam *)get_disposable_camera;

-(BOOL)set_disposable_camera:(NSString *)camera_id
                        user:(NSString *)user
                         pwd:(NSString *)pwd
                       https:(BOOL)https;

-(void)clear_disposable_camera;

-(BOOL)update_disposable_camera_pwd:(NSString *)pwd;

-(BOOL)reset_disposable_camera;

-(void)rediscover_cameras;

-(void)set_forbidden_in_mobile:(BOOL)forbidden_in_mobile;

-(IPCAMMGR_NETWORK_TYPE)get_network_type;

@end
