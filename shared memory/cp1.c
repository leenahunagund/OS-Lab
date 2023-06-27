//6a,(i) consumer product shared memory
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/mman.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	void *psm;
	int shmid;
	shmid=shm_open("OS",O_RDONLY,0666);
	ftruncate(shmid,1024);
	psm=mmap(0,1024,PROT_READ,MAP_SHARED,shmid,0);
	printf("key/ID/fd of the shared memory: %d\n " , shmid);
	printf("shared memory for consumer is attatched at :%p\n" , psm);
	printf("%s", (char*)psm);
	printf("\n");
	shm_unlink("OS"); //removes the name of the shared memeory object named by the string pointed to by name
	return 0;
}
