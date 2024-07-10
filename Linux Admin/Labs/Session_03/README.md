# Linux Admin - Session 03 Notes

## Redirection & File Descriptor

It's the redirection of one of the process file descriptors to another file.

* Three files are created automatically for every process: (they all see the terminal)

    1. File `0`: provides the process with the **input**.
    2. File `1`: stores the **output** of the process.
    3. File `2`:  

* Say we have a file called `mian.c` that takes file inputs and yields them as its outputs.:

```c
#include <stdio.h>

int main(int argc, char* argv[])
{
    char name[10];
    
    printf("Pls Enter Your Name: ");    // to fd1
    
    scanf("%s", name);                  // from fd0
    printf("hello %s!\n", name);        // to fd1

    for(int i = 0; i < argc; ++i)
    {
            printf("%s \n", argv[i]);   // to fd1
    }

    return 0;
}
```

* When you write:

```bash
./main.exe
```

This command writes its output on its output file descriptor `1`, hence this output gets printed on the terminal.

* If you want to change this output from be printed omn terminal to another file:

```bash
./main.exe > output
```



### View process files

* To view processes that runs on terminal:

```bash
ps -at
```

* navigate to the process id in the `/proc` directory and list its files:

```bash
cd /proc/42103
ls
```

* You can view the stack of this process

```bash
sudo cat stack
```

* You canalso view the file descriptors of this process

```bash
cd /proc/42103/fd
ls -lh
```

* You will find that there are 3 files `0, 1, 2` for input, output, and error.

* Initially all of the three are redirected to the terminal. (the terminal provides the input and displays the output and the error).

* **Note:** you can directly write on this terminal by writing on th terminal file

```bash
ps -at      # first know which terminal you want to write on
echo 5 > /dev/pts/0
```

* You can also directly write on the process fd input file `0`:

```bash
echo 5 > /proc/5654/fd/0
```

* If you want to take the process input from a file, you can redirect the input file descriptor `1` to another file:

```bash
./main.exe < var
```

* You can also write directly on one of the file descriptors directly from within your code:

```c
fprintf(stderr, "hello from error");

fprintf(stdout, "hello from output");
```

* you can redirect the three files

```bash
./main.exe 2> error > output < var
```

* Errors in the code will be directly printed on the fd error file `2`

* Suppose main.c has errors, these errors will automatically directed to the erro file

```c
gcc main.c 2> error
```

* You can create new file descriptor from within code and write on it

```cpp
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
    fd = open("var", O_RDWR);           // O_RDWR for read and write permissions

    printf("my file desscriptor: %d\n", fd);

    write(fd, "hello from var\n", 16);  // 16 is the number of bytes

    /* write on file descriptor 4 */
    write(4, "hello from fd 4\n", 16);
}
```

* here `fd` will take the value `3`

---

## Piping

### Inter Process Communication (IPS)

```shell
cat main.c | grep main
```

---

## Links

Is a shortcut used to run and edit a file from another place.

* **Note:** The **inode** is a data container for each file which collects all the file metadata. And each inode has a specific id.

### Soft Link

* It's another file (with a **different inode**) that points to the original file.

```shell
ln -s main.c mysoftlink
```

### Hard Link

* It have the **same inode** of the original file.

```shell
ln main.c myhardlink
```

* To see which took more space and each one's inode:

```shell
ls -li
```

### Softlinks Vs. Hardlinks

| Soft Link | hard Link |
| :--- | :--- |
| Can be used on directories | Cannot be used on Directories (only on files) |
| | Also cannot be used on files on a different storage blocks or devices (as it refers to the inode address in its storage space) |
