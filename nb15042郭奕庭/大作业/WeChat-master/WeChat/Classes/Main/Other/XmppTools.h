//
//  XmppTools.h
//  WeChat
//
//  Created by greeting on 15/10/9.
//  Copyright © 2015年 com.greeting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Singleton.h"
#import "XMPPFramework.h"

typedef enum
{
    XMPPResultTypeLoginSuccess,//登陆成功
    XMPPResultTypeLoginFailure,// 登录失败
    XMPPResultTypeNetErr, //网络问题
    XMPPResultTypeRegisterSuccess,//注册成功
    XMPPResultTypeRegisterFailure //注册失败
}XMPPResultType;
typedef void (^XMPPResultBlock)(XMPPResultType type);

@interface XmppTools : NSObject
singleton_interface(XmppTools)

@property (nonatomic,strong,readonly) XMPPStream * xmppStream;
@property (nonatomic,strong,readonly) XMPPvCardTempModule * vCard;
@property (nonatomic,strong,readonly) XMPPRosterCoreDataStorage *rosterStorage;
@property (nonatomic,strong,readonly) XMPPRoster *roster;
@property (nonatomic,strong,readonly) XMPPMessageArchivingCoreDataStorage * msgStorage;

//注册操作
@property (nonatomic,assign,getter=isRegisterOperation) BOOL registerOperation;

//用户登陆
-(void)userLogin:(XMPPResultBlock )resultBlock;

//用户注册
-(void)userRegister:(XMPPResultBlock)resultBlock;

//用户登出
-(void)userLogout;


@end
