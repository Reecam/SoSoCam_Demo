//
//  IPCamVideoView.h
//  WingedCamSDK
//
//  Created by Maverick Gao on 15-3-11.
//  Copyright (c) 2015年 reecam. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    IPCAMVIDEOVIEW_STATE_PLAYING,
    IPCAMVIDEOVIEW_STATE_PAUSING,
    IPCAMVIDEOVIEW_STATE_BUFFING,
} IPCAMVIDEOVIEW_STATE;

typedef enum {
    IPCAMVIDEOVIEW_TOUCH_EVENT_CLICK,
    IPCAMVIDEOVIEW_TOUCH_EVENT_MOVE_UP,
    IPCAMVIDEOVIEW_TOUCH_EVENT_MOVE_DOWN,
    IPCAMVIDEOVIEW_TOUCH_EVENT_MOVE_LEFT,
    IPCAMVIDEOVIEW_TOUCH_EVENT_MOVE_RIGHT,
} IPCAMVIDEOVIEW_TOUCH_EVENT;

@protocol IPCamVideoViewDelegate

-(void)on_touch_event:(IPCAMVIDEOVIEW_TOUCH_EVENT)event;

@end


@interface IPCamVideoView : UIView

-(void)show_rgb24:(NSData *)rgb24
            width:(int)width
           height:(int)height;

-(void)clear;

-(NSData *)get_current_jpeg;

-(IPCAMVIDEOVIEW_STATE)state;

-(void)set_state:(IPCAMVIDEOVIEW_STATE)state;

-(void)set_delegate:(id<IPCamVideoViewDelegate>)delegate;

-(void)set_keep_image_radio:(BOOL)keep_image_radio;

@end
