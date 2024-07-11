#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char brightness;

#define USE_PIPING 1

#if USE_PIPING == 0

    /* Read input from the file './output' */
    fd = open("./output", O_RDWR);

    read(fd, &brightness, 1);

#else

    /* Read the input from the right-hand-side of the piping (|) operator */
    scanf("%c", &brightness);

#endif

    /* Toggle Capslock Brightness */
    brightness = (brightness == '0') ? '1' : '0';

    /* Open the Capslock Brightness file */
    fd = open("/sys/class/leds/input3::capslock/brightness", O_RDWR);

    /* overwrite the brightness with the new value */
    write(fd, &brightness, 1);

    /* Print the Capslock Brightness Status*/
    switch (brightness)
    {
    case '0':
        printf("Capslock brightness off\n");
        break;

    case '1':
        printf("Capslock brightness on\n");
        break;

    default:
        break;
    }

    return 0;
}