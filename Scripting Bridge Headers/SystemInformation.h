/*
 * SystemInformation.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class SystemInformationItem, SystemInformationApplication, SystemInformationColor, SystemInformationDocument, SystemInformationWindow, SystemInformationAttributeRun, SystemInformationCharacter, SystemInformationParagraph, SystemInformationText, SystemInformationAttachment, SystemInformationWord, SystemInformationPrintSettings;

enum SystemInformationSavo {
	SystemInformationSavoAsk = 'ask ' /* Ask the user whether or not to save the file. */,
	SystemInformationSavoNo = 'no  ' /* Do not save the file. */,
	SystemInformationSavoYes = 'yes ' /* Save the file. */
};
typedef enum SystemInformationSavo SystemInformationSavo;

enum SystemInformationEdtl {
	SystemInformationEdtlBasic = 'basi' /* A version which includes the basic hardware, software and network information.   Moderate in size. */,
	SystemInformationEdtlFull = 'full' /* A profile which includes all available information - can be quite large */,
	SystemInformationEdtlMini = 'mini' /* A compact profile which does not include any personal identifying information */
};
typedef enum SystemInformationEdtl SystemInformationEdtl;

enum SystemInformationEnum {
	SystemInformationEnumStandard = 'lwst' /* Standard PostScript error handling */,
	SystemInformationEnumDetailed = 'lwdt' /* print a detailed report of PostScript errors */
};
typedef enum SystemInformationEnum SystemInformationEnum;



/*
 * Standard Suite
 */

// A scriptable object.
@interface SystemInformationItem : SBObject

@property (copy) NSDictionary *properties;  // All of the object's properties.

- (void) closeSaving:(SystemInformationSavo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveAs:(NSString *)as in:(NSURL *)in_;  // Save an object.
- (void) send;  // Send to AppleCare

@end

// An application's top level scripting object.
@interface SystemInformationApplication : SBApplication

- (SBElementArray *) documents;
- (SBElementArray *) windows;

@property (readonly) BOOL frontmost;  // Is this the frontmost (active) application?
@property (copy, readonly) NSString *name;  // The name of the application.
@property (copy, readonly) NSString *version;  // The version of the application.

- (SystemInformationDocument *) open:(NSURL *)x;  // Open an object.
- (void) print:(NSURL *)x printDialog:(BOOL)printDialog withProperties:(SystemInformationPrintSettings *)withProperties;  // Print an object.
- (void) quitSaving:(SystemInformationSavo)saving;  // Quit an application.

@end

// A color.
@interface SystemInformationColor : SystemInformationItem


@end

// A document.
@interface SystemInformationDocument : SystemInformationItem

@property (readonly) BOOL modified;  // Has the document been modified since the last save?
@property (copy) NSString *name;  // The document's name.
@property (copy) NSString *path;  // The document's path.


@end

// A window.
@interface SystemInformationWindow : SystemInformationItem

@property NSRect bounds;  // The bounding rectangle of the window.
@property (readonly) BOOL closeable;  // Whether the window has a close box.
@property (copy, readonly) SystemInformationDocument *document;  // The document whose contents are being displayed in the window.
@property (readonly) BOOL floating;  // Whether the window floats.
- (NSInteger) id;  // The unique identifier of the window.
@property NSInteger index;  // The index of the window, ordered front to back.
@property (readonly) BOOL miniaturizable;  // Whether the window can be miniaturized.
@property BOOL miniaturized;  // Whether the window is currently miniaturized.
@property (readonly) BOOL modal;  // Whether the window is the application's current modal window.
@property (copy) NSString *name;  // The full title of the window.
@property (readonly) BOOL resizable;  // Whether the window can be resized.
@property (readonly) BOOL titled;  // Whether the window has a title bar.
@property BOOL visible;  // Whether the window is currently visible.
@property (readonly) BOOL zoomable;  // Whether the window can be zoomed.
@property BOOL zoomed;  // Whether the window is currently zoomed.


@end



/*
 * Text Suite
 */

// This subdivides the text into chunks that all have the same attributes.
@interface SystemInformationAttributeRun : SystemInformationItem

- (SBElementArray *) attachments;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end

// This subdivides the text into characters.
@interface SystemInformationCharacter : SystemInformationItem

- (SBElementArray *) attachments;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end

// This subdivides the text into paragraphs.
@interface SystemInformationParagraph : SystemInformationItem

- (SBElementArray *) attachments;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end

// Rich (styled) text
@interface SystemInformationText : SystemInformationItem

- (SBElementArray *) attachments;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end

// Represents an inline text attachment.  This class is used mainly for make commands.
@interface SystemInformationAttachment : SystemInformationText

@property (copy) NSString *fileName;  // The path to the file for the attachment


@end

// This subdivides the text into words.
@interface SystemInformationWord : SystemInformationItem

- (SBElementArray *) attachments;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end



/*
 * System Profiler suite
 */

// System Profiler top level scripting object.
@interface SystemInformationApplication (SystemProfilerSuite)

- (SBElementArray *) documents;

@property (copy, readonly) NSString *systemProfile;  // Plain text representation of a system profile for the current machine.

@end

// A system profile document.
@interface SystemInformationDocument (SystemProfilerSuite)

@property SystemInformationEdtl detailLevel;  // The desired level of detail for the system profile document.
@property (copy, readonly) NSString *plainText;  // Plain text representation of the system profile document.
@property (copy, readonly) NSString *profile;  // Plain text representation of the system profile document.
@property (copy, readonly) NSString *XMLText;  // XML representation of the system profile document.

@end



/*
 * Type Definitions
 */

@interface SystemInformationPrintSettings : SBObject

@property NSInteger copies;  // the number of copies of a document to be printed
@property BOOL collating;  // Should printed copies be collated?
@property NSInteger startingPage;  // the first page of the document to be printed
@property NSInteger endingPage;  // the last page of the document to be printed
@property NSInteger pagesAcross;  // number of logical pages laid across a physical page
@property NSInteger pagesDown;  // number of logical pages laid out down a physical page
@property (copy) NSDate *requestedPrintTime;  // the time at which the desktop printer should print the document
@property SystemInformationEnum errorHandling;  // how errors are handled
@property (copy) NSString *faxNumber;  // for fax number
@property (copy) NSString *targetPrinter;  // for target printer

- (void) closeSaving:(SystemInformationSavo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveAs:(NSString *)as in:(NSURL *)in_;  // Save an object.
- (void) send;  // Send to AppleCare

@end

