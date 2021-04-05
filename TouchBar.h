
#ifndef TouchBar_h
#define TouchBar_h
#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

@interface TBWMenuItem : NSObject {
    @public
        NSString* title;
        bool state;
        NSInteger objid;
        NSString *btnimage;
        NSColor* color;
        NSCustomTouchBarItem* btnReferance;
        NSColorPickerTouchBarItem* colReferance;
}
@end

@interface TBWMenuContext : NSObject {
@public
    NSString* title;
    NSInteger ctxid;
    NSString *btnimage;
    NSMutableArray<TBWMenuItem *> *mItems;
}

-(TBWMenuItem*)AddButton:(NSString*)title;
-(TBWMenuItem*)AddButtonWithImage:(NSString*)title :(NSString*)image;
-(TBWMenuItem*)AddColorPicker:(NSString*)title :(NSColor*)defaultColor;
-(TBWMenuItem*)AddButton:(NSString*)title :(NSString*)image :(NSColor*)defaultColor;
@end

@interface TBWrapperMenu : NSObject
    - (TBWMenuContext*)BeginMenu:(NSString*)title;
    - (TBWMenuContext*)BeginMenu:(NSString*)title : (NSString*) image;
    - (void)EndMenu:(TBWMenuContext*)context;
    - (NSArray<NSString*>*)GetCtx: (NSInteger)ctxID;
@end

extern TBWrapperMenu* wrapperMenu;

void UpdateTouchBar(NSInteger iIndex);
#endif /* TouchBar_h */
