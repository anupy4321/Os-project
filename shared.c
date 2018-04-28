#include<stdio.h>
#include<stdlib.h> 
#include<conio.h>
//using namespace std ;
struct Process
{
int pid,at,bt;
};
void swap1(double *xp,double *yp)
{
double temp = *xp;
*xp = *yp;
*yp = temp;
}
void swap(int *xp, int *yp)
{
int temp = *xp; *xp = *yp;
*yp = temp;
}
void selectionSort(double arr[],int arr1[] ,int n)
{ 
int i, j;
int min_idx;
for (i = 0; i < n-1; i++)  // the complexity of the loop is n
{
min_idx = i;
for (j = i+1; j < n; j++)  //the complexity of the log n^2 if (arr[j] < arr[min_idx])
min_idx = j;
swap1(&arr[min_idx], &arr[i]); 
swap(&arr1[min_idx], &arr1[i]);
}
}
void sort1(struct Process *t,int p)
{
int i,j;
struct Process *q,s;
for(i=0;i<p;i++,t++) //the complexity of the loop is p
{
for(j=i+1,q=t+1;j<p;j++,q++) //the complexity of the loop is p^2
{
if((t->at)>(q->at))
{
s=*t;
*t=*q;
*q=s;
}
}
}
}
int main()
{ 
  int i, n;
int ct[10];
struct Process p[80]; int at,bt;
printf("Enter number of processes\n"); scanf("%d",&n);
int tat[n],wt[n];
for (i=0;i<n;i++) //the complexity of the loop is n
{
printf("for process %d\n",i+1);
printf("\nenter the process id\n "); 
scanf("%d",&p[i].pid); 
printf("\nenter the arrival time\n"); 
scanf("%d",&p[i].at); 
printf("\nenter the burst time \n"); 
scanf("%d",&p[i].bt);
}
int v=n-1;
sort1(p,n);
int a[n],b[n]; int c[n]; int r;
printf("ProcessId\tArrival time\tBurst time\t");
for(i=0;i<n;i++) //the complexity of the loop is n
{
printf("\n%d\t\t%d\t\t%d\n",p[i].pid,p[i].at,p[i].bt); a[i]=p[i].pid;
}
for( i=0;i<n-1;i++) //the complexity of the loop is n
{
b[i]=a[i+1];
}
printf("\n\nGANT CHART\t");
int m=n-1;
int t=0;
if(0==p[0].at)
{
printf("0");
}
else{
printf("0 %d",p[0].at);
t=t+p[0].at;
}
t=t+p[0].bt;
//cout<<" P"<<p[0].pid<<" "<<t;
printf(" P%d %d",p[0].pid,t);
ct[1]=t;
do{
int e=0,j,u;
for(j=0;j<m;j++){ //the complexity of the loop is m for(int u=0;u<n;u++){ //the complexity of the loop is nm
if(b[j]==p[u].pid){
if(p[u].at<=t){
c[e++]=p[u].pid;
}}}


int l=e+1;
double q[l];
int z=4,k,o;
for(k=0;k<l-1;k++)
{                        //the complexity of the loop is l
for( o=0;o<n;o++)
{             //the complexity of the loop is ln if(c[k]==p[o].pid){
q[k]=1+(double)(t-p[o].at)/p[o].bt;
}
}

selectionSort(q,c,l-1);
int f=c[0];
for( i=0;i<n;i++) //the complexity of the loop is n
{ if(e!=0){
if(p[i].pid==f){
t=t+p[i].bt;
} } }
int w=5;
if(e==0 && v>0){
for( i=0;i<n;i++) //the complexity of the loop is n
{
if(t<p[i].at )
{
t=p[i].at+p[i].bt;
printf(" %d P%d %d",p[i].at,p[i].pid,t);
break;
w=9;}}}
else
{
printf(" P%d %d",f,t);
ct[f]=t;
v--;
}
for(i=0; i<m; i++) //the complexity of the loop is m^2
{
if(b[i]==f)
{
for(j=i; j<(m-1); j++)
{
b[j]=b[j+1];
}
break;
}
}
m=m-1;
}
while(m>0);
float s1=0,s2=0;
for (i=0;i<n;i++)
{
//tat[i]=ct[i+1]-p[i].at;
tat[i]=p[i].at-ct[i+1];
}
for (i=0;i<n;i++)
{
//wt[i]=tat[i]-p[i].bt;
wt[i]=p[i].bt-tat[i];
}
for(i=0;i<n;i++)
{
s1=s1+tat[i];
s2=s2+wt[i];
}
printf("\n\n\nProcessId\tArrival time\tBurst time\tTurnAround Time\tWating Time");
for(i=0;i<n;i++)
{
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].at,p[i].bt,tat[i],wt[i]);
}
float avgwt,avgtat;
avgtat=s1/n;
avgwt=s2/n;
printf("\n\n");
printf("Average TurnAround Time=%f",avgtat);
printf("\nAverage Waiting Time=%f",avgwt);
}
