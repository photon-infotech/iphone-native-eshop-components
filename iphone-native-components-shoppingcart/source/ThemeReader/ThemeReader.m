//
//  ThemeReader.m
//  LoginComponent
//
//  Created by Rojaramani on 07/01/13.
//  Copyright (c) 2013 Photon. All rights reserved.
//

#import "ThemeReader.h"

@implementation ThemeReader

-(id) init {

    self = [super init];
    if(self) {
        dataDictionary = nil;
    }
    return self;
}


-(NSMutableDictionary*)loadDataFromPlist:(NSString*)key {
    
    NSFileManager *fileManager = [NSFileManager defaultManager];
    
    NSString* filePath = [[NSBundle mainBundle] pathForResource:@"Manifest" ofType:@"plist"];
    
    if ([fileManager fileExistsAtPath: filePath])
    {
        if(nil == dataDictionary)
        {
            dataDictionary = [[NSMutableDictionary alloc] init];
        }
        else
        {
            [dataDictionary removeAllObjects];
        }
        dataDictionary = [dataDictionary initWithContentsOfFile:filePath];
        return [dataDictionary objectForKey:key];
    }
    return  nil;
}

@end