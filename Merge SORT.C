#include<stdio.h>
#include<conio.h>

void merge(int A[], int lower1, int upper1, int lower2,int upper2 )
{
int p,q,j,n;
int D[10];

p=lower1;
q=lower2;
n=0;

while((p<=upper1)&&(q<=upper2))
{
D[n++]=(A[p]<A[q]?A[p++]:A[q++]) ;
}

while(p<=upper1)

D[n++]=A[p++];
while(q<=upper2)
D[n++]=A[q++] ;

for(q=lower1,n=0;q<=upper1;q++,n++)
A[q]=D[n];

for(q=lower2,j=n;q<=upper2;q++,j++)
A[q]=D[j];

}
void mergesort(int A[], int lower, int upper)
{
int mid;
if(upper>lower)
{
mid=(lower+upper)/2;
mergesort(A,lower,mid);
mergesort(A,mid+1,upper);
merge(A,lower,mid,mid+1,upper);
}

}


int main()
{
int i,lower,upper,n;
int A[50];
//clrscr();
printf("enter the upper limit");
scanf("%d",&n);
printf("enter the numbers");
for(i=0;i<n;i++)
{
scanf("%d",&A[i]);
}
lower=0;
upper=n-1;
mergesort(A,lower,upper);

for(i=0;i<n;i++)
{printf(" %d  ",A[i]);
}

getch();
return(0);
}