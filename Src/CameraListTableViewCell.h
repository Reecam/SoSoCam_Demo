//
//  CameraListTableViewCell.h
//  SoDemonApple
//
//  Created by feng on 16/5/10.
//  Copyright © 2016年 sandy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IPCam.h"

@interface CameraListTableViewCell : UITableViewCell

-(void)showCameraInfo:(IPCam*)ipcam;
@end
