# Device Drivers

* **LKM** : Linux Kernel Modules.

* Linux kernel : handles the task and interface with it during runtime.

* **Module** : is a driver.

* There are two ways to inject a new driver:
  * **Static** : during linux compilation.
    * (it will be part of the linux kernel image : **zImage** file)
    * **Disadvantage** : Size of **zImage** will increase and this will make **startup** of the kernel slow.

  * **Dynamic** : during linux runtime.  
    * (a new file will be created **module.ko** and it can be loaded at runtime)
    * It is used to :
      * Increase security.
      * File system.
      * device drivers
    * **Advantage** :  loading at runtime (from user space)
    * **Disadvantage**:
        1. Size of the `.ko` file will be larger.
        2. Startup of the module will be slow.
    * **Linux Commands**:
      * `sudo ismod` : to insert a module.
      * `sudo rmmod` : to remove a module.
      * `modprobe` : insert & remove modules.
      * `lsmod` : list dynamic modules.

## LKM Syntax

1. **Header Section**
   1. #include (kernel headers) : which their `.c` files are implemented in the linux kernel code.
      1. When choosing the linux headers, make sure they're compatible with linux source code version
         1. Use `uname -r` : your linux kernel version.
         2. They are in `/usr/src/linux-headers-[kernel verrsion]/include/`
         3. Make sure that you use the same linux version
      2. The module will be running in the kernel space. So,
         1. No user-space libraryis linked with kernel module.

2. **Code Section**
   1. **C functions**, but with restrictions (linux gives you what you need -a template-)
   2. You won't have a `main()` function, as the kernel has the `main()` function.
   3. There are two functions:
      1. `module initialization` : your init function (it must return `int`).
      2. `module deinitialization` : deinit module (it's a `void` function).
   4. Add the functions to function-like macros.
      1. `module_int(mykernelInit)`
      2. `module_exit(mykernelDeinit)`
   5. They are mapped to callback functions
   6. Setup environemnt for vscode: If libraries are not included, include them in the include path of the `c_cpp_properties.json` file : add the `/usr/src/...` path in the include section.
   7. Do not forget to add module livense in the code becuase kernel core (c-code of kernel) implemented based on **GPL**. Since your module will use linux source code **GPL**.

   >
   >```c
   >/*** Header Section ***/
   >#include <linux/module.h>
   >#include <linux/init.h>
   >#include <linux/cdev.h>
   >#include <linux/fs.h>
   >
   >/*** Code Section ***/
   >
   >/* Init Function */
   >int mykernel_init(void)
   >{
   >  /* print-function for kernel (prints in dmesg) */
   >  printk("Hello from kernel\n");
   >  /* init function succeeded */
   >  return 0;
   >}
   >
   >/* Deinit Function */
   >void mykernel_exit(void)
   >{
   >
   >}
   >
   >/* Passing your function to function-like macros which in turn pass them to callback functions */
   >module_init(mykernel_init);
   >module_exit(mykernel_exit);
   >
   >/* Module License */
   >MODULE_LICENSE("GPL");
   >```

3. How to build dynamic modules
   1. Call **Makefile** in the kernel source code.

```shell
make -C 
```
   2. Create a makefile:
      1. call makefile in jernel
      2. pass the value of the `obj-m` variable:
         1. Which indicate that you want to build this module as **dynamic**
         2. if you want to build it as **static** in the zImage, use `obj-y`.

```makefile
# Makefile for the kernel needs the value of this variable
obj-m := mydriver.o

all:
  make -C /lib/modules/...-generic/build M=$PWD modules
```

  3. Then call `make`
  4. After `make`, `mydriver.ko` will be created (a kernel object).
     1. The kernel space has increased by the `.ko` file size.

### Why the `.ko` file is larger than the `.o` static module in zImage?

* Use the `__init` with the init function.
  * The `__init` is a section in the linker script. This section will be deleted so as to consume less memory in ram as the init function is not needed afetr initialization.

* Use the `__exit` with the de-init function.
  * The `__exit` is a section in the linker script. This section will be deleted as soon as you remove the module so as to consume less memory in ram as the init function is not needed afetr initialization.
  * But in static modules, you cannot unload it from memory (the module is compiled altogether with kernel). So you don't need to put the `exit` section.

* So in **static** modules, the code have:
  * init function
  * code
* And in **Dynamic** modules
  * init function
  * code
  * exit function : needed only in dynamic modules.

### Implementation of (proc file system)

* All files created under `/prpc/` are created by kernel in RAM.
  * To see these files, you need to mount it as `proc` type (which is a dat structure in the kernel space).
* To create a file inside the `/proc/` directory, you need to create a kernel module.
* Include `<linux/proc_fs.h>`

1. To create a file under `/proc/`, use function `proc_create()`
2. Some sytem call operations that can be done on the file created under proc:
   1. proc_read
   2. proc_write

### How retrieve data from user

### Device Drivers Categories

1. Character Device (GPIO, UART, ...)
2. Block Device (Storage)
3. Network Device (Wifi, Ethernet, ...)

* empty this file `/var/log/kern.log`, `/var/log/sys.log` as this might take large size in memory after printing to it.
