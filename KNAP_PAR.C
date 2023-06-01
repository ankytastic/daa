#include<stdio.h>
#include<conio.h>
int Knapsackpart(float p[],float v[],float w[],int n,int c)
{
int i;
float t=0;

	for(i=0;i<n;i++)
	{
		if(t<c)
		{
		if((t+w[i])>c)
		   {
		   w[i]=c-t;
		   v[i]=w[i]*p[i];
		   t=c;
		   }

		else
		{
		   t=t+w[i];
		}
	      }
	      else
	      break;
	  }
	  return i;


}

int main()
{
	int n,i,j;
	float c,p[10],w[50],v[10],sum_vi=0.0,sum_wi=0.0,temp;
//	clrscr();
	printf("\nEnter the number of Items:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("Enter Weight of Items");
	scanf("%f",&w[i]);
	printf("Enter the value of Items");
	scanf("%f",&v[i]);
	  p[i]=v[i]/w[i];

	}

	printf("\nEnter Capacity:");
	scanf("%f",&c);
	for(i=0;i<n;i++)
	{
	    for(j=i+1;j<n;j++)
	    {
	    if(p[i]<p[j])
		{
		temp=p[j];
		p[j]=p[i];
		p[i]=temp;
	     //***********//
		temp=v[j];
		v[j]=v[i];
		v[i]=temp;
	     //***********//
		temp=w[j];
		w[j]=w[i];
		w[i]=temp;

		}

	  }
	}
     n= Knapsackpart(p,v,w,n,c);
     for(i=0;i<n;i++)
     {
     printf("\n%f",w[i]);
     printf("\t%f",v[i]);
     printf("\t%f",p[i]);
     sum_vi=sum_vi+v[i];
     sum_wi=sum_wi+w[i];
     }
     printf("\n\n sum of value: %f",sum_vi);
     printf("\n\n Total weight: %f",sum_wi);
     getch();
}
