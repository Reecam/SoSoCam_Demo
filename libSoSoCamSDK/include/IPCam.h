//
//  IPCam.h
//  SoSoCamSDK
//
//  Created by Maverick Gao on 15-1-4.
//  Copyright (c) 2015å¹?reecam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IPCamVideoView.h"
#import "WebService.h"

#define STREAM_SD                           0
#define STREAM_HD                           1

#define STRERAM_CODEC_MJPG                  0
#define STRERAM_CODEC_MP4S                  1
#define STRERAM_CODEC_H264                  2

#define STREAM_RESOLUTION_SQCIF             0               //  128*96
#define STREAM_RESOLUTION_QQVGA_H128        1               //  160*128
#define STREAM_RESOLUTION_QQVGA             2               //  160*120
#define STREAM_RESOLUTION_QCIF              3               //  176*144
#define STREAM_RESOLUTION_QVGA              4               //  320*240
#define STREAM_RESOLUTION_CIF               5               //  352*288
#define STREAM_RESOLUTION_VGA               6               //  640*480
#define STREAM_RESOLUTION_D1_W704           7               //  704*576
#define STREAM_RESOLUTION_D1                8               //  720*576
#define STREAM_RESOLUTION_SVGA              9               //  800*600
#define STREAM_RESOLUTION_XGA               10              //  1024*768
#define STREAM_RESOLUTION_H720P             11              //  1280*720
#define STREAM_RESOLUTION_W256_H114         12              //  256*114
#define STREAM_RESOLUTION_W384_H216         13              //  384*216
#define STREAM_RESOLUTION_W512_H288         14              //  512*288
#define STREAM_RESOLUTION_W640_H360         15              //  640*360
#define STREAM_RESOLUTION_W768_H432         16              //  768*432
#define STREAM_RESOLUTION_W896_H504         17              //  896*576
#define STREAM_RESOLUTION_W1024_H576        18              //  1024*576
#define STREAM_RESOLUTION_W1280_H960        19              //  1280*960

typedef enum {
    IPCAM_ERROR_NO_ERROR,
    IPCAM_ERROR_UNKNOWN,
    IPCAM_ERROR_INTERNAL_ERROR,
    IPCAM_ERROR_BAD_PARAM,
    IPCAM_ERROR_BAD_STATUS,
    IPCAM_ERROR_BAD_ID,
    IPCAM_ERROR_NETWORK_ERROR,
    IPCAM_ERROR_CLOSED_BY_DEVICE,
    IPCAM_ERROR_BAD_AUTH,
    IPCAM_ERROR_DEVICE_TOO_MANY_SESSIONS,
    IPCAM_ERROR_DEVICE_INTERNAL_ERROR,
    IPCAM_ERROR_DEVICE_BAD_PARAM,
    IPCAM_ERROR_DEVICE_FORBIDDEN,
    IPCAM_ERROR_DEVICE_BAD_STATUS,
    IPCAM_ERROR_DEVICE_OPERATION_FAIL,
    IPCAM_ERROR_P2P_DISCONNECTED,
    IPCAM_ERROR_P2P_INVALID_ID,
    IPCAM_ERROR_P2P_DEVICE_OFFLINE,
    IPCAM_ERROR_P2P_TIMEOUT,
    IPCAM_ERROR_P2P_TOO_MANY_SESSIONS,
    IPCAM_ERROR_P2P_NETWORK_ERROR,
    IPCAM_ERROR_P2P_OUTOF_CAPACITY,
    IPCAM_ERROR_P2P_SERVER_ERROR,
    IPCAM_ERROR_HTTP_GET_ERROR,
    IPCAM_ERROR_DEVICE_TIMEOUT,
    IPCAM_ERROR_DEVICE_BAD_REQUEST,
    IPCAM_ERROR_UPGRADE_BAD_FILE,
    IPCAM_ERROR_UPGRADE_BAD_SERVER,
    IPCAM_ERROR_UPGRADE_DOWNLOAD_FAILED,
    IPCAM_ERROR_SOSOCAM_BAD_ID,
    IPCAM_ERROR_SOSOCAM_BAD_ACCESS,
    IPCAM_ERROR_SOSOCAM_UNREGISTERED,
    IPCAM_ERROR_CANCELED,
} IPCAM_ERROR;

typedef enum {
    IPCAM_STATUS_IDLE,
    IPCAM_STATUS_P2P_CONNECTING,
    IPCAM_STATUS_CONNECTING,
    IPCAM_STATUS_AUTHING,
    IPCAM_STATUS_CONNECTED,
    IPCAM_STATUS_WAIT_CONNECTING,
} IPCAM_STATUS;

typedef enum {
    IPCAM_PLAY_STATUS_STOPPED,
    IPCAM_PLAY_STATUS_REQUESTING,
    IPCAM_PLAY_STATUS_PLAYING,
} IPCAM_PLAY_STATUS;

typedef enum {
    IPCAM_TF_RECORD_STATUS_STOPPED,
    IPCAM_TF_RECORD_STATUS_REQUESTING,
    IPCAM_TF_RECORD_STATUS_PLAYING,
    IPCAM_TF_RECORD_STATUS_BUFFING,
    IPCAM_TF_RECORD_STATUS_PAUSING,
} IPCAM_TF_RECORD_STATUS;

typedef enum {
    IPCAM_ALARM_NONE,
    IPCAM_ALARM_MOTION_DETECT,
    IPCAM_ALARM_TRIGGER_DETECT,
    IPCAM_ALARM_SOUND_DETECT,
    IPCAM_ALARM_TEMPERATURE,
    IPCAM_ALARM_HUMIDITY,
    IPCAM_ALARM_RF_EMERGENCY,
    IPCAM_ALARM_RF_MAGNETIC,
    IPCAM_ALARM_RF_PIR,
    IPCAM_ALARM_RF_SMOKE,
    IPCAM_ALARM_RF_GAS,
    IPCAM_ALARM_RF_LOW_VOLTAGE,
    IPCAM_ALARM_RF_SHOCK,
    IPCAM_ALARM_RF_GLASS,
    IPCAM_ALARM_USER_DEFINED,
    IPCAM_ALARM_UNKNOWN,
} IPCAM_ALARM;

typedef enum {
    IPCAM_ARM_STATUS_UNKNOW,
    IPCAM_ARM_STATUS_ARM,
    IPCAM_ARM_STATUS_PLAN_ARM,
    IPCAM_ARM_STATUS_DISARM,
} IPCAM_ARM_STATUS;

typedef enum {
    IPCAM_DIJIA_STATUS_WAIT,
    IPCAM_DIJIA_STATUS_SLEEP,
    IPCAM_DIJIA_STATUS_AUTO,
    IPCAM_DIJIA_STATUS_TIMER,
    IPCAM_DIJIA_STATUS_Z,
    IPCAM_DIJIA_STATUS_SWALL,
    IPCAM_DIJIA_STATUS_PTZ,
    IPCAM_DIJIA_STATUS_CHARGER_FAR,
    IPCAM_DIJIA_STATUS_CHARGER_NEARLY,
    IPCAM_DIJIA_STATUS_CHARGER_DOCK,
    IPCAM_DIJIA_STATUS_CHARGER_DC,
    IPCAM_DIJIA_STATUS_ERROR_FAN,
    IPCAM_DIJIA_STATUS_ERROR_SWEEP,
    IPCAM_DIJIA_STATUS_ERROR_CHECK,
    IPCAM_DIJIA_STATUS_ERROR_BATTERY,
    IPCAM_DIJIA_STATUS_ERROR_RIGHT_WHEEL,
    IPCAM_DIJIA_STATUS_ERROR_LEFT_WHEEL,
    IPCAM_DIJIA_STATUS_OTHER
}IPCAM_DIJIA_STATUS;
typedef enum {
    IPCAM_TF_STATUS_NONE,
    IPCAM_TF_STATUS_READY,
    IPCAM_TF_STATUS_ERROR,
    IPCAM_TF_STATUS_FULL,
    IPCAM_TF_STATUS_CHECK,

} IPCAM_TF_STATUS;

typedef enum {
    IPCAM_PTZ_CMD_UP,
    IPCAM_PTZ_CMD_DOWN,
    IPCAM_PTZ_CMD_LEFT,
    IPCAM_PTZ_CMD_RIGHT,
    IPCAM_PTZ_CMD_T_PATROL,
    IPCAM_PTZ_CMD_P_PATROL,
    IPCAM_PTZ_CMD_TRACK_PATROL,
    IPCAM_PTZ_CMD_CENTER,
	IPCAM_PTZ_CMD_SET_PRESET,
    IPCAM_PTZ_CMD_GO_PRESET,
    
    IPCAM_PTZ_CMD_MEIJING_VOLUME_UP,
    IPCAM_PTZ_CMD_MEIJING_VOLUME_DOWN,
    IPCAM_PTZ_CMD_MEIJING_NEXT_TRACK,
    IPCAM_PTZ_CMD_MEIJING_PREVIOUS_TRACK,
    IPCAM_PTZ_CMD_MEIJING_PLAY_PAUSE,
    IPCAM_PTZ_CMD_MEIJING_LED_POWER,
    IPCAM_PTZ_CMD_MEIJING_LED_STYLE,
    
    IPCAM_PTZ_CMD_DIJIA_QUIT,
    IPCAM_PTZ_CMD_DIJIA_AUTO,
    IPCAM_PTZ_CMD_DIJIA_TIMER,
    IPCAM_PTZ_CMD_DIJIA_SWALL,
    IPCAM_PTZ_CMD_DIJIA_Z,
    IPCAM_PTZ_CMD_DIJIA_CHARGE,
    IPCAM_PTZ_CMD_DIJIA_LEFT,
    IPCAM_PTZ_CMD_DIJIA_RIGHT,
    IPCAM_PTZ_CMD_DIJIA_UP,
    IPCAM_PTZ_CMD_DIJIA_DOWN,
    IPCAM_PTZ_CMD_DIJIA_STOP,
    IPCAM_PTZ_CMD_DIJIA_MUTE,
    IPCAM_PTZ_CMD_DIJIA_SPEED,
    
    IPCAM_PTZ_CMD_EWIG_LAUNCH_FEED,
    IPCAM_PTZ_CMD_EWIG_STOP_FEED,
    IPCAM_PTZ_CMD_EWIG_PLAY_MELODY,
    IPCAM_PTZ_CMD_EWIG_STOP_MELODY,
    IPCAM_PTZ_CMD_EWIG_SET_FOOD,
} IPCAM_PTZ_CMD;

typedef enum {
    IPCAM_SENSOR_CMD_BRIGHTNESS,
    IPCAM_SENSOR_CMD_CONTRAST,
    IPCAM_SENSOR_CMD_SHARPNESS,
    IPCAM_SENSOR_CMD_SATURATION,
    IPCAM_SENSOR_CMD_POWER_FREQUENCY,
    IPCAM_SENSOR_CMD_WHITE_BALANCE,
    IPCAM_SENSOR_CMD_FLIP,
} IPCAM_SENSOR_CMD;

typedef enum {
    IPCAM_WIFI_AUTH_OPEN,
    IPCAM_WIFI_AUTH_WEP,
    IPCAM_WIFI_AUTH_WPAPSK,
    IPCAM_WIFI_AUTH_WPA2PSK,
    IPCAM_WIFI_AUTH_UNKNOWN,
} IPCAM_WIFI_AUTH;

typedef enum {
    IPCAM_WIFI_ENCRYPT_NONE,
    IPCAM_WIFI_ENCRYPT_WEP,
    IPCAM_WIFI_ENCRYPT_TKIP,
    IPCAM_WIFI_ENCRYPT_AES,
    IPCAM_WIFI_ENCRYPT_UNKNOWN,
} IPCAM_WIFI_ENCRYPT;

typedef enum {
    IPCAM_WIFI_WEP_KEY_TYPE_HEX,
    IPCAM_WIFI_WEP_KEY_TYPE_ASCII,
} IPCAM_WIFI_WEP_KEY_TYPE;

typedef enum {
    IPCAM_SET_WIFI_STATE_SETTING,
    IPCAM_SET_WIFI_STATE_TESTING,
    IPCAM_SET_WIFI_STATE_SAVING,
} IPCAM_SET_WIFI_STATE;

@protocol IPCamDelegate
@optional
-(void)on_alias_changed:(id)ipcam;

-(void)on_cover_changed:(id)ipcam;

-(void)on_status_changed:(id)ipcam;

-(void)on_video_status_changed:(id)ipcam;

-(void)on_audio_status_changed:(id)ipcam;

-(void)on_speak_status_changed:(id)ipcam;

-(void)on_tf_record_status_changed:(id)ipcam;

-(void)on_tf_record_event:(id)ipcam
               new_record:(BOOL)new_record
                record_id:(int32_t)record_id
                    error:(BOOL)error;

-(void)on_camera_tf_changed:(id)ipcam;

-(void)on_camera_wifi_changed:(id)ipcam;

-(void)on_camera_alarm_changed:(id)ipcam;

-(void)on_bell_alarm_changed:(id)ipcam;

-(void)on_camera_recording_changed:(id)ipcam;

-(void)on_camera_can_upgrade:(id)ipcam;

-(void)on_camera_power_down_changed:(id)ipcam;

-(void)on_camera_arm_changed:(id)ipcam;
-(void)on_camera_dijia_power_changed:(id)ipcam;

-(void)on_camera_dijia_speed_changed:(id)ipcam;

-(void)on_camera_dijia_mute_changed:(id)ipcam;

-(void)on_camera_dijia_status_changed:(id)ipcam;

-(void)on_statistic:(id)ipcam;

-(void)on_can_set_video_performance:(id)ipcam;

-(void)on_camera_temperature_changed:(id)ipcam;

-(void)on_camera_meijing_play_changed:(id)ipcam;

-(void)on_camera_meijing_led_changed:(id)ipcam;

-(void)on_camera_sessions_change:(id)ipcam;

-(void)on_camera_tf_capacity:(id)ipcam;

-(void)on_camera_ewig_status_changed:(id)ipcam;

-(void)on_camera_juyang_led_changed:(id)ipcam;

@end


@protocol IPCamGetSensorParamsDelegate

-(void)on_get_sensor_params_result:(id)ipcam
                             error:(IPCAM_ERROR)error
                        brightness:(int)brightness
                          contrast:(int)contrast
                         sharpness:(int)sharpness
                        saturation:(int)saturation
                   power_frequency:(int)power_frequency
                     white_balance:(int)white_balance
                              flip:(int)flip;

@end

@protocol IPCamGetRFSwitchDevicesDelegate

//  every element of rf_switch_devices_list is a NSDictionary type:
//  key/value
//  addr/NSNumber */int
//  switch/NSNumber */int
//  link/NSNumber */int
//  name/NSString *
-(void)on_get_rf_switch_devices_result:(id)ipcam
                                 error:(IPCAM_ERROR)error
                rf_switch_devices_list:(NSArray *)rf_switch_devices_list;

@end

@protocol IPCamSwitchRFDeviceDelegate

-(void) on_switch_rf_device_result:(id)ipcam
                             error:(IPCAM_ERROR)error;
@end


@protocol IPCamWifiScanDelegate

//  every element of ap_list is a NSDictionary type:
//  key/value
//  bssid/NSString *
//  ssid/NSString *
//  auth/NSNumber */int/IPCAM_WIFI_AUTH
//  encrypt/NSNumber */int/IPCAM_WIFI_ENCRYPT
//  rssi/NSNumber */int
-(void)on_wifi_scan_result:(id)ipcam
                     error:(IPCAM_ERROR)error
                   ap_list:(NSArray *)ap_list;

@end


@protocol IPCamSetWifiDelegate

-(void)on_set_wifi_progress:(id)ipcam
                      state:(IPCAM_SET_WIFI_STATE)state;

-(void)on_set_wifi_result:(id)ipcam
                    error:(IPCAM_ERROR)error;

@end


@protocol IPCamUnplugTFDelegate

-(void)on_unplug_tf_result:(id)ipcam
                     error:(IPCAM_ERROR)error;

@end


@protocol IPCamFormatTFDelegate

-(void)on_format_tf_result:(id)ipcam
                     error:(IPCAM_ERROR)error;

@end


@protocol IPCamUpgradeFWDelegate

-(void)on_upgrade_fw_result:(id)ipcam
                      error:(IPCAM_ERROR)error;

@end


@protocol IPCamUnregisterFromSoSoCamDelegate

-(void)on_unregister_from_sosocam_result:(id)ipcam
                                   error:(IPCAM_ERROR)error;

@end


@protocol IPCamReloginToSoSoCamDelegate

-(void)on_relogin_to_sosocam_result:(id)ipcam
                              error:(IPCAM_ERROR)error;

@end


@protocol IPCamResetPwdDelegate

-(void)on_reset_pwd_result:(id)ipcam
                     error:(IPCAM_ERROR)error;

@end


@protocol IPCamResetHttpsDelegate

-(void)on_reset_https_result:(id)ipcam
                       error:(IPCAM_ERROR)error;

@end


@protocol IPCamSetParamsDelegate

-(void)on_set_params_result:(id)ipcam
                      error:(IPCAM_ERROR)error;

@end


@protocol IPCamRestoreFactoryDelegate

-(void)on_restore_factory_result:(id)ipcam
                           error:(IPCAM_ERROR)error;

@end


@protocol IPCamClearBootPresetDelegate

-(void)on_clear_boot_preset_result:(id)ipcam
                             error:(IPCAM_ERROR)error;

@end


@protocol IPCamSetBootPresetDelegate

-(void)on_set_boot_preset_result:(id)ipcam
                           error:(IPCAM_ERROR)error;

@end


@protocol IPCamGetPTPosDelegate

-(void)on_get_pt_pos_result:(id)ipcam
                      error:(IPCAM_ERROR)error
                        pos:(int32_t)pos;

@end


@protocol IPCamSetTrackDelegate

-(void)on_set_track_result:(id)ipcam
                     error:(IPCAM_ERROR)error;

@end

@protocol IPCamGetAlarmNameDelegate

-(void)on_get_alarm_name_result:(id)ipcam
                          error:(IPCAM_ERROR)error
                     alarm_name:(NSString *)alarm_name;

@end

@protocol IPCamGetBellNameDelegate

-(void)on_get_bell_name_result:(id)ipcam
                          error:(IPCAM_ERROR)error
                     bell_name:(NSString *)bell_name;

@end


    
@protocol IPCamGetParamsDelegate

-(void)on_get_params_result:(id)ipcam
                      error:(IPCAM_ERROR)error
                     params:(NSDictionary *)params;

@end

@protocol IPCamUploadFileDelegate

-(void)on_upload_file_result:(id)ipcam
                       error:(IPCAM_ERROR)error;

@end

@protocol IPCamLoadTFRecordsDelegate

-(void)on_load_tf_records_result:(id)ipcam
                           error:(IPCAM_ERROR)error;

@end


@protocol IPCamGetTFRecordQuarterThumbDelegate

-(void)on_get_tf_record_quarter_thumb_result:(id)ipcam
                                         day:(int)day
                                        hour:(int)hour
                            valid_hour_index:(int)valid_hour_index
                                     quarter:(int)quarter
                                       thumb:(NSData *)thumb;

@end


@protocol IPCamGetTFRecordQuarterDetailDelegate

//  every element of clips is type of NSDictionary
//  key/value
//  valid/NSNumber */BOOL;
//  thumb/NSNumber */BOOL;
//  alarm/NSNumber */int32_t
-(void)on_get_tf_record_quarter_detail_result:(id)ipcam
                                          day:(int)day
                                         hour:(int)hour
                                      quarter:(int)quarter
                                        clips:(NSArray *)clips;

@end


@protocol IPCamGetTFRecordClipThumbDelegate

-(void)on_get_tf_record_clip_thumb_result:(id)ipcam
                                      day:(int)day
                                     hour:(int)hour
                                  quarter:(int)quarter
                                       no:(int)no
                                    thumb:(NSData *)thumb;

@end


@protocol IPCamEWIGSetMelodyDelegate

-(void)on_ewig_set_melody_result:(id)ipcam
                           error:(IPCAM_ERROR)error;

@end


@protocol IPCamEWIGClearMelodyDelegate

-(void)on_ewig_clear_melody_result:(id)ipcam
                             error:(IPCAM_ERROR)error;

@end


@interface IPCam : NSObject<WebServiceCheckLatestVersionDelegate,
                            NSURLConnectionDelegate,
                            NSURLConnectionDataDelegate>

+(BOOL)is_valid_camera_id:(NSString *)camera_id;

+(IPCAM_WIFI_AUTH)parse_wifi_auth:(int)auth;

+(int)parse_wifi_auth2:(IPCAM_WIFI_AUTH)auth;

+(IPCAM_WIFI_ENCRYPT)parse_wifi_encrypt:(int)encrypt;

+(int)parse_wifi_encrypt2:(IPCAM_WIFI_ENCRYPT)encrypt;

+(int)parse_wifi_wepkeytype:(IPCAM_WIFI_WEP_KEY_TYPE)type;

-(IPCAM_STATUS)status;

-(IPCAM_ERROR)error;

-(IPCAM_PLAY_STATUS)video_status;

-(IPCAM_PLAY_STATUS)audio_status;

-(IPCAM_PLAY_STATUS)speak_status;

-(IPCAM_PLAY_STATUS)local_record_status;

-(IPCAM_TF_RECORD_STATUS)tf_record_status;

-(IPCAM_ALARM)alarm;

-(NSString *)alarm_name;
-(NSString *)bell_name;

-(float)temperature;

-(BOOL)meijing_play;

-(BOOL)meijing_led;

-(BOOL)juyang_led;

-(BOOL)need_upgrade;

-(BOOL)Andingbao_power_down;

-(BOOL)Andingbao_bell_alarm;

-(int)current_sessions_number;

-(float)tf_capactiy;

-(int)ewig_food;

-(int)ewig_melodies_size;

-(BOOL)ewig_motor_fault;

-(IPCAM_ARM_STATUS)Andingbao_arm;

-(IPCAM_DIJIA_STATUS)Dijia_status;

-(BOOL)Dijia_mute;

-(BOOL)Dijia_speed;

-(int)Dijia_power;

-(NSString *)current_fw_version;
-(NSString *)latest_fw_version;

-(BOOL)can_set_video_performance;

-(IPCAM_TF_STATUS)tf_status;
-(int)tf_free;

-(BOOL)camera_recording;

-(int)wifi_power;

-(NSString *)ip;
-(int)port;
-(BOOL)p2p_relay;

-(int)times_of_retry_auth;
-(int)delay_of_retry_auth;

-(int)group;

-(int)video_render_fps;
-(int)video_recv_fps;
-(int)video_byterate;

-(int)audio_sps;
-(int)audio_byterate;

-(int)speak_sps;
-(int)speak_byterate;

-(NSString *)sosocam_id;
-(void)set_sosocam_id:(NSString *)sosocam_id;

-(int32_t)model;
-(void)set_model:(int32_t)model;

-(NSString *)alias;
-(void)set_alias:(NSString *)alias;

-(NSString *)camera_id;
-(void)set_camera_id:(NSString *)camera_id;

-(BOOL)master;
-(void)set_master:(BOOL )master;

-(NSString *)user;
-(void)set_user:(NSString *)user;

-(NSString *)pwd;
-(void)set_pwd:(NSString *)pwd;

-(BOOL)https;
-(void)set_https:(BOOL)https;

-(NSData *)cover;
-(void)set_cover:(NSData *)cover;

-(int)cache;
-(void)set_cache:(int)cache;

-(int)record_performance_speed;
-(void)set_record_performance_speed:(int)speed;

-(int)video_performance_mode;
-(void)set_video_performance_mode:(int)mode;


-(IPCAM_ERROR)start_connect:(BOOL)retryable
                retry_delay:(int)retry_delay;

-(void)stop_connect;

-(void)update_lan_status:(BOOL)in_lan
                      ip:(NSString *)ip
                    port:(int)port
                   https:(BOOL)https;

-(void)set_video_view:(IPCamVideoView *)video_view;

-(IPCAM_ERROR)play_video:(int)stream;

-(void)stop_video;

-(IPCAM_ERROR)play_audio;

-(void)stop_audio;

-(IPCAM_ERROR)start_speak;

-(void)stop_speak;

-(IPCAM_ERROR)start_local_record;
-(IPCAM_ERROR)start_local_record:(NSString*)record_file_path;
-(void)stop_local_record;

-(IPCAM_ERROR)snapshot;
-(IPCAM_ERROR)snapshot:(NSString*)photo_file_path;
-(IPCAM_ERROR)play_tf_record:(int)tf_record_id;

-(void)stop_tf_record;

-(IPCAM_ERROR)pause_tf_record;

-(IPCAM_ERROR)continue_tf_record;

-(IPCAM_ERROR)enable_tf_record_download_mode:(BOOL)enabled;

-(IPCAM_ERROR)write_comm:(NSData *)data;

-(IPCAM_ERROR)ptz_control:(IPCAM_PTZ_CMD)cmd
                    param:(int)param;

-(IPCAM_ERROR)sensor_control:(IPCAM_SENSOR_CMD)cmd
                       param:(int)param;

-(void)add_delegate:(id<IPCamDelegate>)delegate;

-(void)remove_delegate:(id<IPCamDelegate>)delegate;

-(IPCAM_ERROR)get_sensor_params:(id<IPCamGetSensorParamsDelegate>)delegate;

-(IPCAM_ERROR)get_rf_switch_devices:(id<IPCamGetRFSwitchDevicesDelegate>)delegate;

-(IPCAM_ERROR)switch_rf_device:(int)addr
                        status:(int)status
                      delegate:(id<IPCamSwitchRFDeviceDelegate>)delegate;

-(IPCAM_ERROR)wifi_scan:(id<IPCamWifiScanDelegate>)delegate;

-(IPCAM_ERROR)set_wifi:(NSString *)ssid
                  auth:(IPCAM_WIFI_AUTH)auth
               encrypt:(IPCAM_WIFI_ENCRYPT)encrypt
         wep_key_index:(int)wep_key_index
          wep_key_type:(IPCAM_WIFI_WEP_KEY_TYPE)wep_key_type
                   key:(NSString *)key
              delegate:(id<IPCamSetWifiDelegate>)delegate;

-(IPCAM_ERROR)set_wifi_without_testing:(NSString *)ssid
                                  auth:(IPCAM_WIFI_AUTH)auth
                               encrypt:(IPCAM_WIFI_ENCRYPT)encrypt
                         wep_key_index:(int)wep_key_index
                          wep_key_type:(IPCAM_WIFI_WEP_KEY_TYPE)wep_key_type
                                   key:(NSString *)key
                              delegate:(id<IPCamSetWifiDelegate>)delegate;

-(IPCAM_ERROR)unplug_tf:(id<IPCamUnplugTFDelegate>)delegate;

-(IPCAM_ERROR)format_tf:(id<IPCamFormatTFDelegate>)delegate;

-(IPCAM_ERROR)upgrade_fw:(id<IPCamUpgradeFWDelegate>)delegate;

-(IPCAM_ERROR)unregister_from_sosocam:(id<IPCamUnregisterFromSoSoCamDelegate>)delegate;

-(IPCAM_ERROR)relogin_to_sosocam:(id<IPCamReloginToSoSoCamDelegate>)delegate;

-(IPCAM_ERROR)reset_pwd:(NSString *)pwd
               delegate:(id<IPCamResetPwdDelegate>)delegate;

-(IPCAM_ERROR)reset_https:(BOOL)https
                 delegate:(id<IPCamResetHttpsDelegate>)delegate;

-(IPCAM_ERROR)set_params:(NSString *)params
                delegate:(id<IPCamSetParamsDelegate>)delegate;

-(IPCAM_ERROR)restore_factory:(id<IPCamRestoreFactoryDelegate>)delegate;

-(IPCAM_ERROR)clear_boot_preset:(id<IPCamClearBootPresetDelegate>)delegate;

-(IPCAM_ERROR)set_boot_preset:(id<IPCamSetBootPresetDelegate>)delegate;

-(IPCAM_ERROR)get_pt_pos:(id<IPCamGetPTPosDelegate>)delegate;

//  the element of nodes_list is type of NSDictionary:
//  key/value
//  pos/NSNumber */int32_t
//  ms/NSNumber */int
-(IPCAM_ERROR)set_track:(NSArray *)nodes_list
               delegate:(id<IPCamSetTrackDelegate>)delegate;

-(IPCAM_ERROR)get_alarm_name:(id<IPCamGetAlarmNameDelegate>)delegate;

-(IPCAM_ERROR)get_bell_name:(id<IPCamGetBellNameDelegate>)delegate;

    
-(IPCAM_ERROR)get_params:(NSString *)params
                delegate:(id<IPCamGetParamsDelegate>)delegate;

-(IPCAM_ERROR)upload_file:(int)type
                  factory:(BOOL)factory
                     data:(NSData *)data
                 delegate:(id<IPCamUploadFileDelegate>)delegate;

-(IPCAM_ERROR)ewig_set_melody:(int)index
                         data:(NSData *)data
                     delegate:(id<IPCamEWIGSetMelodyDelegate>)delegate;

-(IPCAM_ERROR)ewig_clear_melody:(int)index
                       delegate:(id<IPCamEWIGClearMelodyDelegate>)delegate;

-(IPCAM_ERROR)load_tf_records:(id<IPCamLoadTFRecordsDelegate>)delegate;

-(void)clear_tf_records;

//  return
//  key/value
//  valid/NSNumber */BOOL
//  alarm/NSNumber */BOOL
//  week/NSNumber */int
//  today/NSNumber */BOOL
//  yesterday/NSNumber */BOOL
//  dby/NSNumber */BOOL
//  valid_hours/NSNumber */int
-(NSDictionary *)get_tf_record_day_info:(int)day;

-(BOOL)get_tf_record_hour_valid:(int)day
                           hour:(int)hour;

//  return
//  key/value
//  valid/NSNumber */BOOL
//  alarm/NSNumber */BOOL
-(NSDictionary *)get_tf_record_quarter_info:(int)day
                                       hour:(int)hour
                                    quarter:(int)quarter;

-(int32_t)get_tf_record_play_id:(NSDate *)date;

-(int32_t)get_tf_record_play_id_of_quarter:(int)day
                                      hour:(int)hour
                                   quarter:(int)quarter;

-(int32_t)get_tf_record_play_id_of_no:(int)day
                                 hour:(int)hour
                              quarter:(int)quarter
                                   no:(int)no;

//  return
//  key/value
//  day/NSNumber */int
//  hour/NSNumber */int
//  quarter/NSNumber */int
-(NSDictionary *)get_next_tf_record_quarter_time:(int)day
                                            hour:(int)hour
                                         quarter:(int)quarter;

//  return
//  key/value
//  day/NSNumber */int
//  hour/NSNumber */int
//  quarter/NSNumber */int
-(NSDictionary *)get_previous_tf_record_quarter_time:(int)day
                                            hour:(int)hour
                                         quarter:(int)quarter;

//  return
//  key/value
//  day/NSNumber */int
//  hour/NSNumber */int
//  quarter/NSNumber */int
//  no/NSNumber */int
-(NSDictionary *)get_tf_record_clip_time:(int)subrecord_id;

-(IPCAM_ERROR)get_tf_record_quarter_thumb:(int)day
                                     hour:(int)hour
                         valid_hour_index:(int)valid_hour_index
                                  quarter:(int)quarter
                                 delegate:(id<IPCamGetTFRecordQuarterThumbDelegate>)delegate;

-(IPCAM_ERROR)get_tf_record_quarter_detail:(int)day
                                      hour:(int)hour
                                   quarter:(int)quarter
                                  delegate:(id<IPCamGetTFRecordQuarterDetailDelegate>)delegate;

-(IPCAM_ERROR)get_tf_record_clip_thumb:(int)day
                                  hour:(int)hour
                               quarter:(int)quarter
                                    no:(int)no
                              delegate:(id<IPCamGetTFRecordClipThumbDelegate>)delegate;

-(void)cancel_tf_record_tasks;

//  return
//  key/value
//  brightness/NSNumber */bool/can set brightness
//  brightness_min/NSNumber */int
//  brightness_max/NSNumber */int
//  brightness_default/NSNumber */int
//  contrast/NSNumber */bool
//  contrast_min/NSNumber */int
//  contrast_max/NSNumber */int
//  contrast_default/NSNumber */int
//  hue/NSNumber */bool
//  hue_min/NSNumber */int
//  hue_max/NSNumber */int
//  hue_default/NSNumber */int
//  saturation/NSNumber */bool
//  saturation_min/NSNumber */int
//  saturation_max/NSNumber */int
//  saturation_default/NSNumber */int
//  sharpness/NSNumber */bool
//  sharpness_min/NSNumber */int
//  sharpness_max/NSNumber */int
//  sharpness_default/NSNumber */int
//  powerfreq/NSNumber */bool
//  powerfreq_min/NSNumber */int
//  powerfreq_max/NSNumber */int
//  powerfreq_default/NSNumber */int
//  ev/NSNumber */bool
//  ev_min/NSNumber */int
//  ev_max/NSNumber */int
//  ev_default/NSNumber */int
//  scene/NSNumber */bool
//  scene_min/NSNumber */int
//  scene_max/NSNumber */int
//  scene_default/NSNumber */int
//  flip/NSNumber */bool
//  flip_min/NSNumber */int
//  flip_max/NSNumber */int
//  flip_default/NSNumber */int
-(NSDictionary *)get_sensor_capability;

//  every element of NSArray returned is type of NSDictionary
//  key/value
//  stream/NSNumber */int;
//  codec/NSNumber */int;
//  resolution/NSNumber */int
-(NSArray *)get_video_streams_info;

@end
