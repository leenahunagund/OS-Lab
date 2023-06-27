
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *threadfun(); 
int i,j,n; 

void main()
{
	pthread_t T1;
	pthread_create(&T1,NULL,threadfun,NULL); 
	printf("inside main thread\n");
	for(i=0;i<=15;i++)
	{
		printf("i=%d\n",i);
		sleep(1);
	}
	

}
void *threadfun()
{
	printf("inside thread\n");
	for(j=1;j<=5;j++)
	{
		printf("j=%d\n",j);
		sleep(1);
	}
	
}

	
	
