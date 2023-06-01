 
 

//this is an algorithm to find out max and min using divide and conquer rule.
#include<conio.h>
#include<stdio.h>
int a[100],max=0,min=1000,mid,n,max1,max2,min1,min2;
 
 
void max_min(int j,int n)
 {
int p=0,i;
if(p==j)
{
max=min=a[p];//wen der is only one element in array
printf("max is:%d and min is :%d",max,min);
}
else if(p==j-1)
{
if(a[p]<a[j])
{
max=a[j];
min=a[p];
}
else
{
max=a[p];
min=a[j];
}
printf("max is:%d and min is :%d",max,min);
}
else
{
mid=(int)((p+j)/2);
for(i=0;i<mid;i++)
{
if(a[i]>max)
{
max=a[i];
}
if(a[i]<min)
{
min=a[i];
}
}
max1=max;
min1=min;

max=0;
min=1000;
for(i=mid;i<n;i++)
{
if(a[i]>max)
{
max=a[i];
}
if(a[i]<min)
{
min=a[i];
}
}
max2=max;
min2=min;


if(max1<max2)
{
max=max2;
}
else
max=max1;
if(min1<min2)
{   
min=min1;
}
else
{
min=min2;
}
printf("\nmaximum is:%d\n",max);
printf("\n minimun is:%d\n",min);
}
} 

int main()
{
int i,j;
printf("enter the size of the array");
scanf("%d",&n);
printf("enter the elements of the array");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);

}
j=n-1;
max_min(j,n);

getch();

return 0;
}
