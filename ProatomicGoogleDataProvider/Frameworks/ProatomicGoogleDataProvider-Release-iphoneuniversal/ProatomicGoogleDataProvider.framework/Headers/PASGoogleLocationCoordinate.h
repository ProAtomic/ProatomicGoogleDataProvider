//
//  PASGoogleLocationCoordinate.h
//  ProatomicGoogleDataProvider
//
//  Created by Guillermo Sáenz on 7/20/17.
//  Copyright © 2017 Property Atomic Strong SAC. All rights reserved.
//

#import "PASGoogleBaseModelObject.h"

@import CoreLocation;

@interface PASGoogleLocationCoordinate : PASGoogleBaseModelObject

@property (nonatomic, assign, readonly) CLLocationCoordinate2D locationCoordinate;

+ (instancetype)newWithData:(NSDictionary *)data;

@end
