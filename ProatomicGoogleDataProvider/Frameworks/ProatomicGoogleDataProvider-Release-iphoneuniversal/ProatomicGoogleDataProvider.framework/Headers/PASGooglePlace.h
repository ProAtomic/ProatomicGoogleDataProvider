//
//  PASGooglePlace.h
//  ProatomicGoogleDataProvider
//
//  Created by Guillermo Sáenz on 7/20/17.
//  Copyright © 2017 Property Atomic Strong SAC. All rights reserved.
//

#import "PASGoogleBaseModelObject.h"

@import UIKit;
@import CoreLocation;

@class PASGoogleGeometry;
@class PASGooglePhoto;

@interface PASGooglePlace : PASGoogleBaseModelObject

@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, copy, readonly) NSString *address;
@property (nonatomic, strong, readonly) PASGoogleGeometry *geometry;
@property (nonatomic, strong, readonly) NSArray <PASGooglePhoto *> *photos;
@property (nonatomic, strong, readonly) NSArray <NSString *> *types;

+ (instancetype)newWithData:(NSDictionary *)data;

@end
