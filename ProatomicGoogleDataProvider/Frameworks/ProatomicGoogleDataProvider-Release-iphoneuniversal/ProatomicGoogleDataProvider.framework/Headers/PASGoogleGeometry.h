//
//  PASGoogleGeometry.h
//  ProatomicGoogleDataProvider
//
//  Created by Guillermo Sáenz on 7/21/17.
//  Copyright © 2017 Property Atomic Strong SAC. All rights reserved.
//

#import "PASGoogleBaseModelObject.h"

@class PASGoogleLocationCoordinate;

@interface PASGoogleGeometry : PASGoogleBaseModelObject

@property (nonatomic, copy, readonly) PASGoogleLocationCoordinate *locationCoordinate;

+ (instancetype)newWithData:(NSDictionary *)data;

@end
