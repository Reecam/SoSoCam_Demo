//
//  lanCameraViewController.m
//  SoDemonApple
//
//  Created by sandy on 16/5/13.
//  Copyright © 2016年 sandy. All rights reserved.
//

#import "lanCameraViewController.h"
#import "lanCameraTableViewCell.h"
#import "IPCamMgr.h"
#import "AddCameraViewController.h"

@interface lanCameraViewController (){
    
    __weak IBOutlet UITableView *tablevViewLanCameraList;
    NSArray* lanCameraList;

}

@end

@implementation lanCameraViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    lanCameraList = [[IPCamMgr get_share]get_discovered_cameras_list];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark UITableViewDataSource&UITableViewDelegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return lanCameraList.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    static NSString *cellID =@"lanCameraTableViewCell";
    lanCameraTableViewCell * cell = (lanCameraTableViewCell*)[tablevViewLanCameraList dequeueReusableCellWithIdentifier:cellID];
    if (cell == nil) {
        NSArray *array = [[NSBundle mainBundle]loadNibNamed:@"lanCameraTableViewCell" owner:self options:nil];
        cell = [array objectAtIndex:0];
    }
    [cell showCameraInfo:[lanCameraList objectAtIndex:indexPath.row]];
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 120;
}
- (NSIndexPath *)tableView:(UITableView *)tableView
  willSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    
    NSDictionary * dic = [lanCameraList objectAtIndex:indexPath.row];
    AddCameraViewController*AddVC = [[AddCameraViewController alloc]initWithIPCam:[dic objectForKey:@"camera_id"]];
    [self.navigationController pushViewController:AddVC animated:YES];
    
    return nil;
}




@end
