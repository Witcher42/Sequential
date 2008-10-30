/* Copyright © 2007-2008 The Sequential Project. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal with the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:
1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimers.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimers in the
   documentation and/or other materials provided with the distribution.
3. Neither the name of The Sequential Project nor the names of its
   contributors may be used to endorse or promote products derived from
   this Software without specific prior written permission.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
THE CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS WITH THE SOFTWARE. */
#import <Cocoa/Cocoa.h>

enum {
	PGNoEdges       = 0,
	PGMinXEdgeMask  = 1 << NSMinXEdge,
	PGMinYEdgeMask  = 1 << NSMinYEdge,
	PGMaxXEdgeMask  = 1 << NSMaxXEdge,
	PGMaxYEdgeMask  = 1 << NSMaxYEdge,
	PGHorzEdgesMask = PGMinXEdgeMask | PGMaxXEdgeMask,
	PGVertEdgesMask = PGMinYEdgeMask | PGMaxYEdgeMask,
	PGMinEdgesMask  = PGMinXEdgeMask | PGMinYEdgeMask,
	PGMaxEdgesMask  = PGMaxXEdgeMask | PGMaxYEdgeMask
};
typedef unsigned PGRectEdgeMask;

enum {
	PGReadingDirectionLeftToRight = 0,
	PGReadingDirectionRightToLeft = 1
};
typedef int PGReadingDirection;

enum {
	PGHomeLocation = 0,
	PGEndLocation  = 1
};
typedef int PGPageLocation;

enum {
	PGUpright      = 0,
	PGFlippedVert  = 1 << 0,
	PGFlippedHorz  = 1 << 1,
	PGRotated90CC  = 1 << 2, // Counter-Clockwise.
	PGUpsideDown   = PGFlippedVert | PGFlippedHorz,
	PGRotated270CC = PGFlippedVert | PGFlippedHorz | PGRotated90CC
};
typedef unsigned PGOrientation;

typedef struct {
	float minX;
	float minY;
	float maxX;
	float maxY;
} PGInset;