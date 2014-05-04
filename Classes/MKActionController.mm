//
//  MKActionController.cpp
//  InTheField
//
//  Created by Minko on 14-5-4.
//
//
#include "MKActionController.h"
#import <UIKit/UIKit.h>
@interface MKSwipe:NSObject
-(void)registeGes:(id) view;
//-(void)swipHandler:(UIGestureRecognizer *)recognizer;
@end

@implementation MKSwipe
-(void)swipHandler:(UIGestureRecognizer *)recognizer
{
    auto swipe = (UISwipeGestureRecognizer*)recognizer;
    NSMutableString* direction = [[NSMutableString alloc]init];
    switch(swipe.direction)
    {
        case UISwipeGestureRecognizerDirectionUp:
            direction = @"向上↑";
            break;
        case UISwipeGestureRecognizerDirectionLeft:
            direction = @"向左←";
            break;
        case UISwipeGestureRecognizerDirectionRight:
            direction = @"向右→";
            break;
    }
    NSLog(@"当前手势%@", direction);
}
-(void)registeGes:(id) view
{
    auto swipe = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(swipHandler:)];
    swipe.direction = UISwipeGestureRecognizerDirectionLeft;
    [view addGestureRecognizer:swipe];
    [swipe release];
    
    swipe = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(swipHandler:)];
    swipe.direction = UISwipeGestureRecognizerDirectionRight;
    [view addGestureRecognizer:swipe];
    [swipe release];
    
    swipe = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(swipHandler:)];
    swipe.direction = UISwipeGestureRecognizerDirectionUp;
    [view addGestureRecognizer:swipe];
    [swipe release];
}

@end

void MKActionController::registControl(void* view)
{
    auto swipe = [[MKSwipe alloc] init];
    [swipe registeGes:(UIView*) view];
}

