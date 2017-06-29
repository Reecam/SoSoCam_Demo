//
//  Storage.h
//  SoSoCamSDK
//
//  Created by Maverick Gao on 14-12-22.
//  Copyright (c) 2014年 reecam. All rights reserved.
//

#import <Foundation/Foundation.h>

#define OFFLINE_USER                0
#define ACCOUNT_USER                1
#define QQ_USER                     2
#define FACEBOOK_USER               3
#define WEB_QQ_USER                 4


#define MEDIA_PICTURE               0
#define MEDIA_CLIP                  1

@interface Storage : NSObject

+(Storage *)get_share;

+(void)release_share;

-(void)set_forbidden_with_mobile:(BOOL)forbidden_with_mobile;

-(BOOL)get_forbidden_with_mobile;

-(void)set_push_enabled:(BOOL)enabled;

-(BOOL)get_push_enabled;



//  every element in NSArray returned is type of NSDictionary
//  key/value:
//  user_id/NSString *
//  alias/NSString *
//  login_type/NSNumber *
//  account_name/NSString *
//  account_pwd/NSString *
//  open_id/NSString *
//  access_token/NSString *
//  latest/NSNumber *
-(NSArray *)get_users_list;

-(void)update_user:(NSString *)user_id
         login_type:(int)login_type
          auth_name:(NSString *)auth_name
           auth_pwd:(NSString *)auth_pwd
             alias:(NSString *)alias;

-(void)clear_user_latest;

-(void)remove_user:(NSString *)user_id;

-(void)set_current_user:(NSString *)user_id;

-(NSString *)get_current_user_id;

-(NSString *)get_current_user_alias;


//  every element in NSArray returned is type of NSDictionary
//  key/value:
//  camera_id/NSString *
//  alias/NSString *
//  user/NSString *
//  pwd/NSString *
//  https/NSNumber *
//  sosocam_id/NSString *
//  cover/NSData *
//  model/NSNumber *
//  recent/NSNumber */Long
//  master/NSNumber */BOOL
-(NSArray *)get_cameras_list;

-(BOOL)merge_cameras_list:(NSArray *)server_cameras_list;

-(void)add_camera:(NSString *)camera_id
            alias:(NSString *)alias
             user:(NSString *)user
              pwd:(NSString *)pwd
            https:(BOOL)https
        sosocam_id:(NSString *)sosocam_id
            model:(int32_t)model
           master:(BOOL)master;

-(void)remove_camera:(NSString *)camera_id;

-(void)update_camera_alias:(NSString *)camera_id
                     alias:(NSString *)alias;

-(void)update_camera_user:(NSString *)camera_id
                     user:(NSString *)user;

-(void)update_camera_pwd:(NSString *)camera_id
                     pwd:(NSString *)pwd;

-(void)update_camera_https:(NSString *)camera_id
                     https:(BOOL)https;

-(void)update_camera_sosocam_id:(NSString *)camera_id
                      sosocam_id:(NSString *)sosocam_id;

-(void)update_camera_cover:(NSString *)camera_id
                     cover:(NSData *)cover;

-(void)update_camera_recent:(NSString *)camera_id
                     recent:(time_t)recent;

-(void)update_camera_master:(NSString *)camera_id
                     master:(BOOL)master;




//  every element in NSArray returned is type of NSDictionary
//  key/value:
//  share_id/NSString *
//  valid/NSNumber *
//  alias/NSString *
//  user/NSString *
//  pwd/NSString *
//  cover_url/NSString *
//  recent/NSNumber */Long
-(NSArray *)get_collections_list;

-(BOOL)merge_collections_list:(NSArray *)server_collections_list;

-(BOOL)add_collection:(NSString *)share_id
                alias:(NSString *)alias
            cover_url:(NSString *)cover_url;

-(NSDictionary *)get_collection:(NSString *)share_id;

-(void)remove_collection:(NSString *)share_id;

-(void)update_collection_valid:(NSString *)share_id
                         valid:(BOOL)valid;

-(void)update_collection_user:(NSString *)share_id
                         user:(NSString *)user;

-(void)update_collection_pwd:(NSString *)share_id
                         pwd:(NSString *)pwd;

-(void)update_collection_recent:(NSString *)share_id
                     recent:(time_t)recent;




-(NSString *)generate_new_clip_path:(NSString *)camera_id;

//  every element in NSArray returned is type of NSDictionary
//  key/value:
//  time/NSDate *
//  size/NSNumber * /long long
//  type/NSNumber * /int
//  path/NSString *
-(NSMutableArray *)get_album:(NSString *)camera_id;

-(void)remove_album:(NSString *)camera_id;

-(void)remove_album_item:(NSString *)path;

-(void)add_album_picture:(NSString *)camera_id
                 picture:(NSData *)picture;


-(void)add_alarm_picture:(NSString *)camera_id
                 alarm_id:(NSString *)alarm_id
                   index:(int)index
                 picture:(NSData *)picture;

-(NSData *)get_alarm_picture:(NSString *)camera_id
                     alarm_id:(NSString *)alarm_id
                       index:(int)index;


@end


