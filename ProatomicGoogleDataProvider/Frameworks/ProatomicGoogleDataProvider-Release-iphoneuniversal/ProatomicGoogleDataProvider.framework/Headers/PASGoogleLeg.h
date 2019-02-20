//
//  PASGoogleLeg.h
//  ProatomicGoogleDataProvider
//
//  Created by Guillermo Sáenz on 7/20/17.
//  Copyright © 2017 Property Atomic Strong SAC. All rights reserved.
//

#import "PASGoogleBaseModelObject.h"

@class PASGoogleLocationCoordinate;

@interface PASGoogleLeg : PASGoogleBaseModelObject

@property (nonatomic, copy, readonly) NSString *duration;
@property (nonatomic, copy, readonly) NSString *distance;
@property (nonatomic, copy, readonly) NSString *startAddress;
@property (nonatomic, copy, readonly) NSString *endAddress;
@property (nonatomic, strong, readonly) PASGoogleLocationCoordinate *startLocationCoordinate;
@property (nonatomic, strong, readonly) PASGoogleLocationCoordinate *endLocationCoordinate;

+ (instancetype)newWithData:(NSDictionary *)data;

@end
