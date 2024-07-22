# Kernel Panic

```txt
Error Cannot find rootfs
```

* You must tell the Kernel where's the rootfs ext4 partition.
* U-boot has an evironment variable `bootargs` which we can send u-boot arguments:

## In Raspberry Bi

```sh
root=/dev/mmcblk0p2 rw      # tells the kernel to: mount -t ext4 /dev/mmcblk0p2 /, rw
console=/dev/tty0
```

* Why not `rwx`?: as in the kernel space there is no such thing as an executable file. It only read and write into memory.

## In Qemu

```sh
root=/dev/mmcblk0p2
console=/dev/ttyAMA0
```

### Attempt 1

```shell
Essam =>printenv bootargs
bootargs=console=tty0 console=ttyAMA0,38400n8
Essam =>editenv bootargs 
edit: console=tty0 console=ttyAMA0,38400n8 root=/dev/mmcblk0p2 rw
Essam =>saveenv
Saving Environment to FAT... OK

Essam =>bootflow scan
```

### Output 1

```txt
VFS: Mounted root (ext4 filesystem) on device 179:2.
Error No working init found.
```

### Attempt 2

```shell
Essam =>editenv bootargs 
edit: console=tty0 console=ttyAMA0,38400n8 root=/dev/mmcblk0p2 rw init=/init
Essam =>saveenv
```

### Output 2

```txt
Run /init as init process
helloKernel panic - not syncing: Attempted to kill init! 
```

* /init as / is the mounted dir for ext4

* Or `APPEND` the root= in the `extlinux.conf` file.

* clone the `shell`, compile it and put it as the init process.
  * But without external commands, which we will download from **Busybox**.

---

## Busybox

* **Busybox** is a fork from **Coreutils** with only important commands.

```shell
git clone busybox
make menuconfig     # Apps you need
make                # compile
make install        # will be stored in ./_install 
```

* It will allow us to populate `/bin`, `/sbin`, `/usr/bin`, `/usr/sbin`.

* Now we have:
  * `/bin`,
  * `/sbin`,
  * `/usr/bin`,
  * `/usr/sbin`,
  * `/usr/lib`
  * `/etc`,
  * `/dev`,     mounted from **RAM**
  * `/sys`,     mounted from **RAM**
  * `/proc`,    mounted from **RAM**

```shell
mount -t devtmpfs /dev
mount -t sysfs /sys
mount -t proc /proc
source sh
```

* We then we need to set the `PATH` variable in order to use applications like `ls`.

### Busybox init

* Location of any init process `/sbin/init` implemented with C code.
  * The `init` process will creat a configuration file `/etc/inittab`

### Inittab Syntax

```txt
node::action:Application to run
::sysinit:/usr/bin/mount -t devtmpfs /dev
::sysinit:/usr/bin/mount -t sys /sys
::sysinit:/usr/bin/mount -t proc /proc
```

* Actions:
  1. `sysinit`: Specify which application (sytem essential apps) to run @ first and **wait** for completion
  2. `wait`: Run the application (in run time like mouse) and **wait** for completion
  3. `once`: Run the application (here the branching starts) and **don't wait** for completion
  4. `askfirst`: Ask yes or no

  * The rest are invoked by user during run-time
    * `respawn`: run apps after system sleep
    * `ctrlaltdel`: do a certain action
    * `shutdown`: close application

