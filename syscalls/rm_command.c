//rm command simulation

#include<stdio.h>

void main()

{

char fn[10];

printf("enter source filename\n");

scanf("%s",fn);

if( remove(fn)==0)

printf("file removed\n");

else

printf("file cannot be removed\n");

}
