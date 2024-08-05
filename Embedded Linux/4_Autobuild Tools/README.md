# Autobuild Tools

* To build your image to occupy smaller size, you need to build your image from scratch.

* We can use an automated building process through **Build Root**.

* When you build an application needed in the user space:

.

* Types of bootloaders: `U-boot`, `grub`, `barebox`.

## Yocto Project VS. Buildroot

| Yocto Project | Buildroot |
| :---: | :---: |
| features | smaller timing |
| integration of new applications | difficult to integrate new apps |
|| smaller workspace |
|| smaller footprint |

## In Buildroot

* open **make menuconfig**

```shell
cd buildroot
make menuconfig
```

* Set these configurations

* **Toolchain** : chase lib

* **System Configuration**:
  * type of init process
  * type of shell
  * enable root passwd
* **Kernel** : version of kernel
* **Target Packages in User Space**:
  * dropbear (a light version of Open SSH)
  * games > chocolates
* **Filesystem Image**: type and size of rootfs
* **Bootloader**: grub

---

## Task

* Create a multi-thread app **Demo_app**.
* It is required to appear in **Make menuconfig** **Target Package**
* The **Make menuconfig** reads a file called **kconfig**.
* Which in turn reads **config.in**
* create Demo_app in
* ./package/Demo_app/
  * `config.in`
  * `makefile`
  * .mk file contains **description**
