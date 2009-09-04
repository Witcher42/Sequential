/* Copyright © 2007-2009, The Sequential Project
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

THIS SOFTWARE IS PROVIDED BY THE SEQUENTIAL PROJECT ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE SEQUENTIAL PROJECT BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
#import <Cocoa/Cocoa.h>

// Models
@class PGNode;
@class PGContainerAdapter;

@interface PGXMLParser : NSObject <NSXMLParserDelegate>
{
	@private
	NSXMLParser    *_parser;
	PGXMLParser    *_parent;
	NSURL          *_baseURL;
	NSMutableArray *_subparsers;
	NSString       *_initialTagPath;
	NSString       *_tagPath;
	NSDictionary   *_attributes;
	NSArray        *_classes;
}

+ (id)parserWithData:(NSData *)data baseURL:(NSURL *)URL classes:(NSArray *)classes;
+ (BOOL)canParseTagPath:(NSString *)p attributes:(NSDictionary *)attrs;

- (NSURL *)baseURL;
- (void)setBaseURL:(NSURL *)URL;

- (void)parseWithData:(NSData *)data;

- (PGXMLParser *)parentParser;
- (NSArray *)subparsers;
- (void)useSubparser:(PGXMLParser *)parser;

- (void)beganTagPath:(NSString *)p attributes:(NSDictionary *)attrs;
- (NSMutableString *)contentStringForTagPath:(NSString *)p;
- (void)endedTagPath:(NSString *)p;

@end

@interface PGXMLParser(PGXMLParserNodeCreation)

- (BOOL)createsMultipleNodes;

- (NSString *)title;
- (NSURL *)URL;
- (NSError *)error;
- (id)info;

- (NSString *)URLString;
- (NSString *)errorString;

- (NSArray *)nodesWithParentAdapter:(PGContainerAdapter *)parent;
- (PGNode *)nodeWithParentAdapter:(PGContainerAdapter *)parent;

@end
