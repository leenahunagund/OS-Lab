#include <stdio.h>
struct process {
int id, at, bt, btmp, ct, tt, wt, flg;
} P[10], temp;
void main() {
int n, i, j, qnt;
float total_tt = 0, total_wt = 0;
printf("Enter the number of Process: ");
scanf("%d", &n);
for (i = 0; i < n; i++) {
P[i].id = i + 1;
printf("Enter AT for process %d :", i + 1);
scanf("%d", &P[i].at);
printf("Enter BT for process %d :", i + 1);
scanf("%d", &P[i].bt);
P[i].btmp = P[i].bt;
P[i].flg = 0;
}
printf("Enter qnt : ");
scanf("%d", &qnt);
for (i = 0; i < n - 1; i++)
for (j = 0; j < n - i - 1; j++)
if (P[j].at > P[j + 1].at) {
temp = P[j];
P[j] = P[j + 1];
P[j + 1] = temp;
}
printf("\nGantt Chart:\n");
int comp = 0, cnd, ct = P[0].at, que[100], f = 0, r = 0, cnt = 0;
cnt++;
que[r] = 0;
P[0].flg = 1;
while (comp != n) {
cnd = que[f];
f = (f + 1) % n;
if (P[cnd].bt > qnt) {
P[cnd].bt -= qnt;
ct += qnt;
printf("|P%d(%d) %d", P[cnd].id, qnt, ct);
} else {
ct += P[cnd].bt;
printf("|P%d(%d) %d", P[cnd].id, P[cnd].bt, ct);
P[cnd].bt = 0;
}
P[cnd].ct = ct;
cnt--;
for (int i = 0; i < n && P[i].at <= ct; i++) {
if (P[i].flg == 1 || P[i].bt == 0 || i == cnd)
continue;
r = (r + 1) % n;
P[i].flg = 1;
que[r] = i;
cnt++;
}
if (P[cnd].bt > 0) {
r = (r + 1) % n;
que[r] = cnd;
cnt++;
} else {
comp++;
}
}
for (i = 0; i < n; i++) {
P[i].tt = P[i].ct - P[i].at;
P[i].wt = P[i].tt - P[i].btmp;
total_tt += P[i].tt;
total_wt += P[i].wt;
}
printf("\nID\tAT\tBT\tCT\tWT\tTT\n");
for (i = 0; i < n; i++)
printf("%d\t%d\t%d\t%d\t%d\t%d\n", P[i].id, P[i].at, P[i].btmp, P[i].ct,P[i].wt, P[i].tt);
printf("AVG tt : %.3f\n", total_tt / n);
printf("AVG wt : %.3f\n", total_wt / n);
}
