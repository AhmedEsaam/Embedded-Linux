/*** Header Section ***/
#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>

/*** Code Section ***/
const struct proc_ops proc_file_operations = {
    .proc_read = myRead,
    .proc_write = myWrite

};

const struct proc_dir_entry proc_file_operations = {
    .proc_read = myRead,
    .proc_write = myWrite

};

ssize_t myWrite(struct file *files, const char __user *buff, size_t size, loff_t *loff)
{
  printk("Hello from write\n");

  return 0;
}

ssize_t myRead(struct file *files, char __user *buff, size_t size, loff_t *loff)
{
  printk("Hello from read\n");

  return 0;
}

/* Init Function */
static __init int mykernel_init(void)
{
  /* print function for kernel (prints in dmesg) */
  printk("Hello from kernel\n");

  proc_create("google", 0666, NULL, proc_ops, )

      /* init function succeeded */
      return 0;
}

/* Deinit Function */
static __exit void mykernel_exit(void)
{
  proc_void proc_remove(struct proc_dir_entry *);
  /* print function for kernel (prints in dmesg) */
  printk("Removed by kernel\n");
}

/* Passing your function to function-like macros which in turn pass them to callback functions */
module_init(mykernel_init);
module_exit(mykernel_exit);

/* Module License */
MODULE_LICENSE("GPL");