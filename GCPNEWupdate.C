#include<stdio.h>
#include<conio.h>
int m,n;
int found= 0;
 int G[10][10];
	 int x[10];

void NextValue(int k)
{
	int j;
	while(1)
	{

		x[k] = (x[k]+1)%(m+1);
		if(x[k]==0)
	       break;	   
		for(j=1; j<=n; j++)
		{
		if( (G[k][j] != 0) && (x[k] == x[j]) )
			break;
		}
		if(j == n+1)
		       break;
	}

}
void mColoring(int k)
{       int i;

	while(1)
	{
		NextValue(k);
		if(x[k] == 0)
	      break; 
		if(k == n)
		{
			for(i=1; i<=k;i++)
			printf("%d\t",x[i]);
			printf("\n");
			found=1;

			break;
		}
		else
		{
			mColoring(k+1);
		}
	}
}
int main()
{
	 int i,j;
	
		printf("\nGRAPH COLORING");

		printf("\nEnter the number of the vertices: ");
		scanf("%d",&n);
		printf("\nIf edge between the following vertices enter 1 else 0:\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if((i!=j)&&(i<j))
				{       printf("\n%d----%d",i,j);
					 scanf("%d",&G[i][j]);
				G[j][i]=G[i][j];
				}
				if(i==j)
					G[i][j]=0;
			}
		}
		printf("\nEnter the number of colors available: ");
		scanf("%d",&m);
		printf("\nSolution:\n");
		mColoring(1);
		if (found == 0)
		printf("\nNo Solution possible!");
getch();
}
