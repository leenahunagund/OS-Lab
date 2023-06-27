//to demonstrate exit, getpid, getppid, wait,sleep, execlp
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

void main()
{
	pid_t child_pid,my_pid,parent_pid,wid;
	int i=10;
	child_pid=fork();
	if(child_pid<0)
	{
	printf("fork fialed , exiting!\n");
	exit(0);
	}
	else if(child_pid==0)
	{
	//child process
	//printf(("[CHILD] before using exit syscall\n");
	//exit(0);
	printf("[CHILD] this is the child process\n");
	my_pid=getpid();
	parent_pid=getppid();
	printf("[CHILD] my pid is %d\n ", my_pid);
	printf("[CHILD] my parent pid is %d\n ", parent_pid);
	printf("[CHILD] i = %d\n ", --i);
	printf("[CHILD] child process going to load another program using execlp syscall\n"); 
	execlp("/bin/pwd", "pwd", NULL);
	}
	else
	{
	//parent process
	printf("[PARENT] This is the parent process\n");
	my_pid=getpid();
	printf("[PARENT] waiting for the child to terminate\n");
	wid=wait(NULL);
	printf("[PARENT] My parents pid is %d\n",parent_pid);
	printf("[PARENT] My child's pid is %d\n",child_pid);
	printf("[PARENT] i = %d\n",++i);
	}
	
}




	
	
	
