//ls command simulation
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
void main(int argc , char *argv[])
{
DIR *dp;
struct dirent *dirp;
if(argc<2)
{
printf("\n you ARE not passing the directory\n");
exit(1);
}
if ((dp=opendir(argv[1]))==NULL)
{
printf("\ncannot open it doesnt exist %s file! \n",argv[1]);
exit(1);
}
while((dirp=readdir(dp))!=NULL)
printf("%s\n",dirp->d_name);
closedir(dp);
}
