
#include<stdio.h>
#include<conio.h   >
void binSearch(int k,int a[],int n)
{
	int lower=0,mid;
	int j;
	int upper;
	upper=n-1;
	j=-1;
	while(upper>=lower)
	{
		mid=(upper+lower)/2;
		if(k==a[mid])
		{
			j=mid;
			break;
		}
		else
		{
			if(k>a[mid])
				lower=mid+1;
			else
				upper=mid-1;
		}
	}
	if(j==-1)
	printf("The number not found");
    else
	printf("The number is found");
	getch();
}

void main()
{

    int a[10],i,n,k;

    printf("Enter the size of an array: ");
    scanf("%d",&n);

    printf("Enter the elements in ascending order: ");
    for(i=0;i<n;i++)
    {
	 scanf("%d",&a[i]);
    }

    printf("Enter the number to be search: ");
    scanf("%d",&k);
    binSearch(k,a,n);
}
