void init(void)
{
    const char hw[] = "Hello World!";
    int i;
    char* video = (char*) 0xb8000;
    
    /* Clear the screen */
    for (i = 0; i < (80 * 25); ++i) {
        video[i * 2] = 0;
        video[i * 2 + 1] = 0x0;
    }

    /* Print boot string */
    for (i = 0; hw[i] != '\0'; i++) {
        video[i * 2] = hw[i];
        video[i * 2 + 1] = 0x07;
    } 
}
