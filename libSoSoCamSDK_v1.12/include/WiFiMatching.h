//
//  WiFiMatching.h
//  SoSoCamSDK
//
//  Created by Maverick Gao on 15/11/9.
//  Copyright © 2015年 reecam. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol WiFiMatchingDelegate

-(void)on_wifi_matching_succeed:(NSString *)camera_id;

@end

@interface WiFiMatching : NSObject

-(BOOL)start:(NSString *)ssid
         psk:(NSString *)psk
    delegate:(id<WiFiMatchingDelegate>)delegate;

-(void)stop;

@end
