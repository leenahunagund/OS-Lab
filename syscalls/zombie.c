//zombie process
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	pid_t child_pid,my_pid,parent_pid;
	child_pid=fork();
	if(child_pid<0)
	{
	printf("fork failed .exiting 1\n");
	exit(0);
	}
	if (child_pid==0)
	{
	//child process
	printf("[CHILD] This is the child process\n");
	my_pid=getpid();
	parent_pid=getppid();
	printf("[CHILD] my pid is %d\n",my_pid);
	printf("[CHILD] my parent's pid is %d\n",parent_pid);
	printf("[CHILD] exiting");
	exit(0);
	}
	else
	{
	//parent process
	printf("[PARENT] This is the parent process\n");
	my_pid=getpid();
	parent_pid=getppid();
	printf("[PARENT] my pid is %d\n",my_pid);
	printf("[PARENT] my parent's pid is %d\n",parent_pid);
	printf("[PARENT] sleeping for 10 seconds\n");
	sleep(10);
	printf("[PARENT]child pid= %d has ended , but it has an entry in the process table . it is a zombie process\n",child_pid);
	}
	return 0;
}


	

	


