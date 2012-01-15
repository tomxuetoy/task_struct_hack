#define __KERNEL__
#include <linux/sched.h>
#include <stdio.h>

struct task_struct;

main()
{
	printf("sizeof(struct task_struct) - %d\n", sizeof(struct task_struct));
}
