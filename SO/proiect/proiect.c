#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

struct process_info {
	pid_t pid;
	pid_t ppid;
	int children_count;
	pid_t *pchildren;
	uid_t user_id;
};
void print_space(int level) {
    int i;
    for (i = 0; i < level * 4; i++) {
        printf(" ");
    }
}
void print(struct process_node *p, int level) {
    print_spaces(level);
    printf("pid: %d\n", p->pid);

    print_spaces(level);
    printf("ppid: %d\n", p->ppid);

    print_spaces(level);
    printf("children: %d\n", p->children_count);

    print_spaces(level);
    printf("user_id: %d\n", (int)p->user_id);

 
    printf("\n");
}

void dfs(pid_t pid, int level) 
{
	//allocate memory for the new process
	struct process_info *proc = (struct process_info *) malloc(sizeof(struct process_info ));
	int children_count = syscall(332, pid);
	proc->children = (pid_t *) malloc(sizeof(pid_t) *children_count);
	//processing the current process;
	int check = syscall(333, pid, p);
	if (check < 0) {
        	printf("Try anothe PID! :(\n");
        	return;
    	}
	else {
		print(proc, level);
	      }
	//processing all the descendants of the current process
	int i = 0;
    	for (i = 0; i < proc->children_count; i++) {
        	dfs(p->pchildren[i], level + 1);
    	}

	//  Deallocating heap memory
    	free(proc->pchildren);
    	free(proc);

}

int main(int argc, char **argv)
{
	pid_t pid = atoi(argv[1]);//the pid about which we want info 

	struct process_info *result_process = (struct  
process_info*)malloc(sizeof(struct process_info));	//the result
	int children_count = syscall(332, pid);
	proc->children = (pid_t *) malloc(sizeof(pid_t) *children_count);


	int check = syscall(331, pid, result_process);//if the process exists
	
	if(check < 0) {
		printf("It doesn't exist process with this pid \n");
	}
	else {
		printf("Starting with parent process...\n\n");
		print(result_process, 0);
		int i, level = 0;
		for (i = 0; i < children_count; i++)
			dfs(result_process->pchildren[i], level + 1);
	
	}
	free(result_process->pchildren);
    	free(result_process);

	return 0;

}
