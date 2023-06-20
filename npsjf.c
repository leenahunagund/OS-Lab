#include<stdio.h>
struct process
{
int ID,AT,BT,CT,TAT,WT,IsComp;
};

void main()
{
struct process P[10];
int n,i,j;
float total_tat=0,total_wt=0;
printf("enter the number of processes : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
P[i].ID=i+1;
printf("enter AT for the process %d: ",i+1);
scanf("%d",&P[i].AT);
printf("enter BT for the process %d: ",i+1);
scanf("%d",&P[i].BT);
P[i].IsComp=0;
}

printf("\ngantt chart:\n");
int MIN_IND,MIN_BT,COMP=0,CUR_TIME=0;
while(COMP!=n)
{
MIN_IND=-1;
MIN_BT=999;
for(i=0;i<n;i++)
{
if(P[i].AT<=CUR_TIME && P[i].IsComp==0)
if(P[i].BT<MIN_BT || (P[i].BT==MIN_BT && P[i].AT<P[MIN_IND].AT))
{
MIN_BT=P[i].BT;
MIN_IND=i;
}
}
if(MIN_IND==-1)
CUR_TIME++;
else
{
CUR_TIME+=P[MIN_IND].BT;
P[MIN_IND].CT=CUR_TIME;
P[MIN_IND].TAT=P[MIN_IND].CT-P[MIN_IND].AT;
P[MIN_IND].WT=P[MIN_IND].TAT-P[MIN_IND].BT;
total_tat+=P[MIN_IND].TAT;
total_wt+=P[MIN_IND].WT;
P[MIN_IND].IsComp=1;
COMP++;
printf("| P %d(%d)%d ", P[MIN_IND].ID,P[MIN_IND].BT,CUR_TIME);
}
}
printf("\n\nID\tAT\tBT\tCT\tWT\tTAT\n");
for(i=0;i<n;i++)
printf("\n\n%d\t%d\t%d\t%d\t%d\t%d\n",P[i].ID,P[i].AT,P[i].BT,P[i].CT,P[i].WT,P[i].TAT);
printf("AVG TAT : %.3f\n",total_tat/n);
printf("AVG WT : %.3f\n",total_wt/n);
}


