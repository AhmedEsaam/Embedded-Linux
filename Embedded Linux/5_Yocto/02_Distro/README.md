# Distro

* Bitbake perform these tasks to install a recipe
    1. fetch
    2. unpack
    3. patch
    4. configuration
    5. build
    6. install

```shell
    INAGE_INSTALL:append recipe
```

## Patch

* Is a file contains the changes that can be applied on acode file.

```shell
git diff main.c > mypatch.patch
git apply mypatch.patch
```

### In Yoctu

```shell
SRC_URI = "file://main.c \
            file://mypatch.patch \"
```

---

## Task

* Make layer : to run `myImage.pp`, Distro
* Edit `local.conf`

* `core_image_minimal` generate a **terminal**.

* `core_image_sato` generates a **GUI**.

* Write a `Qt` app on a version `Qt5`.
* Install it on your host machine.
* Write a recipe to execute this app.

* We need
    1. Sato (server)
    2. meta_Qt5 (checkout on Kirkstone)
       1. qtbase
    3. recipe (has your application (inherit `qtmake5_base`))
    4. Include your recipe in `IMAGE_INSTALL`
    5. **Upgrade** your Qt : add a button (press to led on, and off).
    6. Put `INHERIT = "rm_work"` in `local.conf` to remove work directory with all the downloads to free space.
