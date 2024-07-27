# Busybox

* Busybox is used to populate the root file system `rootfs` with needed binaries and shell commands.

* Lets start from the beginning...

## Kernel Panic

* When attempting to run a kernel without a rootfs, it will panic!

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

## Install Busybox

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

* We then need to set the `PATH` variable in order to use applications like `ls`.

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

### The Busybox executable

* Has a switch case on the softlink that is created pointing to the Busybox.
* That includes init, sh, busybox softlinks.
* Put the files under ./_install to the rootfs of the sdimage under respected files (bin, sbin, usr/bin, usr/sbin)
* create inittab under /etc

```shell
::sysinit:/etc/init.d/rcs #rcs has the mounts of /dev, /sys/ proc
::askfirst:/bin/sh
```

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

1. Execution process is **faster** (In the expense of RAM memory)
2. **Dual Bbooting** by giving the ability to switch between two banks (two ext4 rootfs) using `chroot`
3. **Security and Validation** (it check sums the ext4 partition)
4. **Recovery** (if the rootfs has failed)

### How to boot the initramfs

* After creating the **rootfs**, copy it to the `ext4` partition.

```shell
cp -r ./busybox/_install/ /media/ahmed-essam/rootfs
```

* Configure the inittab file in `/etc/inittab` and `/etc/init.d/rcs` as mentioned above.

* Create the initramfs (by creating a **ramdisk** from a compressed rootfs using **cpio**)

```shell
cd ~/sdcard/rootfs
find . | cpio -H newc -ov --owner root:root > ../initramfs.cpio
cd ..
gzip initramfs.cpio
mkimage -A arm -O linux -T ramdisk -d initramfs.cpio.gz uRamdisk
```

#### In U-Boot

* Now we give `bootargs`:
  * `initrd=/bin/sh`      # this will go to the the shell in ram
    * or you can put a script that does checksum and check banks

  * `init=/sbin/init`     # this will go to the init in rootfs
  * You can use `INIRD` in `extlinux.conf`

```shell
setenv bootargs console=ttyAMA0,115200 root=/dev/mmcblk0p2 rootfstype=ext4 rw rootwait rdinit=/bin/sh init=/sbin/init
```

* Load the kernel **zImage**, the **dtb** file, and the resulting **uRamdisk** into **RAM**.

>* **Note:** Run `bdinfo` to know memory **Start** and **End** addressesTry
>
>![bdinfo](<assets/Screenshot from 2024-07-27 00-31-08.png>)
>
>* Then try loading the kernel and the dtb file first to know how much they've occupied from >memory to `setenv` an appropriate value to the `initramfs_addr_r` environment variable.
>
>![memory](<assets/Screenshot from 2024-07-27 00-33-19.png>)

* You can now put those commands in a file then source it from inside the u-boot, or directly set the environemnt variable `bootcmd` with them.

```shell
fatload mmc 0:1 $kernel_addr_r zImage
fatload mmc 0:1 $fdt_addr_r vexpress-v2p-ca9.dtb
fatload mmc 0:1 $initramfs_addr_r uRamdisk

#boot from initrd:
bootz $kernel_addr_r $initramfs_addr_r $fdt_addr_r
```

* Then within initrd

```shell
mount /dev/mmcblk0p2 /media
chroot /media
```

* This will initiate at `initrd`

---

#### **Note:**

* if we do:

```shell
bootz $kernel - $dtb
```

* This will initiate at `init`

* Create `/etc/passwd`, `/etc/shadow`, `/etc/group`

---

## Result

* After running **Quemu** using the command:

```shell
sudo qemu-system-arm -M vexpress-a9 -m 128M -nographic -kernel u-boot -sd ~/sd1.img
```

![result](<assets/Screenshot from 2024-07-27 00-37-55.png>)

---

## Making the initrd choose between two root file systems

* Boot from initrd with an application in c to choose between two ext4 rootfs.
* Depending on the input (1 or 2), run...

```shell
mount /dev/mmcblk0p[2 or 3] /media
chroot /media
```

Or

* just write the script with shell in `init.d/rcs`
  * Here, we put `initrd=/sbin/init`

---

## NFS (Network File System)

* To put the `rootfs` on the **Server** and the **Client** calls the commands from the rootfs and runs it using its **RAM**.
