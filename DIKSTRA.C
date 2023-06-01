#include<stdio.h>
#include<conio.h>
void dijsaktra(int cost[100][100],int n)
{
int c=1,s,i,dist[100],cnt=0,z,k,j,u,v;
while(c)
	{
	printf("enter the source node whose shortest path is to be determined");
	scanf("%d",&s);//get the input for source node
	//find the shortest path
	for(i=1;i<=n;i++)
	dist[i]=cost[s][i];
	for(k=2;k<n;k++)
	{
		for(u=1;u<=n;u++)
		{
		for(z=1;z<=n;z++)
		{
			if(cost[z][u]!=1000)
			cnt=cnt+1;
		}
		if(cnt!=0)
		{
			cnt=0;
			for(i=1;i<=n;i++)
			{
				if(dist[u]>(dist[i]+cost[i][u]))
				dist[u]=dist[i]+cost[i][u];
			}
		}
	}
	}
	printf("shortest path from %d",s);
	for(i=1;i!=s,i<=n;i++)
	if(i!=s)
	printf("\n%d : %d",i,dist[i]);//display th shotest path
	printf("continue? y=1 or n=0");//check if the user wishes yo continue
	scanf("%d",&c);
	}
}
int main()
{
int n,i,j,cost[100][100];
//clrscr();
printf("enter no of vertices");
scanf("%d",&n);
for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
		{
		scanf("%d",&cost[i][j]);
		}
	}
	dijsaktra(cost,n);
	getch();
	return 0;
}
