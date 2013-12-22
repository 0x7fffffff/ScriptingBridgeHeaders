/*
 * BluetoothFileExchange.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class BluetoothFileExchangeApplication;



/*
 * Standard Suite
 */

@interface BluetoothFileExchangeApplication : SBApplication

- (void) browseDevice:(NSString *)device;  // Browse a device.
- (void) sendFile:(NSURL *)file toDevice:(NSString *)toDevice;  // Send a file to a bluetooth device.

@end

