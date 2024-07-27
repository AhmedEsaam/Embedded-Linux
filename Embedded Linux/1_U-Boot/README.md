# Bootloader

The bootloader is used to:

1. Flash new software.
2. Booting (Jumb to the application).

## Unified Bootloader (`u-boot`)

We use `u-boot` beacuse it:

1. Supports many boards (unified)
2. You can boot from a storage device or TFTP.
3. Has CLI (with his own commands)
4. Small in size (small footprint ~2MB)
5. Used in industry

* The U-Boot is a **unified** boatloader for the most boards, which means that you don't have to learn a new boatloader for every board.

How it access the H/W?

* It has a small linux kernel which it uses to make system calls

Install `u-boot`

* Clone the u-boot repo.

```bash
git clone https://github.com/u-boot/u-boot.git

cd u-boot

make menuconfig
```

### How to Configure the `u-boot`

#### 1. Board Configuration

```bash
cd configs
ls | grep vexpress
make vexpress_ca9x4_defconfig
```

#### 2. Compiler (as it will run on the CPU)

```bash
export export CROSS_COMPILE=arm-cortexa9_neon-linux-musleabihf- 
sudo apt-get install libssl-dev 
sudo apt-get install uuid-dev
make

qemu-system-arm -M ? | grep vexpress
qemu-system-arm -M vexpress-a9 -nographic -kernel u-boot    # run u-boot
```

* To terminate the process use: `Ctrl+A x`

#### 3. Commands

You acn't touch files in the u-boot Bootloader, so we use variables to store scripts

```bash
bdinfo          # Board info
mmc dev         # check sd card

# Variables
echo            # print variables (variables can be used to store scripts)
printenv        # print variables
run variable    # run variable command

setenv myname "echo Hi; echo Ahmed; echo fady"          # set new variable
run myname

# if conditions
setenv var 1
setenv xar 2
setenv myvar "if mmc dev; then echo sdcard exist; elif test ${var} = ${xar}; then echo equal; else echo No; fi"
run myvar

# for loop
setenv myvar 1 2 3 4 
for i in myvar; do
echo i; done;
```

The u-boot runs `Autoboot` which is a counter, after that, it runs a variable called **bootcmd** which in turn, runs another variables.

```bash
echo ${bootcmd}
```

* If running u-boot yielded an error, The error is in the running of the var `bootvmd`. You can check that by overwriting this var and try to build the u-boot again and run it.

#### 4. Network configuration (if you need to use FOTA)

   > This needs an application in the `u-boot` to communicate with the network server.

### Adding `sd-card`

```bash
qemu-system-arm -M vexpress-a9 -nographic -kernel u-boot -sd ~/sd.img
mmc dev
echo $bootdelay
setenv bootdelay 5
saveenv
```

```bash
make menuconfig
```

* **Note:** To quickly mount the sd.img passed to the U-Boot to your linux, you can type

### `uboot.env`

An environment variable that the u-boot stores the needed variables in which it needs while run-time.
