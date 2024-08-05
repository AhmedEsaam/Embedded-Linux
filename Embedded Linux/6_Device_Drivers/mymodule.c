/*** Header Section ***/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/proc_fs.h>

static int __init lkm_init(void)
{
    printk("Hello from init\n");

    return 0;
}

static void __exit lkm_exit(void)
{
    printk("Hello from init\n");
}

module_init(lkm_init);
module_exit(lkm_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ahmed Essam");
MODULE_DESCRIPTION("A simple character device driver for reading and writing to a file");