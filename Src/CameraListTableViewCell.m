//
//  CameraListTableViewCell.m
//  SoDemonApple
//
//  Created by feng on 16/5/10.
//  Copyright © 2016年 sandy. All rights reserved.
//

#import "CameraListTableViewCell.h"

@implementation CameraListTableViewCell{
        
    __weak IBOutlet UILabel *labelCamStatus;

    __weak IBOutlet UILabel *labelCamID;
}

- (void)awakeFromNib {
    // Initialization code
}

-(void)showCameraInfo:(IPCam*)ipcam{
    
    labelCamID.text = [NSString stringWithFormat:@"ID:%@",[ipcam camera_id]];
    if ([ipcam status] == IPCAM_STATUS_CONNECTED ) {
        labelCamStatus.text = @"status:connect success";
    }

    else if ([ipcam status] == IPCAM_STATUS_IDLE ){
        if ([ipcam error] == IPCAM_ERROR_BAD_AUTH ) {
            labelCamStatus.text = @"status:connect fail,password error";

        }
        else if ([ipcam error] == IPCAM_ERROR_P2P_DEVICE_OFFLINE) {
            labelCamStatus.text = @"status:connect fail,device offline";
        }
        else{
            labelCamStatus.text = @"status:connect fail,other error";
        }
    }
    else{
        labelCamStatus.text = @"status:connecting...";
    }
}



@end
