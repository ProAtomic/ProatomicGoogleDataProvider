//
//  PASGoogleAddress.h
//  ProatomicGoogleDataProvider
//
//  Created by Guillermo Sáenz on 7/21/17.
//  Copyright © 2017 Property Atomic Strong SAC. All rights reserved.
//

#import "PASGoogleBaseModelObject.h"

@import CoreLocation;

@class PASGoogleGeometry;
@class PASGoogleAddressComponents;

@interface PASGoogleAddress : PASGoogleBaseModelObject

@property (nonatomic, copy, readonly) NSString *formattedAddress;
@property (nonatomic, strong, readonly) NSArray <PASGoogleAddressComponents *> *addressComponents;
@property (nonatomic, strong, readonly) PASGoogleGeometry *geometry;

+ (instancetype)newWithData:(NSDictionary *)data;

@end

@interface PASGoogleAddress (PASAccessors)

@property (nonatomic, copy, readonly) NSString *streetNumber;
@property (nonatomic, copy, readonly) NSString *route;
@property (nonatomic, copy, readonly) NSString *locality;
@property (nonatomic, copy, readonly) NSString *administrativeAreaLevel2;
@property (nonatomic, copy, readonly) NSString *country;
@property (nonatomic, copy, readonly) NSString *postalCode;

@end
