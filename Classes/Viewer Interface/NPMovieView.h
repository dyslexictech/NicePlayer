/**
 * NPMovieView.h
 * NicePlayer
 */

#import <Cocoa/Cocoa.h>
#import "Pluggable Players/NPMovieProtocol.h"
#import "NiceWindow.h"
#import "ControlButton.h"
#import "NPPluginReader.h"

@class ControlPlay;
@class NiceWindow;

@interface NPMovieView : NSView {
    NSURL *openedURL;
    id trueMovieView;
    id contextMenu;
    id title;
    
    NSTrackingRectTag trackingRect;
    
    NSString *fileType;
    NSString *fileExtension;

    BOOL dragButton;
    BOOL wasPlaying;
    BOOL mouseEntered;
}

+(id)blankImage;

-(BOOL)openURL:(NSURL *)url;
-(void)switchToPlugin:(id)sender;
-(void)switchToPluginClass:(Class)aClass;
-(BOOL)loadMovie;
-(void)closeReopen;
-(void)close;

-(void)mouseDoubleClick:(NSEvent *)anEvent;

-(void)start;
-(void)stop;
-(void)ffStart;
-(void)ffDo;
-(void)ffDo:(int)aSeconds;
-(void)ffEnd;
-(void)rrStart;
-(void)rrDo;
-(void)rrDo:(int)aSeconds;
-(void)rrEnd;

-(void)toggleMute;
-(void)incrementVolume;
-(void)decrementVolume;
-(void)setVolume:(float)aVolume;
-(float)volume;

-(BOOL)isPlaying;
-(BOOL)wasPlaying;
-(void)playPrevMovie;
-(void)playNextMovie;
-(void)finalProxyViewLoad;

-(void)showOverLayVolume;
-(void)smartHideMouseOverOverlays;
-(void)timedHideOverlayWithSelector:(NSString *)aStringSelector;
-(void)cancelPreviousPerformRequestsWithSelector:(NSString *)aStringSelector;
-(void)hideOverlayWithSelector:(NSString *)aStringSelector;

-(Class)currentPluginClass;
-(id)myMenu;
-(id)menuTitle;
-(id)pluginMenu;
-(id)contextualMenu;
-(void)rebuildMenu;

-(BOOL)canAnimateResize;
-(void)scrollWheelResize:(NSEvent *)anEvent;
-(void)scrollWheelAdjustVolume:(NSEvent *)anEvent;

#pragma mark -
#pragma mark Calculations

-(double)scrubLocation:(id)sender;
-(NSSize)naturalSize;
-(BOOL)hasEnded:(id)sender;
-(BOOL)muted;
-(void)setMuted:(BOOL)aBool;
-(double)currentMovieTime;
-(double)currentMovieFrameRate;
-(void)setCurrentMovieTime:(double)aDouble;
-(double)totalTime;
-(void)drawMovieFrame;
-(void)setLoopMode:(NSQTMovieLoopMode)flag;

@end
