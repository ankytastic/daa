#include<stdio.h>
#include<conio.h>

int partition(int a[],int lower,int upper)
{
	int i,p,q,t;
	p=lower;
	q=upper+1;
	i=a[lower];
	while(q>=p)
	{
		while(a[++p]<i);
		while(a[--q]>i);
		if(q>p)
		{
			t=a[p];
			a[p]=a[q];
			a[q]=t;
		}
	}
	t=a[lower];
	a[lower]=a[q];
	a[q]=t;
	return q;
}



void quicksort(int a[],int lower,int upper)
{
	int i;
	if(upper>lower)
	{
		i=partition(a,lower,upper);
		quicksort(a,lower,i-1);
		quicksort(a,i+1,upper);
	}
}

int main()
{
	int a[100],lower,upper,i,n,j;

	printf("\tenter the no of element to be inserted:\t");
	scanf("%d",&n);
	lower=0;
	upper=n-1;
	printf("\tenter the elements\n");
	for(i=0;i<n;i++)
	       {	printf("\t%d :   ",i);
			scanf("%d",&a[i]);
		}
	
	quicksort(a,lower,upper);

	
	printf("sorted list is:\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	
	getch();
	return 0;
}
