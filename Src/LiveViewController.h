//
//  LiveViewController.h
//  SoDemonApple
//
//  Created by sandy on 16/5/10.
//  Copyright © 2016年 sandy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IPCam.h"
#import "IPCamVideoView.h"

@interface LiveViewController : UIViewController<IPCamDelegate,IPCamVideoViewDelegate,UITextFieldDelegate>

-(instancetype)initWithIPCam:(IPCam *)ipcam;

@end
