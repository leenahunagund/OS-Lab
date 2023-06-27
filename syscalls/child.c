//create child
#include<stdio.h>
#include<unistd.h>
int main(){
printf("before fork\n");
fork();
printf("after first fork\n");
fork();
printf("after second fork\n");
fork();
printf("after third fork\n");
return 0;
}
