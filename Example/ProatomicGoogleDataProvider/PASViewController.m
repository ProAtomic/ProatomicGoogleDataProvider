//
//  PASViewController.m
//  ProatomicGoogleDataProvider
//
//  Created by 942v on 08/11/2017.
//  Copyright (c) 2017 942v. All rights reserved.
//

#import "PASViewController.h"

@import ProatomicGoogleDataProvider;

@interface PASViewController ()

@end

@implementation PASViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    PASGoogleDataProvider *googleDataProvider = [PASGoogleDataProvider newWithAPIKey:@""];
    
    [googleDataProvider reverseGeocodingFromLocationCoordinate:CLLocationCoordinate2DMake(-12.099205017089856, -76.96675770085687)
                                               resultsLanguage:PASGoogleDataProviderResponseLanguageES
                                                       success:^(NSArray<PASGoogleAddress *> *addresses) {
                                                           NSLog(@"addresses: %@", addresses);
                                                       } failure:nil];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
