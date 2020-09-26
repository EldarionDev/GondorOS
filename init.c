#include "kernel/framebuffer/write.h"

void init(void)
{
    const char boot_string[] = "Hello World!\nThis is GondorOS by Eldarion.\nFOR GONDOR!\n";

    /* Clears the screen. */
    FRA_new_page();
    FRA_set_color(Green, Blue);
    int     boot_string_end =   0;
    char    current_color_fg    =   0x0;
    int     current_char        =   0;
    while   (!boot_string_end) {
        ++current_char;
        if      (current_color_fg   ==  0x14)
            current_color_fg    =   0x0;
        ++current_color_fg;
        FRA_set_color(current_color_fg, 0x0);
        if  (boot_string[current_char - 1]  ==  '\0')
            break;
        char    newStr[2];
        newStr[0]   =   boot_string[current_char - 1];
        newStr[1]   =   '\0';
        FRA_write(newStr);
    }
}
