#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    char brightness;

    /* Open a file descriptor on the Capslock Brightness file */
    fd = open("/sys/class/leds/input3::capslock/brightness", O_RDWR);

    read(fd, &brightness, 1);

    /* print the brightness status */
    printf("%c", brightness);

    // store the output into file output */
    fd = open("./output", O_RDWR);

    write(fd, &brightness, 1);

    return 0;
}