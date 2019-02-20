//
//  PASGoogleDataProvider.h
//  ProatomicGoogleDataProvider
//
//  Created by Guillermo Sáenz on 7/20/17.
//  Copyright © 2017 Property Atomic Strong SAC. All rights reserved.
//

@import Foundation;
@import UIKit;
@import CoreLocation;

@class PASGooglePlace;
@class PASGoogleDirection;
@class PASGoogleAddress;

/**
 *  @typedef PASGoogleDataProviderRouteMode
 *  @brief Specifies the mode of transport to use when calculating directions
 */
typedef enum : NSUInteger {
    PASGoogleDataProviderRouteModeDefault,
    /**
     *  Indicates standard driving directions using the road network.
     */
    PASGoogleDataProviderRouteModeDriving,
    /**
     *  Requests walking directions via pedestrian paths & sidewalks (where available).
     */
    PASGoogleDataProviderRouteModeWalking,
    /**
     *  Requests bicycling directions via bicycle paths & preferred streets (where available).
     */
    PASGoogleDataProviderRouteModeBicycling,
    /**
     *  Requests directions via public transit routes (where available).
     */
    PASGoogleDataProviderRouteModeTransit
} PASGoogleDataProviderRouteMode;

/**
 *  @typedef PASGoogleDataProviderResponseLanguage
 *  @brief Specifies the language in which to return results.
 */
typedef enum : NSUInteger {
    PASGoogleDataProviderResponseLanguageDefault,
    /**
     *  Spanish
     */
    PASGoogleDataProviderResponseLanguageES,
    /**
     *  English
     */
    PASGoogleDataProviderResponseLanguageEN
} PASGoogleDataProviderResponseLanguage;

/**
 *  @typedef PASGoogleDataProviderUnits
 *  @brief Specifies the unit system to use when displaying results.
 */
typedef enum : NSUInteger {
    PASGoogleDataProviderUnitsDefault,
    /**
     *  Specifies usage of the metric system. Textual distances are returned using kilometers and meters.
     */
    PASGoogleDataProviderUnitsMetric,
    /**
     *  Specifies usage of the Imperial (English) system. Textual distances are returned using miles and feet.
     */
    PASGoogleDataProviderUnitsImperial,
} PASGoogleDataProviderUnits;

/**
 *  @typedef PASGoogleDataProviderStatusCode
 *  @brief The status field within the Directions response object contains the status of the request, and may contain debugging information to help you track down why the Directions service failed.
 */
typedef enum : NSUInteger {
    /**
     *  Indicates the response contains a valid result.
     */
    PASGoogleDataProviderStatusCodeOK,
    /**
     *  Indicates at least one of the locations specified in the request's origin, destination, or waypoints could not be geocoded.
     */
    PASGoogleDataProviderStatusCodeNotFound,
    /**
     *  Indicates no route could be found between the origin and destination.
     */
    PASGoogleDataProviderStatusCodeZeroResults,
    /**
     *  Indicates that too many waypointss were provided in the request The maximum allowed waypoints is 8, plus the origin, and destination.
     */
    PASGoogleDataProviderStatusCodeMaxWaypointsExceeded,
    /**
     *  Indicates that the provided request was invalid. Common causes of this status include an invalid parameter or parameter value.
     */
    PASGoogleDataProviderStatusCodeInvalidRequest,
    /**
     *  Indicates the service has received too many requests from your application within the allowed time period.
     */
    PASGoogleDataProviderStatusCodeOverQueryLimit,
    /**
     *  Indicates that the service denied use of the directions service by your application.
     */
    PASGoogleDataProviderStatusCodeRequestDenied,
    /**
     *  Indicates a directions request could not be processed due to a server error. The request may succeed if you try again.
     */
    PASGoogleDataProviderStatusCodeUnknownError
} PASGoogleDataProviderStatusCode;

@interface PASGoogleDataProvider : NSObject

+ (instancetype)newWithAPIKey:(NSString *)APIKey;
- (instancetype)initWithAPIKey:(NSString *)APIKey;

/*! @abstract Use newWithAPIKey: to init with an API Key. */
+ (instancetype)new NS_UNAVAILABLE;

/*! @abstract Use initWithAPIKey: to init with an API Key. */
- (instancetype)init NS_UNAVAILABLE;

/**
 Queries Google API for routes between 2 points
 
 @param fromLocationCoordinate Start coordinates.
 @param toLocationCoordinate End coordinates.
 @param routeMode Specifies the mode of transport to use when calculating directions.
 @param multipleAlternatives Use this bool to ask for multiple alternatives for the direction.
 @param resultsLanguage Specifies the language in which to return results.
 @param unitSystem Specifies the unit system to use when displaying results.
 @param success success block.
 @param failure failure block.
 @return returns a NSURLSessionDataTask;
 */
- (NSURLSessionDataTask *)fetchDirectionsFromLocationCoordinate:(CLLocationCoordinate2D)fromLocationCoordinate
                                           toLocationCoordinate:(CLLocationCoordinate2D)toLocationCoordinate
                                                      routeMode:(PASGoogleDataProviderRouteMode)routeMode
                                           multipleAlternatives:(BOOL)multipleAlternatives
                                                resultsLanguage:(PASGoogleDataProviderResponseLanguage)resultsLanguage
                                                     unitSystem:(PASGoogleDataProviderUnits)unitSystem
                                                        success:(void (^)(NSArray <PASGoogleDirection *> *directions))success
                                                        failure:(void (^)(NSError *error, PASGoogleDataProviderStatusCode statusCode))failure;

/**
 Queries Google API for near places of a location coordinates
 
 @param locationCoordinate Point's location coordinates.
 @param radius Radius of the query in meters.
 @param type It only supports 1 type per query. See https://developers.google.com/places/web-service/supported_types
 @param resultsLanguage Specifies the language in which to return results.
 @param success success block.
 @param failure failure block.
 @return returns a NSURLSessionDataTask;
 */
- (NSURLSessionDataTask *)fetchPlacesNearLocationCoordinate:(CLLocationCoordinate2D)locationCoordinate
                                                     radius:(CGFloat)radius
                                                       type:(NSString *)type
                                            resultsLanguage:(PASGoogleDataProviderResponseLanguage)resultsLanguage
                                                    success:(void (^)(NSArray <PASGooglePlace *> *places))success
                                                    failure:(void (^)(NSError *error, PASGoogleDataProviderStatusCode statusCode))failure;

/**
 Queries Google API for the reverse geocoding of a location coordinates
 
 @param locationCoordinate Point's location coordinates.
 @param resultsLanguage Specifies the language in which to return results.
 @param success success block.
 @param failure failure block.
 @return returns a NSURLSessionDataTask;
 */
- (NSURLSessionDataTask *)reverseGeocodingFromLocationCoordinate:(CLLocationCoordinate2D)locationCoordinate
                                                 resultsLanguage:(PASGoogleDataProviderResponseLanguage)resultsLanguage
                                                         success:(void (^)(NSArray <PASGoogleAddress *> *addresses))success
                                                         failure:(void (^)(NSError *error, PASGoogleDataProviderStatusCode statusCode))failure;

/**
 Composes a string of a valid URL that includes the provided API and photo reference.
 
 @param reference Reference parameter of a place photo.
 @param maxWidth Max with of the image. Google with return an image that repects the aspect ratio and provided width.
 @return NSString
 */
- (NSString *)getPlacePhotoURLFromReference:(NSString *)reference maxWidth:(NSNumber *)maxWidth;

@end
