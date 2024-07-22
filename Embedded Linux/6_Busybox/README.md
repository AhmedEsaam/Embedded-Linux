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

### Errors while compiling Busybox

* TC

> search for `CONFIG_TC` in `.config` file and make it `=n`

* Nothing in kernel

> `init` that is created is not executable --> make it executable: `chmod +x init`

### The Busyboc=x executable

* Has a switch case on the softlink that is created pointing to the Busybox.
* That includes init, sh, busybox softlinks.
* Put the files under ./_install to the rootfs of the sdimage under respected files (bin, sbin, usr/bin, usr/sbin)
* create inittab under /etc

    > ::sysinit:/etc/init.d/rcs #rcs has the mounts of /dev, /sys/ proc

    > ::askfirst:/bin/sh

* Then mkdir all dirs under `/`
  * Or, use:

  ```shell
  rsync -a ~/busybox/_install /media/rootfs
  rsync -a ~/x-tools/arm/..../sysroot /media/rootfs
  ```

* Then put `init=init` in `bootargs`, or use `APPEND init=init` in the extlinux.conf file (with the bootargs has he higher priority).

---

## `initramfs` and `initrd`

* We creates a packup of **essential** commands in (/bin, /sbin, /usr) and store it compressed in RAM in case of a failure of the rootfs.

* First, you must compile _install **static**.
* Running `initrd` (init ram disk) will create initrd.cpio.xz
* Put it under boot
* Now we have under `boot`: (this boot partition are usually locked)
* > initrd.cpio.xz
* > u-boot
* > .dtb
* > zImage
* > extlinux/extlinux.conf
* > u-boot.env

### Its Pros

1. Execution process is faster
2. Gives the ability to switch between two banks (two ext4 rootfs) using `chroot`
3. Security (it check sums the ext4 partition)
4. Recovery (if the rootfs has failed)

* First: `fatload mmc 0:1 ${initramfs} cpio.xz` putting the cpio.xz in **RAM**.

* Now we give `bootargs`:
  * `initrd=/bin/sh`      # this will go to the the shell in ram
    * or you can put a script that does checksum and check banks

  * `init=/sbin/init`     # this will go to the init in rootfs
  * You can use `INIRD` in `extlinux.conf`

* boot from initrd:

```shell
bootz $kernel $initramfs $dtb
```

* Then within initrd

```shell
mount /dev/mmcblk0p2 /media
chroot /media
```

* This will initiate at `initrd`

* if we do:

```shell
bootz $kernel - $dtb
```

* This will initiate at `init`

* Create `/etc/passwd`, `/etc/shadow`, `/etc/group`

---

## Task

* Boot from initrd with an application in c to choose between two ext4 rootfs.
* Depending on the input (1 or 2), run...

```shell
mount /dev/mmcblk0p[2 or 3] /media
chroot /media
```

Or

* just write the script with shell in `initrd/rcs`
  * Here, we put `initrd=/sbin/init`

---

## NFS (Network File System)

* To put the `rootfs` on the **Server** and the **Client** calls the commands from the rootfs and runs it using its **RAM**.
