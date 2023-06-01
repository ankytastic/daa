#include<stdio.h>
#include<conio.h>
void Knapsack(int no,float wt[50],float pft[50],float max)
{
int i,j;
float total=0,tpft;
	for(i=0;i<no;i++)
	{
		if((total+wt[i])<=max)
		{
		total=total+wt[i];
		tpft=tpft+pft[i];
		}

		else
		for(j=i+1;j<no;j++)
		{
			if((total+wt[j])<=max)
			{
			total=total+wt[j];
			tpft=tpft+pft[j];
			}
	       }
	}

	printf("\nTotal Weight %f",total);
	printf("\nTotal Profit %f",tpft);


}

int main()
{
	int n,i,j;
	float temp, p[50],w[50],m;
	//clrscr();
	printf("\nEnter the number of Items:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("Enter Weight of Items");
	scanf("%f",&w[i]);
	printf("Enter the value of Items");
	scanf("%f",&p[i]);
	}

	printf("\nEnter Capacity:");
	scanf("%f",&m);
	for(i=0;i<n;i++)
	{
	    for(j=i;j<n;j++)
	    {
	    if(p[i]<p[j])
		{
		temp=p[j];
		p[j]=p[i];
		p[i]=temp;
	     //***********//
		temp=w[j];
		w[j]=w[i];
		w[i]=temp;
		}

	  }
	}
      Knapsack(n,w,p,m);
      getch();
}
