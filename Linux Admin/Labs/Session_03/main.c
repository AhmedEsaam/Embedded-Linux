#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char var = 0;

    /* create a new file descriptor and write on it */
    int fd = 0;
    fd = open("var", O_RDWR);

    printf("my file desscriptor: %d\n", fd);

    write(fd, "hello from var\n", 16);
    write(4, "hello from fd 4\n", 16);

    /* to print on the output */
    printf("hello\n");

    /* to choose which file stream to print on */
    /* 'stdin', 'stdout', 'stderr', ...*/
    fprintf(stderr, "hello from error\n");
    fprintf(stdout, "hello from out\n");

    /* to take input from the fd input */
    printf("Enter a character: ");
    scanf("%c", &var);

    printf("%c\n", var);

    while (1)
        ;

    return 0;
}
