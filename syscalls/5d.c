#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#define  B 300

int main()
{
	char buf[B];
	int fd1,fd2,n;

	fd1=open("m6.c",O_RDONLY);
	fd2=open("copy",O_CREAT|O_WRONLY,0666);
	printf("File descriptor for m6.c is %d and copied file is %d\n\n",fd1,fd2);

	if(fd1==-1||fd2==-1)
    	{ 
		printf("Failed to open file\n");
      		exit(0);
    	}
 	n=read(fd1,buf,B);
	printf("characters %d\n",n);
	write(fd2,buf,n);
	printf("file has been created and contents are copied successfully\n");
	return 0;
}
	
