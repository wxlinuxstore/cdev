#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/uaccess.h>

struct cdev demo_cdev;
dev_t demo_no;
static struct class *demo_class = NULL;
static struct device *demo_device = NULL;

static int demo_open(struct inode *inode, struct file *filp)
{
    return 0;
}

static ssize_t demo_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_ops)
{
    return 0;
}

static ssize_t demo_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
    return 0;
}

static int demo_release(struct inode *inode, struct file *filp)
{
    return 0;
}

static const struct file_operations demo_fops = {
    .open = demo_open,
    .write = demo_write,
    .read = demo_read,
    .release = demo_release,
};

static int __init demo_init(void)
{
    cdev_init(&demo_cdev, &demo_fops);
    alloc_chrdev_region(&demo_no, 0, 1, "demo");
    cdev_add(&demo_cdev, demo_no, 1);

    demo_class = class_create(THIS_MODULE, "demo");
    demo_device = device_create(demo_class, NULL, demo_no, NULL, "devdemo");

    return 0;
}

static void __exit demo_exit(void)
{
    device_destroy(demo_class, demo_no);
    class_unregister(demo_class);
    class_destroy(demo_class);

    cdev_del(&demo_cdev);
    unregister_chrdev_region(demo_no, 1);
}

module_init(demo_init);
module_exit(demo_exit);

MODULE_LICENSE("GPL");
