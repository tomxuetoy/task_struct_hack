#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/sched.h>	//task_struct

MODULE_LICENSE("GPL");

static int hello_init(void) {
    printk(KERN_ALERT "Hello, Tom Xue! From inside kernel driver!\n");
    printk(KERN_ALERT "The size of task_struct is %d\n", sizeof(struct task_struct));
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_INFO "Goodbye, Tom Xue! From inside kernel driver!\n");
}

module_init(hello_init);
module_exit(hello_exit);
