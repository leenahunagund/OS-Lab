#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#define B 30

int main()
{
	int fd,n;
	char buf[B];
	fd=open("m6.c",O_RDWR);
	if(fd==1)
	{
		printf("Failed to open the file\n");
		exit(0);
	}

	printf("\nReading first 10 characters from file\n");
	n=read(fd,buf,10);
	write(1,buf,n);

	printf("\nSkipping 5 char from current position in the file\n");
	lseek(fd,5,SEEK_CUR);
	n=read(fd,buf,10);
	write(1,buf,n);

	printf("\nGoing 10 char before current position in the file\n");
	lseek(fd,-10,SEEK_CUR);
	n=read(fd,buf,10);
	write(1,buf,n);

	printf("\nGoing to 5th best char in the file\n");
	lseek(fd,-5,SEEK_END);
	n=read(fd,buf,7);
	write(1,buf,5);

	printf("\nGoing to the 3rd char in the file\n");
	lseek(fd,3,SEEK_SET);
	n=read(fd,buf,5);
	write(1,buf,n);

	return 0;
}








