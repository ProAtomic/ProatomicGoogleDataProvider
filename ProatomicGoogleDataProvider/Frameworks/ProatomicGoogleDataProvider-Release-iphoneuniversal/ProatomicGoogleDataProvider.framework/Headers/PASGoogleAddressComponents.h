//
//  PASGoogleAddressComponents.h
//  ProatomicGoogleDataProvider
//
//  Created by Guillermo Sáenz on 7/21/17.
//  Copyright © 2017 Property Atomic Strong SAC. All rights reserved.
//

#import "PASGoogleBaseModelObject.h"

/**
 *  @typedef PASGoogleDataProviderUnits
 *  @brief Specifies the type of address component.
 */
typedef enum : NSUInteger {
    PASGoogleAddressComponentTypeDefault,
    /**
     *  Specifies the type street number for the address component.
     */
    PASGoogleAddressComponentTypeStreetNumber,
    /**
     *  Specifies the type route for the address component.
     */
    PASGoogleAddressComponentTypeRoute,
    /**
     *  Specifies the type locality for the address component.
     */
    PASGoogleAddressComponentTypeLocality,
    /**
     *  Specifies the type administrative area level 1 for the address component.
     */
    PASGoogleAddressComponentTypeAdministrativeAreaLevel1,
    /**
     *  Specifies the type administrative area level 2 for the address component.
     */
    PASGoogleAddressComponentTypeAdministrativeAreaLevel2,
    /**
     *  Specifies the type country for the address component.
     */
    PASGoogleAddressComponentTypeCountry,
    /**
     *  Specifies the type postal code for the address component.
     */
    PASGoogleAddressComponentTypePostalCode,
} PASGoogleAddressComponentType;

@interface PASGoogleAddressComponents : PASGoogleBaseModelObject

@property (nonatomic, copy, readonly) NSString *longName;
@property (nonatomic, copy, readonly) NSString *shortName;
@property (nonatomic, assign, readonly) PASGoogleAddressComponentType type;

+ (instancetype)newWithData:(NSDictionary *)data;

@end
