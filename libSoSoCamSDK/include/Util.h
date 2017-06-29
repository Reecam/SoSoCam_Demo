//
//  Util.h
//  SoSoCamSDK
//
//  Created by Maverick Gao on 15-1-8.
//  Copyright (c) 2015å¹?reecam. All rights reserved.
//

#import <Foundation/Foundation.h>
//@import UIKit;
#import <UIKit/UIKit.h>

#define SOSOCAMSDK_BUNDLE_NAME @"SoSoCamSDKBundle.bundle"
#define SOSOCAMSDK_BUNDLE_PATH [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent: SOSOCAMSDK_BUNDLE_NAME]
#define SOSOCAMSDK_BUNDLE [NSBundle bundleWithPath: SOSOCAMSDK_BUNDLE_PATH]
#define SOSOCAMSDK_BUNDLE_RESOURCE_PATH(name) [[SOSOCAMSDK_BUNDLE resourcePath] stringByAppendingPathComponent:name]

@protocol UtilRecordAudioDelegate

-(void)on_record_audio_finished:(NSData *)data;

@end

@protocol UtilPlayAudioDelegate

-(void)on_play_audio_finished;

@end

@interface Util : NSObject
+(BOOL)isOS7;

+(BOOL)isOS8;

+(BOOL)isAfterOS7;

+(BOOL)isAfterOS8;

+(BOOL)isBelowOS8;

+(UIAlertView *)show_alert_view:(NSString *)title
                        message:(NSString *)message
                       ok_title:(NSString *)ok_title
                     ok_handler:(void (^)(UIAlertAction * action))ok_handler
                      parent_vc:(UIViewController *)parent_vc
                       delegate:(id<UIAlertViewDelegate>)delegate;

+(UIAlertView *)show_alert_view:(NSString *)title
                        message:(NSString *)message
                       ok_title:(NSString *)ok_title
                     ok_handler:(void (^)(UIAlertAction * action))ok_handler
                   cancel_title:(NSString *)cancel_title
                 cancel_handler:(void (^)(UIAlertAction * action))cancel_handler
                      parent_vc:(UIViewController *)parent_vc
                       delegate:(id<UIAlertViewDelegate>)delegate;


+(UIInterfaceOrientation)getScreenOrientation;

+(BOOL)is_content_matching_regular_expression:(NSString *)content
                           regular_expression:(NSString *)regular_expression;

+(BOOL)is_content_contain_regular_expression:(NSString *)content
                          regular_expression:(NSString *)regular_expression;

+(NSString *)url_query_value_encode:(NSString *)value;

//+(NSString *)url_encode:(NSString *)url;

+(NSDictionary *)http_get_json:(NSString *)url;

+(NSDictionary *)http_get_json:(NSString *)url
                       timeout:(int)timeout;

+(UIImage *)http_get_image:(NSString *)url;

+(NSData *)http_get_binary:(NSString *)url;

+(NSDictionary *)http_post_multipart_file:(NSString *)url
                                 filetype:(NSString *)filetype
                                 filename:(NSString *)filename
                                     data:(NSData *)data;

+(int)passwordStrength:(NSString *)str;

+(UIColor *)colorWithRGB:(int)color;
+(UIButton*)cornerRadius:(UIButton*)m_button colorwithRGB:(int)color;
+(UIView*)cornerRadius:(UIView*) m_view colorRGB:(int)color;
+(NSString *)check_language;

+(NSString *)get_app_version;
+(NSString* )get_app_name;

+(void)show_long_toast:(NSString *)tip;

+(void)show_short_toast:(NSString *)tip;

+(void)cancel_toast;

+(NSString *)get_ssid;

+(NSString *)get_sosocamlib_version;

+(NSData *)encrypt:(NSString *)data;

+(NSString *)decrypt:(NSData *)data;

+(void)save_picture_to_system_album:(NSString *)picture_path;

+(void)save_picture_data_to_system_album:(NSData *)picture_data;

+(void)save_clip_to_system_album:(NSString *)clip_path;

/*
 key/value
 duration / NSNumber * / float
 thumb / UIImage *
 */
+(NSDictionary *)get_clip_info:(NSString *)clip_path;

/*
 key/value
 duration / NSNumber * / float
 duration_string / NSString *
 thumb / UIImage *
 */
+(NSDictionary *)get_clip_info:(NSString *)file_path time:(CGFloat )timeBySecond;

+(int)get_name_of_camera_id:(NSString *)camera_id;

+(int)get_serial_of_camera_id:(NSString *)camera_id;

+(NSString *)encodeTag:(NSString*)camID;

+(NSString*)get_sys_current_datatime;

+(BOOL)start_record_audio:(unsigned int)max_seconds delegate:(id<UtilRecordAudioDelegate>)delegate;

+(void)stop_record_audio;

+(BOOL)start_play_audio:(NSData *)data delegate:(id<UtilPlayAudioDelegate>)delegate;

+(void)stop_play_audio;

@end
