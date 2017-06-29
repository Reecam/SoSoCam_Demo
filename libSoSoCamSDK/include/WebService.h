//
//  WebService.h
//  SoSoCamSDK
//
//  Created by Maverick Gao on 15-1-4.
//  Copyright (c) 2015年 reecam. All rights reserved.
//

#import <Foundation/Foundation.h>

#define APP_ID          @"1"

typedef enum {
    WEBSERVICE_LOGIN_STATUS_IDLE,
    WEBSERVICE_LOGIN_STATUS_LOGGING_IN,
    WEBSERVICE_LOGIN_STATUS_LOGGED_ON,
} WEBSERVICE_LOGIN_STATUS;

typedef enum {
    WEBSERVICE_ERROR_NO_ERROR,
    WEBSERVICE_ERROR_BAD_STATUS,
    WEBSERVICE_ERROR_NETWORK_ERROR,
    WEBSERVICE_ERROR_SVR_ERROR,
    WEBSERVICE_ERROR_BAD_AUTH,
    WEBSERVICE_ERROR_NEED_VERTIFICATION,
    WEBSERVICE_ERROR_NO_ACTIVATED,
    WEBSERVICE_ERROR_REGISTERED_BY_OTHERS,
    WEBSERVICE_ERROR_INVALID_SHARE_ID,
    WEBSERVICE_ERROR_SHARE_ID_EXISTS,
} WEBSERVICE_ERROR;

typedef enum {
    WEBSERVICE_LOGIN_TYPE_ACCOUNT,
    WEBSERVICE_LOGIN_TYPE_QQ,
    WEBSERVICE_LOGIN_TYPE_FACEBOOK,
    WEBSERVICE_LOGIN_TYPE_WEB_QQ,
} WEBSERVICE_LOGIN_TYPE;

typedef enum {
    WEBSERVICE_CHECK_LATEST_VERSION_ERROR_FAILED,
    WEBSERVICE_CHECK_LATEST_VERSION_ERROR_NO_LATEST_VERSION,
    WEBSERVICE_CHECK_LATEST_VERSION_ERROR_LATEST_VERSION_AVAIABLE,
    WEBSERVICE_CHECK_LATEST_VERSION_ERROR_SVR_RETURN_ERROR,
} WEBSERVICE_CHECK_LATEST_VERSION_ERROR;

@protocol WebServiceLoginDelegate
-(void)on_login_status_changed;
@end

@protocol WebServiceAddCameraDelegate
-(void)on_add_camera_result:(WEBSERVICE_ERROR)error
          sosocam_camera_id:(NSString *)sosocam_camera_id;
@end

@protocol WebServiceRemoveCameraDelegate
-(void)on_remove_camera_result:(WEBSERVICE_ERROR)error;
@end

@protocol WebServiceUpdateCameraAliasDelegate
-(void)on_update_camera_alias_result:(WEBSERVICE_ERROR)error;
@end

@protocol WebServiceGetAlarmCamerasListDelegate
//  every element in alarm_cameras_list passed is type of NSDictionary
//  key/value:
//  sosocam_camera_id/NSString *
//  camera_id/NSString *
//  unread/NSNumber */int
//  total/NSNumber */int
-(void)on_get_alarm_cameras_list_result:(WEBSERVICE_ERROR)error
                     alarm_cameras_list:(NSArray *)alarm_cameras_list;
@end

@protocol WebServiceGetCameraAlarmsListDelegate
//  every element in camera_alarms_list passed is type of NSDictionary
//  key/value:
//  alarm_id/NSString *
//  alarm_type/NSNumber */(int32_t)
//  image_numbers/NSNumber */(int)
//  read/NSNumber */(BOOL)
//  time/NSDate *
//  thumb_url/NSString *
-(void)on_get_camera_alarms_list_result:(WEBSERVICE_ERROR)error
                     camera_alarms_list:(NSArray *)camera_alarms_list;
@end

@protocol WebServiceGetAlarmImagesListDelegate
//  every element in alarm_images_list passed is type of NSDictionary
//  key/value:
//  time/NSDate *
//  url/NSString *
-(void)on_get_alarm_images_list_result:(WEBSERVICE_ERROR)error
                     alarm_images_list:(NSArray *)alarm_images_list;
@end

@protocol WebServiceGetImageDelegate
-(void)on_get_image_result:(NSString *)image_id
                      data:(NSData *)data;
@end

@protocol WebServiceCheckLatestVersionDelegate
-(void)on_check_latest_verion_result:(WEBSERVICE_CHECK_LATEST_VERSION_ERROR)error
                      latest_version:(NSString *)latest_version
                       changelog_url:(NSString *)changelog_url
                        download_url:(NSString *)download_url;
@end

@protocol WebServiceCheckLatestAppVersionDelegate
-(void)on_check_latest_app_verion_result:(WEBSERVICE_CHECK_LATEST_VERSION_ERROR)error
                          latest_version:(NSString *)latest_version;
@end

@protocol WebServiceShareCameraDelegate
-(void)on_share_camera_result:(WEBSERVICE_ERROR)error
                     share_id:(NSString *)share_id
                    share_url:(NSString *)share_url
                 share_qrcode:(NSString *)share_qrcode;
@end

@protocol WebServiceDisshareCameraDelegate
-(void)on_disshare_camera_result:(WEBSERVICE_ERROR)error;
@end

@protocol WebServiceGetCollectionCameraDelegate
-(void)on_get_collection_camera_result:(WEBSERVICE_ERROR)error
                             camera_id:(NSString *)camera_id
                                 https:(BOOL)https;
@end

@protocol WebServiceGetCollectionDelegate
-(void)on_get_collection_result:(WEBSERVICE_ERROR)error
                          alias:(NSString *)alias
                      cover_url:(NSString *)cover_url;
@end

@protocol WebServiceAddCollectionDelegate
-(void)on_add_collection_result:(WEBSERVICE_ERROR)error
                          alias:(NSString *)alias
                      cover_url:(NSString *)cover_url;
@end

@protocol WebServiceRemoveCollectionDelegate
-(void)on_remove_collection_result:(WEBSERVICE_ERROR)error;
@end



@interface WebService : NSObject

+(void)set_url_head:(NSString *)check_latest_version_url_head
client_webservice_url_head:(NSString *)client_webservice_url_head
current_user_info_url_head:(NSString *)current_user_info_url_head
client_forget_password_url_head:(NSString *)client_forget_password_url_head
client_new_user_url_head:(NSString *)client_new_user_url_head
client_activate_url_head:(NSString *)client_activate_url_head
client_web_qq_login_url_head:(NSString *)client_web_qq_login_url_head;

+(WebService *)get_share;

+(void)release_share;

-(WEBSERVICE_LOGIN_STATUS)get_login_status;

-(WEBSERVICE_ERROR)get_error;

-(NSString *)get_user_id;

-(NSString *)get_user_alias;

-(BOOL)get_badauth_locked;

-(int)get_badauth_retry_times;

-(NSString *)get_activate_user_type;

-(NSString *)get_activate_auth_code ;

//  every element in NSArray returned is type of NSDictionary
//  key/value:
//  camera_id/NSString *
//  sosocam_camera_id/NSString *
//  alias/NSString *
//  https/NSNumber */BOOL
//  user/NSString *
//  pwd/NSString *
//  model/NSNumber */int32_t
-(NSArray *)get_cameras_list;

//  every element in NSArray returned is type of NSDictionary
//  key/value:
//  share_id/NSString *
//  alias/NSString *
//  cover_url/NSString *
-(NSArray *)get_collections_list;

-(void)add_login_delegate:(id<WebServiceLoginDelegate>)delegate;

-(void)remove_login_delegate:(id<WebServiceLoginDelegate>)delegate;

-(WEBSERVICE_ERROR)login_with_account:(NSString *)user
                                  pwd:(NSString *)pwd
                   vertification_code:(NSString *)vertification_code
                       exit_on_failed:(BOOL)exit_on_failed;

-(WEBSERVICE_ERROR)login_with_oauth:(WEBSERVICE_LOGIN_TYPE)type
                            open_id:(NSString *)open_id
                       access_token:(NSString *)access_token
                     exit_on_failed:(BOOL)exit_on_failed;

-(WEBSERVICE_ERROR)login_with_web_qq:(NSString *)session_id
                      exit_on_failed:(BOOL)exit_on_failed;

-(void)logout;

-(NSString *)get_current_user_info_url;

-(NSString *)get_web_qq_login_url;

-(NSString *)get_new_user_url;

-(NSString *)get_forget_password_url;

-(NSString *)get_vetification_code_image_url;

-(NSString*)get_activate_url;

-(WEBSERVICE_ERROR)add_camera:(NSString *)camera_id
                        alias:(NSString *)alias
                        https:(BOOL)https
                        model:(int32_t)model
                     delegate:(id<WebServiceAddCameraDelegate>)delegate;
    
-(WEBSERVICE_ERROR)remove_camera:(NSString *)sosocam_camera_id
                        delegate:(id<WebServiceRemoveCameraDelegate>)delegate;

-(WEBSERVICE_ERROR)update_camera_alias:(NSString *)sosocam_camera_id
                                 alias:(NSString *)alias
                              delegate:(id<WebServiceUpdateCameraAliasDelegate>)delegate;

-(WEBSERVICE_ERROR)get_alarm_cameras_list:(id<WebServiceGetAlarmCamerasListDelegate>)delegate;

-(WEBSERVICE_ERROR)get_camera_alarms_list:(NSString *)sosocam_camera_id
                     delegate:(id<WebServiceGetCameraAlarmsListDelegate>)delegate;

-(WEBSERVICE_ERROR)get_alarm_images_list:(NSString *)alarm_id
                    delegate:(id<WebServiceGetAlarmImagesListDelegate>)delegate;

-(void)cancel_get_alarm_images_list_tasks;

-(void)get_alarm_image:(NSString *)image_id
                   url:(NSString *)url
              delegate:(id<WebServiceGetImageDelegate>)delegate;

-(void)cancel_get_alarm_image_tasks;

-(void)check_latest_camera_fw:(NSString *)current_version
                     delegate:(id<WebServiceCheckLatestVersionDelegate>)delegate;
-(void)check_latest_app_version_delegate:(id<WebServiceCheckLatestAppVersionDelegate>)delegate;

-(WEBSERVICE_ERROR)share_camera:(NSString *)sosocam_camera_id
                       delegate:(id<WebServiceShareCameraDelegate>)delegate;

-(WEBSERVICE_ERROR)disshare_camera:(NSString *)sosocam_camera_id
                          delegate:(id<WebServiceDisshareCameraDelegate>)delegate;

-(WEBSERVICE_ERROR)get_collection_camera:(NSString *)share_id
                                delegate:(id<WebServiceGetCollectionCameraDelegate>)delegate;

-(WEBSERVICE_ERROR)get_collection:(NSString *)share_id
                         delegate:(id<WebServiceGetCollectionDelegate>)delegate;

-(WEBSERVICE_ERROR)add_collection:(NSString *)share_id
                         delegate:(id<WebServiceAddCollectionDelegate>)delegate;

-(WEBSERVICE_ERROR)remove_collection:(NSString *)share_id
                            delegate:(id<WebServiceRemoveCollectionDelegate>)delegate;

@end
