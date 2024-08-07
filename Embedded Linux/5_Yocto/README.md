# Open Embedded

## Open Embedded Community

* Created a tool in python (to be portable) to automate configuring and building images called **bitbake**.
* Give the **bitbake** metadata which conains required **configurations**.
* They create layers contains applications:
  * **meta-core**: layer that has python.
  * **meta-resbperry Bi**: layer that has u-boot, ... for RPI.

* A layer starts with `meta-`

* There are two types of layers:
  * Appliation layers
  * Board Suport Package **(BSP)**
  * A layer supports the two.

```shell
mkdir ImageGenerateDir
cd ImageGenerateDir
git clone bitbake       # the python tool
git clone meta-core     # the layer which has python
git clone meta-rasb     # the layer which has RPI board support package
```

* :warning: But they lacked good **documentation**

* :Warning: And **Compatibility**
  * Which emerges when the cloned version of **bitbake** does not recognize the version of the cloned **layer**.

* So, the **Yocto Project** came up.

## The Yocto Project

### Provided References

* The came up with the **Reference** to How to create an image using the **Open Embedded** with the `bitbake` tool.

* They created a repo called **`Poky`** that contains:
  * **`bitbake`**
  * **Layers from Open Embedded**:
    * `meta`
    * `meta-core`
    * `meta-skeleton`   - A **Template** on how to create **BSP** layer.
  * **Layers They Created**
    * `meta-poky`       - contains **bitbake**.
    * `meta-yocto-bsp`

### Compatibility

* Every layer developer must create release branches for different **Poky** Versions.
  * **Zeus**
  * **Dunfill**
  * **Kirkstone**

* When you clone a layer that has been developed using a specific **Poky** version (based on a specific `bitbake` version), you need to checkout to this release branch in the cloned layer or Yocto will show an error.

* It's often required to make a certain layer compatible for a specific Poky version.

```shell
# In Yocto (Kirkstone)
git clone layer
cit checkout kirkstone      # the layer kirkstone branch
```

### The metadata concept

* `bitbake` require user **configurations**, **application**, **classes**.

* Each **Layer** is a **directory** that contains:

  * If the layer is a `meta-bsp` layer
    * `.conf` : configuration files (**BSP** and **Distro**).

  * If the layer is a `meta-application` layer
    * `.bb` : how to build the application.
    * `.bbappend` : append to bb files
    * `.class` : classes
    * `.inc` : include files.

### How Bitbake works?

* The `bitbake` will folow the layer metadata files to download different apps.

* It use different directories:
  * S : Source
  * B : Build
  * D : Destination

* The `meta-layer` directory have
  * `recipes-myApp` dir. for every application which have
    * `.bb` file which have the recipe for how to build myApp.

* So the `bitbake`...
  * First it clones into the **Downloads** directry.
  * For example it follows the `.bb` file which contains the **recipe** to install your **application**:
    * `unpack` in **S**
    * `patch` in **S**
    * `configure` in **S**
    * `build` in **B**
    * `install` in **D**          # tell which file to whch targeted place in root
    * `packagefeeder` in **D**
      * It either make the Image a **release Image** (without debugging symbols)
      * Or an **SDK Image** (Software Developer Kit - with debugging symbols).

---

## Variables

### Variable types

* Any variables created under these files are **local variables**: Only seen in its file
  * `.bb`
  * `.bbappend`
  * `.class`
  
* Any variabless created under these files are **global variables**: can be seen in any other metadat file
  * `.conf`

### Syntax

#### To Assign a variable

* Normal Assignation (=)

```sh
myVar = "string"
myVar = "name"
# bitbake result "name"
```

* Weak Assignation (?=)

```sh
myVar = "3"
myVar ?= "4"
# bitbake result 3

myvar ?= "3"              # assign to 3
myvar ?= "4"              # assignation is weak --> already assigned (in any metadata file if this var is global) so, no new assignation
# bitbake result 3
```

* Weak Weak Assignation (??=)

```sh
myVar ??= "4"             # will not get assigned (treats it as a default value)
myVar ?= "3"
# bitbake result 3

myVar ??= "4"
myVar ??= "3"
# bitbake result 3

myVar ??= "5"
myVar ?= "6"
myVar = "7"
# bitbake result 7
```

* Immediate Assignation (:=)

```sh
xar = "3"
myVar = "${xar}"          # myVar = ${xar} : it will be evaluated at the end
xar = "4"
# myVar = "4"

xar = "3"
myVar := "${xar}"         # myVar = ${xar} : it will be evaluated immediately
xar = "4"
# myVar = "3"

myVar := "${xar}"         # myVar = ${xar} : it will be evaluated at the end as no previous value for xar
xar = "3"
xar = "4"
# myVar = "4"

xar ??= "3"
myVar := "${xar}"         # myVar = ${xar} : it will be evaluated immediately
xar ??= "4"
# myVar = "3"

xar ??= "3"
myVar := "${xar}"         # myVar = ${xar} : it will be evaluated immediately
xar = "4"
# myVar = "3"
```

#### To Append

* Using `+=` and `:append`

```sh
myVar = "4"
myVar += "5"
# bitbake result "4 5"    # it will put a space in between

myVar = "4"
myVar:append = "5"        # not supperted in 'dunfill' 
# bitbake result "45"     # no space

myVar = "4"
myVar += "5"
myVar:append = "6"
# bitbake result "4 56"

myVar = "4"
myVar:append = "5"        # any alphapetical operation is a low priority (will execute last) 
myVar += "6"
# bitbake result "46 5"

myVar = "4"
myVar:append = "5"
myVar += "6"
# bitbake result "4 6 5"

myVar ??= "5"             # this will not get assigned (it's a default value)
myVar += "6"
# bitbake result "6"

myVar ?= "5"
myVar += "6"
# bitbake result "5 6"

myVar ?= "5"
myVar += "6"
myVar = "7"
# bitbake result "7"

myVar ?= "5"
myVar += "6"
myVar ?= "7"
# bitbake result "5 6"
```

* Use `:append` as it's more readable (But do not forget to put the **space** at the beginning).

* Pre-Append

```sh
myVar =+ "7"
myVar:prepend = "8"
```

* Append & Pre-Append with dots (.)

```sh
# append
myVar .= "4"

# pre-append
myVar =. "3"
```

* Append Priority
  1. `+=` and `.=`
  2. `:append`

* Example

```sh
xar = "5"
xar:append = "7"
xar =. "8"
xar =+ "9"
# bitbake result "79 85"
```

#### To Remove

```sh
myVar = "3 5 6"
myVar:remove = "5"
# bitbake result "3 6"
```

### How to read global Variables

* `bitbake` tool:

```shell
bitbake-getvar myVar      # give it your variable to get.
```

---

## Creating a Layer

* Local Variables are applied on recipes

1. Create a layer directory **outside Poky**.

   * create layer.
   * **layer.conf** file will be created and have variables
      * 

   * bitbake parses the conf files first

2. Add your layer

   * Vim on **BBlayers.conf** : include all layers that you want in your building system (Use absolute pathes).
   * Or, use the command : **`bitbake-layers add-layer [layer relative path]`**

   * If this layer depends on anoter layer, bitbake will yield an error.

   * When you add a layer, make sure that you are in the `Poky/building environemnt` path.

3. Run `bitbake` on your recipe.

   * `bitbake myrecipe`

### Build Environemnt

* One of the important scripts (to build your environment) is `oe-init-build-env` which creates your environment.
    1. It updates the `PATH` environment variable to run `bitbake` as a normal command.
    2. Creates the template of the build environment.

* You must resource it before using `bitbake`

---

## Task

1. Create an environment.
2. Create layer.
   1. Create a recipe in this layer (take a copy of the provided recipe)
   2. Edit in the function `do_display_banner()`

    > ```cpp
    > if(var == 3)
    >   display "hi"
    > else if (var == 4)
    >   display "hello"
    >```

3. Either use `bb.` or `if in python`
4. In `layer.conf` create a variable to read the variable.
5. Include this variable : `LICENCE = "closed"` to build recipe
