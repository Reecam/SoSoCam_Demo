//
//  AddCameraViewController.m
//  SoDemonApple
//
//  Created by sandy on 16/5/10.
//  Copyright © 2016年 sandy. All rights reserved.
//

#import "AddCameraViewController.h"
#import "IPCamMgr.h"
#import "Storage.h"

@interface AddCameraViewController (){
    
    __weak IBOutlet UITextField *textFieldCamID;

    __weak IBOutlet UITextField *textFieldCamUser;
    
    __weak IBOutlet UITextField *textFieldCamPwd;
    
    NSString*lanCamID;

}

@end

@implementation AddCameraViewController

-(instancetype)initWithIPCam:(NSString *)camID;
{
    self = [super init];
    if (! self)
        return nil;
    
    lanCamID = camID;
    
    return self;
}
- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationItem.title =  @"Add Camera";
    textFieldCamID.text = lanCamID;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (IBAction)buttonSaveAction:(id)sender {
        
    /*
     *添加到本地
     */
    [[Storage get_share]add_camera:textFieldCamID.text alias:nil user:textFieldCamUser.text pwd:textFieldCamPwd.text https:NO sosocam_id:nil model:0 master:NO];//
    /*
     *添加到IPCamMgr便于批量管理
     */
    [[IPCamMgr get_share] add_camera:textFieldCamID.text alias:nil user:textFieldCamUser.text pwd:textFieldCamPwd.text https:NO];
    
    /*
     *添加到服务器
     */
    /*
     *如果需要添加到服务器，还需要
     [[WebService get_share] add_camera:[m_ipcam camera_id]
     alias:[m_ipcam alias]
     https:[m_ipcam https]
     model:[m_ipcam model]
     delegate:self]
     *但是因为添加到服务器是一个摄像机只能被一个帐号添加。
     *所以添加之前必须先连接摄像机，连接成功后判断是否被添加，以及解绑等操作
     *详细请参考sdk说明文档之添加摄像机
     */
    
    [self.navigationController popToRootViewControllerAnimated:YES];
}

-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    [textFieldCamUser resignFirstResponder];
    [textFieldCamID resignFirstResponder];
    [textFieldCamPwd resignFirstResponder];
}


#pragma mark  UITextFieldDelegate
- (BOOL)textFieldShouldReturn:(UITextField *)textField              // called when 'return' key pressed. return NO
{
    if ([textField isEqual:textFieldCamUser]) {
        [textFieldCamUser resignFirstResponder];
    }
    else if([textField isEqual:textFieldCamID] ){
        [textFieldCamID resignFirstResponder];
    }
    else if ([textField isEqual:textFieldCamPwd]){
        [textFieldCamPwd resignFirstResponder];
    }
    return YES;
}
@end
