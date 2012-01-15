#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/sched.h>	//task_struct
#include <linux/list.h>		//list_head

MODULE_LICENSE("GPL");

static int hello_init(void) {
    struct task_struct *my_parent = current->parent;
	struct task_struct *task;
	struct list_head *list;

    printk(KERN_ALERT "Hello, Tom Xue! From inside kernel driver!\n");
    printk(KERN_ALERT "The size of task_struct is %d\n", sizeof(struct task_struct));
    
	printk(KERN_ALERT "My parent task name is %s\n", my_parent->comm);

	list_for_each(list, &current->parent->sibling){
		task = list_entry(list, struct task_struct, sibling);
		printk(KERN_ALERT "The uncle process's name: %s", task->comm);
	}

	for(task = current; task != &init_task; task = task->parent)
		printk(KERN_ALERT "The series of task name: %s\n", task->comm);

	//for(task = next_task(&init_task); task != &init_task; task = next_task(task))
	for_each_process(task)
		printk(KERN_ALERT "List all the task name: %s\t\t%d", task->comm, task->pid);

    return 0;
}

static void hello_exit(void)
{
    printk(KERN_INFO "Goodbye, Tom Xue! From inside kernel driver!\n");
}

module_init(hello_init);
module_exit(hello_exit);
