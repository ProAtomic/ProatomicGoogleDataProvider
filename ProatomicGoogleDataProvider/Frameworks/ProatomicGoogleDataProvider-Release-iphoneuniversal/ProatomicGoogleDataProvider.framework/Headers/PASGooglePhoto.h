//
//  PASGooglePhoto.h
//  ProatomicGoogleDataProvider
//
//  Created by Guillermo Sáenz on 7/21/17.
//  Copyright © 2017 Property Atomic Strong SAC. All rights reserved.
//

#import "PASGoogleBaseModelObject.h"

@interface PASGooglePhoto : PASGoogleBaseModelObject

@property (nonatomic, copy, readonly) NSString *photoReference;

+ (instancetype)newWithData:(NSDictionary *)data;

@end
