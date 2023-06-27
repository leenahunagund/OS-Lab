// 6a,(ii) consumer product shared memory
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
	void *psm;
	char buf[10];
	int shmid;
	shmid=shmget((key_t) 1122 ,1024,0666);
	printf("key of the shared memory: %d\n " , shmid);
	psm=shmat(shmid,NULL,0666);
	printf("process attatched at :%p\n" , psm);
	printf("data read from the shared memory :%s\n", (char*)psm);
	printf("\n");
	//shmctl() performs the control operation specified by cmd
	shmctl(shmid, IPC_RMID, NULL);
	//IPC_RMD marks the segment to destroyed
	return 0;
}
