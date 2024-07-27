# Loading kernel

Kernel needs to files: zimage and fdt files

```bash
printenv kernel_addr_r  # address to store kernel
```

`fatload`: load file from fat to ram
`md`: memory display

Variables:

`$kernel_addr_r`: the address of the kernel
`$fat_addr_r`:

---

## Load kernel from server

We will load from the application `TFTP` `:69` (trivial file transport protocol)

* We will use it because it is used in u-boot.

* setting the ip address and server address

![alt text](assets/setenv.png)

* Loading kernel from `TFTP`

![alt text](<assets/kernel and fdt in ram after seldev.png>)

---

## Loading kernel from MMC

* Check the mmc partitions

![alt text](<assets/mmc part.png>)

* Loading kernel from MMC

![alt text](<assets/fatload zimage.png>)

---

## Check to boot from sd card or server

* Set variables to Load the **dtb** and **kernel** either from `mmc` or from `TFTP`

![alt text](<assets/setenv load.png>)

* Write a boot file script to check for the kernel and dtb in the mmc or the tftp if existed.

```shell
if mmc dev; then
        echo mmc exist;
        run load_DTB_from_MMC;
        run load_Kernel_from_MMC;
elif ping ${serverip}; then
        echo tftp exist;
        run load_DTB_from_TFTP;
        run load_Kernel_from_TFTP;
else echo No option found;
fi      
```

* Then fatload the file and source it inside the `bootcmd` environment variable.

* The output:

![alt text](<assets/Screenshot from 2024-07-27 00-54-59.png>)

* Kernel and dtb file in RAM after running the script

![alt text](<assets/kernel and fdt in ram after seldev.png>)

---

## Load kernel using the `bootflow scan` command

* The `bootflow scan` command perform automatic searching for the `EFI` partition (which is **Primary** and **Bootable**) to find the the kernel in the sd card using a config file called `extlinux.conf` inside the directory `extlinux/`

![alt text](<assets/setenv bootcmd to equal bootflow scan.png>)

* **Bootflow Scan** run

![alt text](<assets/bootflow scan run.png>)

* The linux kernel panic --> because there is no root file system `rootfs` yet:

![alt text](<assets/linux kernel panic.png>)