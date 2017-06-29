//
//  LiveViewController.m
//  SoDemonApple
//
//  Created by sandy on 16/5/10.
//  Copyright © 2016年 sandy. All rights reserved.
//

#import "LiveViewController.h"

@interface LiveViewController (){
    
    __weak IBOutlet IPCamVideoView *viewVideo;
    __weak IBOutlet UIButton *buttonMic;
    __weak IBOutlet UIButton *buttonSDWihtHD;
    __weak IBOutlet UIButton *buttonHZ;
    __weak IBOutlet UIButton *buttonRecord;
    __weak IBOutlet UIButton *buttonSpeaker;
    
    __weak IBOutlet UILabel *labelTips;
    IPCam*liveCam;

    
}

@end

@implementation LiveViewController

-(instancetype)initWithIPCam:(IPCam *)ipcam
{
    self = [super init];
    if (! self)
        return nil;
    
    liveCam = ipcam;
    
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationItem.title = @"Live Video";
    [IPCamVideoView class];
}
-(void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    [liveCam set_video_view:viewVideo];//设置视频
    [liveCam play_video:0];//播放视频 640*960
    /*
     *添加代理IPCamDelegate
     */
    [liveCam add_delegate:self];
    
    /*
     *需要在视频上添加手势时，添加代理IPCamVideoViewDelegate
     */
    [viewVideo set_delegate:self];
    
    /*
     *因为此demon只设置两种hz，所以此处
     *把hz默认设置为50hz
     */
    [liveCam sensor_control:IPCAM_SENSOR_CMD_POWER_FREQUENCY param:1];
    
}
-(void)viewWillDisappear:(BOOL)animated{
    [super viewWillDisappear:animated];
    [liveCam stop_audio];
    [liveCam stop_video];
    [liveCam stop_speak];
    [liveCam stop_local_record];
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
#pragma mark buttonAction
- (IBAction)buttonMicAction:(id)sender {
    if ([liveCam status] != IPCAM_STATUS_CONNECTED) {
        labelTips.text = @"Tips:device disconnect";
        return;
    }
    
    if ([liveCam audio_status] == IPCAM_PLAY_STATUS_STOPPED) {
        [liveCam play_audio];
    }
    else{
        [liveCam stop_audio];
    }
}
- (IBAction)buttonSDWihtHDAction:(UIButton*)sender {
    if ([liveCam status] != IPCAM_STATUS_CONNECTED) {
        labelTips.text = @"Tips:device disconnect";
        return;
    }
    [liveCam stop_video];
    sender.selected = !sender.selected;
    if (sender.selected) {
        [liveCam play_video:1];
        labelTips.text = @"Tips:play 640*360";
    }
    else{
        [liveCam play_video:0];
        labelTips.text = @"Tips:play 1280*720";
    }
}
- (IBAction)buttonHZAction:(UIButton*)sender {
    if ([liveCam status] != IPCAM_STATUS_CONNECTED) {
        labelTips.text = @"Tips:device disconnect";
        return;
    }
    sender.selected = !sender.selected;
    /*
     *设置室外如下，此处就不列举了
     *[liveCam sensor_control:IPCAM_SENSOR_CMD_POWER_FREQUENCY param:2];
     */
    if (sender.selected) {
        [liveCam sensor_control:IPCAM_SENSOR_CMD_POWER_FREQUENCY param:0];
        labelTips.text = @"Tips:settings 60hz success";
    }
    else{
        [liveCam sensor_control:(IPCAM_SENSOR_CMD_POWER_FREQUENCY) param:1];
        labelTips.text = @"Tips:settings 50hz success";
    }
    
}

- (IBAction)buttonRecordAction:(UIButton*)sender {
    if ([liveCam status] != IPCAM_STATUS_CONNECTED) {
        labelTips.text = @"Tips:device disconnect";
        return;
    }
    if (!sender.selected) {
        if (IPCAM_ERROR_NO_ERROR == [liveCam start_local_record]) {
            sender.selected = YES;
            labelTips.text = @"Tips:camera record start";
        }
    }
    else{
        [liveCam stop_video];
        sender.selected = NO;
        labelTips.text = @"Tips:camera record stop";
    }

}
- (IBAction)buttonSpeakerAction:(id)sender {
    if ([liveCam status] != IPCAM_STATUS_CONNECTED) {
        labelTips.text = @"Tips:device disconnect";
        return;
    }
    if ([liveCam speak_status] == IPCAM_PLAY_STATUS_STOPPED) {
        [liveCam start_speak];
    }
    else{
        [liveCam stop_speak];
    }
}
- (IBAction)buttonSnapshotAction:(id)sender {
    if ([liveCam status] != IPCAM_STATUS_CONNECTED) {
        labelTips.text = @"Tips:device disconnect";
        return;
    }
    [liveCam snapshot];
    labelTips.text = @"Tips:camera snapshot success";

}

#pragma mark IPCamVideoViewDelegate

-(void)on_touch_event:(IPCAMVIDEOVIEW_TOUCH_EVENT)event{
    /*
     *在此实现视频上的各个手势功能
     */
}

#pragma mark IPCamDelegate
-(void)on_alias_changed:(id)ipcam{
    
}

-(void)on_cover_changed:(id)ipcam{
    
}

-(void)on_status_changed:(id)ipcam{
    if ([liveCam status] ==  IPCAM_STATUS_CONNECTED) {
        labelTips.text = @"Tips:camera connect success";
    }
    else if([liveCam status] == IPCAM_STATUS_IDLE){
        labelTips.text = @"Tips:camera connect break";
    }
    else{
        labelTips.text = @"Tips:camera connecting";
    }
}

-(void)on_video_status_changed:(id)ipcam{
    if ([liveCam video_status] == IPCAM_PLAY_STATUS_PLAYING) {
        labelTips.text = @"Tips:camera video play";
    }
    else if([liveCam video_status] == IPCAM_PLAY_STATUS_REQUESTING){
        labelTips.text = @"Tips:camera video requesting";
    }
    else{
        labelTips.text = @"Tips:camera video stop";
    }
}
-(void)on_camera_ewig_status_changed: (id)ipcam {}
-(void)on_audio_status_changed:(id)ipcam{
    if ([liveCam audio_status] == IPCAM_PLAY_STATUS_STOPPED) {
        buttonMic.selected = NO;
        labelTips.text = @"Tips:camera audio stop";
    }
    else{
        buttonMic.selected = YES;
        labelTips.text = @"Tips:camera audio start";
    }
}

-(void)on_speak_status_changed:(id)ipcam{
    if ([liveCam speak_status] == IPCAM_PLAY_STATUS_STOPPED) {
        buttonSpeaker.selected = NO;
        labelTips.text = @"Tips:camera speaker stop";
    }
    else{
        buttonSpeaker.selected = YES;
        labelTips.text = @"Tips:camera speaker start";
    }
}

-(void)on_tf_record_status_changed:(id)ipcam{
    
}

-(void)on_tf_record_event:(id)ipcam
               new_record:(BOOL)new_record
                record_id:(int32_t)record_id
                    error:(BOOL)error{
    
}

-(void)on_camera_tf_changed:(id)ipcam{
    
}

-(void)on_camera_wifi_changed:(id)ipcam{
    
}

-(void)on_camera_alarm_changed:(id)ipcam{
    
}

-(void)on_bell_alarm_changed:(id)ipcam{
    
}

-(void)on_camera_recording_changed:(id)ipcam{
    
}

-(void)on_camera_can_upgrade:(id)ipcam{
    
}

-(void)on_camera_power_down_changed:(id)ipcam{
    
}

-(void)on_camera_arm_changed:(id)ipcam{
    
}

-(void)on_camera_dijia_power_changed:(id)ipcam{
    
}

-(void)on_camera_dijia_speed_changed:(id)ipcam{
    
}

-(void)on_camera_dijia_mute_changed:(id)ipcam{
    
}

-(void)on_camera_dijia_status_changed:(id)ipcam{
    
}

-(void)on_statistic:(id)ipcam{
    
}

-(void)on_can_set_video_performance:(id)ipcam{
    
}

-(void)on_camera_temperature_changed:(id)ipcam{
    
}

-(void)on_camera_meijing_play_changed:(id)ipcam{
    
}

-(void)on_camera_meijing_led_changed:(id)ipcam{
    
}
-(void)on_camera_juyang_led_changed:(id)ipcam{}

-(void)on_camera_sessions_change:(id)ipcam{
    
}

-(void)on_camera_tf_capacity:(id)ipcam{
    
}


@end
