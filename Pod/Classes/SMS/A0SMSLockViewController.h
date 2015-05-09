// A0SMSLockViewController.h
//
// Copyright (c) 2014 Auth0 (http://auth0.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <UIKit/UIKit.h>
#import "A0ContainerViewController.h"

@class A0AuthParameters, A0UserProfile, A0Token, A0Lock;

@interface A0SMSLockViewController : A0ContainerViewController

/**
 *  Instance of Lock with Auth0 account information. By default it will build this object with information from `Info.plist` if none is set.
 */
@property (strong, nonatomic) A0Lock *lock;

/**
 Allows the A0AuthenticationViewController to be dismissed by adding a button. Default is NO
 */
@property (assign, nonatomic) BOOL closable;

/**
 Block that is called on successful authentication. It has two parameters profile and token.
 */
@property (copy, nonatomic) void(^onAuthenticationBlock)(A0UserProfile *profile, A0Token *token);

/**
 Block that is called on when the user dismisses the Login screen. Only when closable property is `YES`.
 */
@property (copy, nonatomic) void(^onUserDismissBlock)();

/**
 *  Parameters to be sent to all Authentication request to Auth0 API.
 *  @see A0AuthParameters
 */
@property (strong, nonatomic) A0AuthParameters *authenticationParameters;

/**
 *  Block that returns a signed JWT with `create:users` scope for API v2. It's required to send SMS code.
 *  For more info: https://api.auth0.com/docs/api/v2
 */
@property (copy, nonatomic) NSString *(^auth0APIToken)();

@end
