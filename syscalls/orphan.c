//orphan process
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
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
	printf("[CHILD] sleeping for 10 seconds\n");
	sleep(10);
	printf("[CHILD]MY parent ended so i am an orphan process adopted by init process\n");
	}
	else
	{
	//parent process
	printf("[PARENT] This is the parent process\n");
	my_pid=getpid();
	printf("[PARENT] my pid is %d \n",my_pid);
	printf("[PARENT] my  parents pid is %d \n",parent_pid);
	printf("[PARENT] exiting\n");
	}
	return 0;
}
	
	
	
