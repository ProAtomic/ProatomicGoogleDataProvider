//
//  PASGoogleDirection.h
//  ProatomicGoogleDataProvider
//
//  Created by Guillermo Sáenz on 7/20/17.
//  Copyright © 2017 Property Atomic Strong SAC. All rights reserved.
//

#import "PASGoogleBaseModelObject.h"

@class PASGoogleLeg;

@interface PASGoogleDirection : PASGoogleBaseModelObject

@property (nonatomic, copy, readonly) NSString *summary;
@property (nonatomic, copy, readonly) NSString *polylinePoints;
@property (nonatomic, strong, readonly) NSArray <PASGoogleLeg *> *legs;

+ (instancetype)newWithData:(NSDictionary *)data;

@end
