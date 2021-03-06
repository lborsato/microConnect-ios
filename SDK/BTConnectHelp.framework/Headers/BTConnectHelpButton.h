//
//  BTConnectHelpButton.h
//  BTConnectHelp
//
//  Created by Larry Borsato on 2016-03-08.
//  Copyright © 2016 Boomtown. All rights reserved.
//

@import UIKit;

/**
 These methods allow the Help Button to communicate with the delegate calling application
 */
@protocol BTConnectHelpButtonDelegate <NSObject>

@required

/**
 Called when the issue view controller is ready to be displayed. This will display tracking and chat related to the issue
 */
- (void) helpButton:(nonnull id)helpButton  displayIssueViewController:(nonnull UIViewController *)viewController;

/**
 Called when the generated help action sheet is ready to be displayed. This will display the available support options
 */
- (void) helpButton:(nonnull id)helpButton  displayHelpActionSheet:(nonnull UIAlertController *)alertController;

/**
 Called when authorization fails so that the user can take appropriate action
 */
- (void) helpButton:(nonnull id)helpButton  authorizationFailedWithStatus:(nonnull NSNumber *)status message:(nonnull NSString *)message;

/**
 Called to provide alerts for the user. The message will explain the situation (which is really a failure description)
 */
- (void) helpButton:(nonnull id)helpButton  alertWithMessage:(nullable NSString *)message;

@optional

@end


IB_DESIGNABLE
@interface BTConnectHelpButton : UIView

/**
 The delegate for responses
 */
@property (nullable, strong, nonatomic)	id			delegate;

/**
 Website URL the help button will take the user to.
 If not null this will be populated by the setCredentialsWithToken:secret: method from the current provider information
 */
@property (nullable, strong, nonatomic)	NSString	*supportWebsiteURL;

/**
 Email address the help button will send email to.
 If not null this will be populated by the setCredentialsWithToken:secret: method from the current provider information
 */
@property (nullable, strong, nonatomic)	NSString	*supportEmailAddress;

/**
 Phone number the help button will call.
 If not null this will be populated by the setCredentialsWithToken:secret: method from the current provider information
 */
@property (nullable, strong, nonatomic)	NSString	*supportPhoneNumber;

/**
 The ID of the member (also referred to as teh merchant)
 */
@property (nullable, strong, nonatomic)	NSString	*memberID;

/**
 The ID of the member user
 */
@property (nullable, strong, nonatomic)	NSString	*memberUserID;

/**
 The ID of the member user's location
 */
@property (nullable, strong, nonatomic)	NSString	*memberLocationID;


/**
 Set the correct API credentials
 The token and secret have been provided to the developer separately
 This method will populate supportWebsiteURL, supportEmailAddress, and supportPhoneNumber if they are non-null, though they may be set manually after calling this method
 */
- (void)setCredentialsWithToken:(nonnull NSString *)token secret:(nonnull NSString *)secret;

@end
