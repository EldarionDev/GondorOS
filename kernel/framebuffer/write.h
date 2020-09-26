extern int  FRA_cursor_pos;
extern int  FRA_escape_character;

extern char FRA_fg_color;
extern char FRA_bg_color;

extern char*    FRA_video_address;

typedef enum    FRA_Color {
Black   =   0x0,
    Blue    =   0x1,
    Green   =   0x2,
    Cyan    =   0x3,
    Red     =   0x4,
    Magenta =   0x5,
    Brown   =   0x6,
    Light_Grey  =   0x7,
    Dark_Grey   =   0x8,
    Light_Blue  =   0x9,
    Light_Green =   0x10,
    Light_Cyan  =   0x11,
    Light_Red   =   0x12,
    Light_Magenta   =   0x13,
    Light_Brown =   0x14,
    White   =   0x15
} FRA_Color;

void    FRA_set_color   (FRA_Color  fgColor, FRA_Color  bgColor);

void    FRA_new_page    ();

int     FRA_write       (const char*    text);


