//
//  lanCameraTableViewCell.m
//  SoDemonApple
//
//  Created by sandy on 16/5/13.
//  Copyright © 2016年 sandy. All rights reserved.
//

#import "lanCameraTableViewCell.h"

@implementation lanCameraTableViewCell{
    
    __weak IBOutlet UILabel *labelCameraAlias;

    __weak IBOutlet UILabel *labelCameraID;
    
    __weak IBOutlet UILabel *labelCameraIP;
    
    __weak IBOutlet UILabel *labelCameraFirmWareVersion;

}


-(void)showCameraInfo:(NSDictionary*)dic{
    labelCameraAlias.text = [NSString stringWithFormat:@"Alias:%@",[dic objectForKey:@"alias"]];
    labelCameraID.text = [NSString stringWithFormat:@"ID:%@",[dic objectForKey:@"camera_id"]];
    labelCameraIP.text = [NSString stringWithFormat:@"IP:%@",[dic objectForKey:@"current_ip"]];
    labelCameraFirmWareVersion.text = [NSString stringWithFormat:@"fw_version:%@",[dic objectForKey:@"fw_version"]];
}


- (void)awakeFromNib {
    // Initialization code
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end
