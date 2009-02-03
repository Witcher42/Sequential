/* Copyright © 2007-2008, The Sequential Project
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the the Sequential Project nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE Sequential Project ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE Sequential Project BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
#import <Cocoa/Cocoa.h>

// Views
@class PGAlertGraphic;

// Categories
#import "NSBezierPathAdditions.h"

enum {
	PGSingleImageGraphic,
	PGInterImageGraphic
};
typedef unsigned PGAlertGraphicType;

@interface PGAlertView : NSView
{
	@private
	NSMutableArray *_graphicStack;
	PGAlertGraphic *_currentGraphic;
	unsigned        _frameCount;
	NSTimer        *_frameTimer;
}

- (PGAlertGraphic *)currentGraphic;
- (void)pushGraphic:(PGAlertGraphic *)aGraphic window:(NSWindow *)window;
- (void)popGraphic:(PGAlertGraphic *)aGraphic;
- (void)popGraphicIdenticalTo:(PGAlertGraphic *)aGraphic;
- (void)popGraphicsOfType:(PGAlertGraphicType)type;

- (unsigned)frameCount;
- (void)animateOneFrame:(NSTimer *)aTimer;

- (void)windowWillClose:(NSNotification *)aNotif;

@end

@interface PGAlertGraphic : NSObject

+ (id)cannotGoRightGraphic;
+ (id)cannotGoLeftGraphic;
+ (id)loopedRightGraphic;
+ (id)loopedLeftGraphic;

- (PGAlertGraphicType)graphicType;

- (void)drawInView:(PGAlertView *)anAlertView;
- (void)flipHorizontally;
- (NSTimeInterval)fadeOutDelay; // Less than 0.01 means forever.

- (NSTimeInterval)animationDelay; // Less than or equal to 0 means don't animate.
- (unsigned)frameMax;
- (void)animateOneFrame:(PGAlertView *)anAlertView;

@end

@interface PGLoadingGraphic : PGAlertGraphic
{
	@private
	float _progress;
}

+ (id)loadingGraphic;

- (float)progress;
- (void)setProgress:(float)progress;

@end

@interface PGBezierPathIconGraphic : PGAlertGraphic
{
	@private
	AEIconType _iconType;
}

+ (id)graphicWithIconType:(AEIconType)type;
- (id)initWithIconType:(AEIconType)type;

@end
