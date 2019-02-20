//
//  PASGoogleBaseModelObject.h
//  ProatomicGoogleDataProvider
//
//  Created by Guillermo Sáenz on 7/20/17.
//  Copyright © 2017 Property Atomic Strong SAC. All rights reserved.
//

@import Foundation;

@interface PASGoogleBaseModelObject : NSObject <NSSecureCoding>

+ (NSString *)classNameString;

+ (instancetype)initWithArchivedVersion:(NSData *)archivedVersion;

- (NSData *)getArchivedVersion;

@end
