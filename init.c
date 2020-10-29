#include "kernel/framebuffer/write.h"

void init(void) {
    const char boot_string[] = "Hello World!\nThis is GondorOS by Eldarion.\nFOR GONDOR!\n\0";

    /* Clears the screen. */
    FRA_new_page();
    FRA_set_color(Dark_Grey, Light_Brown);
    FRA_write(boot_string);
}
