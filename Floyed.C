#include<conio.h>
#include<stdio.h>
void floyd(int cost[10][10],int n)
{
int i,k,j,t,x[10][10];
for(i=0;i<n;i++)
for(j=0;j<n;j++)
x[i][j]=cost[i][j];
for(k=0;k<n;k++)
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
if((x[i][k]==1000)|| (x[k][j]==1000))
t=1000;
else
t=x[i][k]+x[k][j];
x[i][j]=(x[i][j]>t)?t:x[i][j];
}
printf("the dist is:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%d ",x[i][j]);
}
printf("\n");
}
}
int main()
{
int i,j,n,a[10][10]; //clrscr();
printf("enter the no of vertices");
scanf("%d",&n);
printf("enter the cost matrix");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}
floyd(a,n);

getch();
return 0;
}



