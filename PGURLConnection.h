/* Copyright © 2007-2008 Ben Trask. All rights reserved.

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
3. The names of its contributors may not be used to endorse or promote
   products derived from this Software without specific prior written
   permission.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
THE CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS WITH THE SOFTWARE. */
#import <Cocoa/Cocoa.h>

extern NSString *const PGURLConnectionConnectionsDidChangeNotification;

enum {
	PGLoading      = 0,
	PGLoaded       = 1,
	PGLoadCanceled = 2
};
typedef unsigned PGLoadingStatus;

@interface PGURLConnection : NSObject // Wraps NSURLConnection so only a few connections are active at a time.
{
	@private
	NSURLRequest   *_request;
	NSURLResponse  *_response;
	NSMutableData  *_data;
	PGLoadingStatus _status;
	id              _delegate;
}

+ (NSString *)userAgent;
+ (void)setUserAgent:(NSString *)aString;

+ (NSArray *)connectionValues; // Use -nonretainedObjectValue to get the actual connection.
+ (NSArray *)activeConnectionValues;
+ (NSArray *)pendingConnectionValues;

- (id)initWithRequest:(NSURLRequest *)aRequest delegate:(id)anObject;
- (NSURLRequest *)request;
- (id)delegate;
- (NSURLResponse *)response;
- (NSMutableData *)data;
- (PGLoadingStatus)status;
- (float)progress;
- (void)prioritize;
- (void)cancel;

@end

@interface NSObject (PGURLConnectionDelegate)

- (void)connectionLoadingDidProgress:(PGURLConnection *)sender;
- (void)connectionDidReceiveResponse:(PGURLConnection *)sender;
- (void)connectionDidClose:(PGURLConnection *)sender;

@end
