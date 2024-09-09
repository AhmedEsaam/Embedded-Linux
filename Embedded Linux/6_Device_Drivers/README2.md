# Device Drivers

* Is a standard way to write a driver.  using **Kernel Headers**.
  1. We use `strcut` as the data structure unit.
  2. It uses OOP paradighm using C.

* We write a device driver using:
  1. Character
     1. Use `device.h`
  2. Network
  3. Block

* We have user space and kernel space.

* To inject a character device in he kernel space
  * We write our driver as `file` which is a node added to `/dev`
  * An `ID` is created to call every device.
    * This Device number consists of:
        1. Major number: refers to the device
        2. Minor number: refers to instances of the same device

* To add the device:

```C
struct cdev mydev; // charcater device that defines the data structure  

void init() {
    dev_t device_number = 0;
    alloc_chrdev_region(device_number, base_minor, count, char* name); 
    # the device number: returned will have the ID created filled.
    # base minor: is the minor number offset to start at
    # count: the number of minors to be created
    # name: put any name
    printk("%d", Major(device_numer));
    printk("%d", Minor(device_numer));
}
```

```shell
insmode [your code] # injects your device in the kernel space
mknode -c 47 3 /dev/mydevice # node name (you can put it any where not /dev/)
# the node is a connection channel between the minor device iin the kernel space and the user space to interact with it.
```

* Allocate: just allocates some space in memory (raw memory with no data structure)
* But we don't have file operations (cat, seek, ...).

* Formulate `cdev` data structure to format the memory (giving it your file operations implementation).

* **File Operations:**
  * You'll find them under `fs.h`.

```c
file_Operations {
    write = callback function
    read
    open
    save
}

// add you file operation struct instance to cdev either using this function
cdev_init(cdev* cdev, const struct file_operations* fops) { // character device initialization
    // cdev: struct
}

// Or directly:
mycdev file_operations = &fops;
// But use the function as it initializes some other variables
```

* Add your `cdev` to the memory.

```c
cdev_add(cdev, dev + i, 0); 
// dev has the major and first minor
// 0: base minor
// loop over this statement for every minor device 
// this function also defines the dev_t variable in the 'cdev'
```

```cpp
// instead of: mknode add
class_create()
device_create()
```

---

* So, we have 
  * **dev_t**: device number (major and minor)
  * **struct file_operation**: by developer
  * **struct cdev**: row memory
  * **alloc_chrdev_region()**: alloc free memory in ram to be initialized as character device.
  * **cdev_init()**: initialize cdev data structure for the character device (including the file operations).
