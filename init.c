int currentCursorPosition   =   0;
int escapeCharacter =   0;
char* video = (char*) 0xb8000;
char    fgColor;
char    bgColor;

typedef enum    Color {
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
} Color;

void    screen_set_color    (Color  fg_col, Color   bg_col) {
    fgColor =   fg_col;
    bgColor =   bg_col;
}   

void    screen_new_page () {
    for     (int i = 0; i < (80 * 25); ++i) {
        video[i * 2]    =   0;
        video[i * 2 + 1]    =   0x0;
    }
}

void    write   (const char*  text) {
    for     (int i = 0; ; ++i) {
        switch  (text[i]) {
        case '\0':
            return;
        case '\a':
            break;
        case '\b':
            video[currentCursorPosition * 2 - 1]    =   0;
        case '\e':
            escapeCharacter =   1;
            break;
        case '\f':
            screen_new_page();
            break;
        case '\n':
            currentCursorPosition   +=  80 - (currentCursorPosition % 80);
            break;
        case '\r':
            currentCursorPosition   -=  80 - (currentCursorPosition % 80);
            break;
        case '\t':
            currentCursorPosition   +=  8;
            break;
        case '\v':
            currentCursorPosition   +=  480;
            break;
        default:
            if  (escapeCharacter) {
                escapeCharacter =   0;
                break;
            }
            video[currentCursorPosition * 2]    =   text[i];
            video[currentCursorPosition * 2 + 1]    =   (bgColor << 4) + fgColor;
            ++currentCursorPosition;
            break; 
        }
    }
}

void init(void)
{
    const char hw[] = "Hello World!\nThis is a line break\nAnd this is a \tTab.";

    /* Clears the screen. */
    screen_new_page();
    screen_set_color(Green, Blue);

    /* Print boot string */
    /*for (i = 0; hw[i] != '\0'; i++) {
        video[i * 2] = hw[i];
        video[i * 2 + 1] = 0x36;
    } */
    write(hw);
}
