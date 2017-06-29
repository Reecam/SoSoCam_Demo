//
//  CameraListViewController.m
//  SoDemonApple
//
//  Created by feng on 16/5/10.
//  Copyright © 2016年 sandy. All rights reserved.
//

#import "CameraListViewController.h"
#import "CameraListTableViewCell.h"
#import "AddCameraViewController.h"
#import "LiveViewController.h"
#import "lanCameraViewController.h"

@interface CameraListViewController (){
    NSArray *ipcamList;
    
}
@property (weak, nonatomic) IBOutlet UITableView *tabelViewCameraList;

@end

@implementation CameraListViewController

-(void)addDelegateToEveryIpcam{
    for (int i = 0; i< ipcamList.count; i++) {
        IPCam * cam = [ipcamList objectAtIndex:i];
        [cam add_delegate:self];
    }
}
-(void)removeDelegateToEveryIpcam{
    for (int i = 0; i< ipcamList.count; i++) {
        IPCam * cam = [ipcamList objectAtIndex:i];
        [cam remove_delegate:self];
    }
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationItem.title = @"Camera List";
}
-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    ipcamList = [[IPCamMgr get_share]get_cameras_list];
    [self addDelegateToEveryIpcam];
    [self.tabelViewCameraList reloadData];
}

-(void)viewWillDisappear:(BOOL)animated{
    [super viewWillDisappear:animated];
    [self removeDelegateToEveryIpcam];
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}
- (IBAction)buttonSearchAction:(id)sender {
    lanCameraViewController* lanVC = [[lanCameraViewController alloc]init];
    [self.navigationController pushViewController:lanVC animated:YES];
}
- (IBAction)buttonAddAction:(id)sender {
    AddCameraViewController* addVC = [[AddCameraViewController alloc]init];
    [self.navigationController pushViewController:addVC animated:YES];
}

#pragma mark UITableViewDataSource&UITableViewDelegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return ipcamList.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    static NSString *cellID =@"CameraListTableViewCell";
    CameraListTableViewCell * cell = (CameraListTableViewCell*)[self.tabelViewCameraList dequeueReusableCellWithIdentifier:cellID];
        if (cell == nil) {
            NSArray *array = [[NSBundle mainBundle]loadNibNamed:@"CameraListTableViewCell" owner:self options:nil];
            cell = [array objectAtIndex:0];
        }
    [cell showCameraInfo:[ipcamList objectAtIndex:indexPath.row]];
        return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 72;
}
- (NSIndexPath *)tableView:(UITableView *)tableView
  willSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    LiveViewController * liveVC = [[LiveViewController alloc]initWithIPCam:[ipcamList objectAtIndex:indexPath.row]];
    [self.navigationController pushViewController:liveVC animated:YES];
    return nil;
}

#pragma mark IPCamDelegate
-(void)on_alias_changed:(id)ipcam{
    
}

-(void)on_cover_changed:(id)ipcam{
    
}

-(void)on_status_changed:(id)ipcam{
    [self.tabelViewCameraList reloadData];
}

-(void)on_video_status_changed:(id)ipcam{
    
}
-(void)on_audio_status_changed:(id)ipcam{
    
}
-(void)on_camera_ewig_status_changed: (id)ipcam {}

-(void)on_speak_status_changed:(id)ipcam{
    
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

-(void)on_camera_sessions_change:(id)ipcam{
    
}
-(void)on_camera_juyang_led_changed:(id)ipcam {}

-(void)on_camera_tf_capacity:(id)ipcam{
    
}

@end
