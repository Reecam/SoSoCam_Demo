//
//  CameraListViewController.h
//  SoDemonApple
//
//  Created by feng on 16/5/10.
//  Copyright © 2016年 sandy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IPCamMgr.h"
#import "IPCam.h"

@interface CameraListViewController : UIViewController<UITableViewDataSource,UITableViewDelegate,IPCamDelegate>

@end
