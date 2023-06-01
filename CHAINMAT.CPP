 #include<stdio.h>
#include<limits.h>
#include<conio.h>


int matrixchain(int p[],int i,int j)
{

	int k,count;
	int min=INT_MAX;
		if(i==j)
			return (0);
	for(k=i;k<j;k++)
	{
     count=matrixchain(p,i,k)+matrixchain(p,k+1,j)+p[i-1]*p[k]*p[j];
		if(count<min)
		min=count;

	}
return min;

}
int main()
{
int arr[5]={4,50,3,2,7};
int n= sizeof(arr)/sizeof(int);
//clrscr();
printf("\n The value of n is %d ",n);
printf("\n The optimal solution is %d ",matrixchain(arr,1,n-1));

getch(); 
return 0;
}
