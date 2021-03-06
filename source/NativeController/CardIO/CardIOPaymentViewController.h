/**
 * PHR_iphoneNativeEshopARC
 *
 * Copyright (C) 1999-2013 Photon Infotech Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
//
//  CardIOPaymentViewController.h
//  Copyright (c) 2011-2012 PayPal. All rights reserved.
// 

#import <UIKit/UIKit.h>
#import "CardIOPaymentViewControllerDelegate.h"

// CardIOPaymentViewController is the main entry point into the card.io SDK.
@interface CardIOPaymentViewController : UINavigationController

// Initializer for scanning only.
- (id)initWithPaymentDelegate:(id<CardIOPaymentViewControllerDelegate>)aDelegate;

// Initializer for scanning only, with extra hooks for controlling whether the camera will be displayed (useful for testing).
// If scanningEnabled is NO, card.io will use manual entry, regardless of whether scanning is supported. (Default value is YES.)
- (id)initWithPaymentDelegate:(id<CardIOPaymentViewControllerDelegate>)aDelegate scanningEnabled:(BOOL)scanningEnabled;

// Set your app token. If not set before presenting the view controller, an exception will be thrown.
@property(nonatomic, copy, readwrite) NSString *appToken;

// Set to NO if you don't need to collect the card expiration. Defaults to YES.
@property(nonatomic, assign, readwrite) BOOL collectExpiry;

// Set to NO if you don't need to collect the CVV from the user. Defaults to YES.
@property(nonatomic, assign, readwrite) BOOL collectCVV;

// Set to YES if you need to collect the billing zip code. Defaults to NO.
@property(nonatomic, assign, readwrite) BOOL collectZip;

// Set to NO if you want to suppress the first-time how-to alert view. Defaults to YES.
@property(nonatomic, assign, readwrite) BOOL showsFirstUseAlert;

// Set to YES to prevent card.io from showing manual entry buttons internally. Defaults to NO.
// If you want to prevent users from *ever* seeing card.io's manual entry screen, you should also:
//   * Check +canReadCardWithCamera before initing the view controller. If +canReadCardWithCamera
//     returns false, card.io will display a manual entry screen if presented.
//   * If needed for UI updates such as disabling/removing card scan buttons, subscribe to scan
//     notifications; see +(start|stop)GeneratingScanAvailabilityNotifications.
@property(nonatomic, assign, readwrite) BOOL disableManualEntryButtons;

// Access to the delegate.
@property(nonatomic, assign, readwrite) id<CardIOPaymentViewControllerDelegate> paymentDelegate;

// Indicates whether this device supports camera-based card scanning, including
// factors like hardware support and OS version. card.io automatically provides
// manual entry of cards as a fallback, so it is not necessary to check this.
+ (BOOL)canReadCardWithCamera;

// Please send the output of this method with any technical support requests.
+ (NSString *)libraryVersion;

@end