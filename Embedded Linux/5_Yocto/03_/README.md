# 03 -

```shell
bitbake core-image-minimal -c listtasks
```

## Collection of tasks

* do_compile
* do_fetch
* do_install
* do_listtasks

### To tasksto generate SDK

* do_populate_sdk
* do_populate_sdk_ext

### Compile recipes

* debug symbols (-g)
* set environment

### How to compile in the x86 an arm application

* you only need to create an environment to compile to arm (install SDK)
* and generate the execuatbel (a.out) compiled using the cross tool chain.
* pass the executable to the running rpi image.
  1. Using `scp`
  2. Or `devtool`

### What is `devtool`

* It's a tool that writes recipes automatically.
* and deploy them.

```shell
source eo_init
devtool --help

devtool add [the upstream: github link] [recipe_name]
# will create a workspace folder in the Build directory
# a layer will be created and added to the bb layer

devtool deploy [recipe_name]
# will compile and send to rpi using scp (user, ip, [no need for destination as you already gave it the recipe_name])
```

* **NOTE:** Make sure to check the generated recipe as the automated recipe might have errors.

* There are SDK for every application (Qt, Java, ...).
* Create a directory to act as the target for this sdk
* Source the script file that contains the system vars like (CC, LDFLAGs, etc)


---

* Watch **Life COding with yocto**.