//
//  SoundWaveWifiSettingSDK.h
//  SoundWaveWifiSettingSDK
//
//  Created by Maverick Gao on 15/4/27.
//  Copyright (c) 2015年 reecam. All rights reserved.
//

#import <Foundation/Foundation.h>

//#define SOUND_WAVE_WIFI_SETTING_DEMO

typedef enum {
    SOUND_WAVE_WIFI_SETTING_STATE_IDLE,
    SOUND_WAVE_WIFI_SETTING_STATE_SEND_SETTING,
    SOUND_WAVE_WIFI_SETTING_STATE_WAIT_CONFIRM,
    SOUND_WAVE_WIFI_SETTING_STATE_WAIT_RESULT,
    SOUND_WAVE_WIFI_SETTING_STATE_SEND_CONFIRM,
} SOUND_WAVE_WIFI_SETTING_STATE;

typedef enum {
    SOUND_WAVE_WIFI_SETTING_RESULT_SUCCEED,
    SOUND_WAVE_WIFI_SETTING_RESULT_TIMEOUT,
    SOUND_WAVE_WIFI_SETTING_RESULT_FAILED_JOIN,
    SOUND_WAVE_WIFI_SETTING_RESULT_FAILED_BUSY,
    SOUND_WAVE_WIFI_SETTING_RESULT_FAILED_INTERNAL,
} SOUND_WAVE_WIFI_SETTING_RESULT;

@protocol SoundWaveWifiSettingDelegate

-(void)on_sound_wave_wifi_setting_state_changed;

@end

@interface SoundWaveWifiSetting : NSObject

-(BOOL)start:(NSString *)ssid
         psk:(NSString *)psk
        test:(BOOL)test
    delegate:(id<SoundWaveWifiSettingDelegate>)delegate;

-(void)stop;

-(SOUND_WAVE_WIFI_SETTING_RESULT)result;

-(SOUND_WAVE_WIFI_SETTING_STATE)state;

-(int)name_of_camera_id;

-(int)serial_of_camera_id;

@end
