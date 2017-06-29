//
//  AppDelegate.m
//  SoDemonApple
//
//  Created by sandy on 16/5/10.
//  Copyright © 2016年 sandy. All rights reserved.
//

#import "AppDelegate.h"
#import "IPCamMgr.h"
#import "IPCam.h"
#import "Storage.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


-(void)loadAllCameras{
    NSArray * ipcamList = [[Storage get_share]get_cameras_list];
    IPCamMgr * ipcamMgr = [IPCamMgr get_share];
    IPCam * cam;
    for (int i = 0; i< ipcamList.count; i++) {
        NSDictionary * camera = [ipcamList objectAtIndex:i];
        cam = [ipcamMgr add_camera:[camera objectForKey:@"camera_id"] alias:[camera objectForKey:@"alias"] user:[camera objectForKey:@"user"] pwd:[camera objectForKey:@"pwd"] https:[[camera objectForKey:@"https"] boolValue]];
        /*
         *如果还需要用到摄像机其他属性，此处应设置到IPCam对象，比如需要用到预览图
         *[cam set_cover:[camera objectForKey:@"cover"]];
         */
    }
}
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    /*
     *初始化sdk
     */
    [IPCamMgr  get_share];
    /*
     *创建和设置一个当前用户
     */
    [[Storage get_share]update_user:@"sandy" login_type:0 auth_name:nil auth_pwd:nil alias:nil];
    [[Storage get_share]set_current_user:@"sandy"];
    /*
     *此app rootview直接使用Main.storyboard
     */
 
    /*
     *加载本地摄像机
     */
    [self loadAllCameras];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    [[IPCamMgr get_share]stop];//停止连接＋停止局域网搜索
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    [[IPCamMgr get_share]start];//开始连接＋开始局域网搜索
}

- (void)applicationWillTerminate:(UIApplication *)application {

    [IPCamMgr release_share];//反初始化
}

@end
