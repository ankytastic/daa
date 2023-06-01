


#include<stdio.h>
#include<conio.h>
int c[10][10],g[10][10][10][10],n;
void calg(int x,int y)
{
     g[x][y][0][0]=c[x][y]+g[y][0][0][0];
     g[y][x][0][0]=c[y][x]+g[x][0][0][0];
     }
     void calg(int x,int y,int z)
     {
          int temp1,temp2;
          temp1=c[x][y]+g[y][z][0][0];
          temp2=c[x][z]+g[z][y][0][0];
          if(temp1>temp2)
          g[x][y][z][0]=temp1;
          else
          g[x][y][z][0]=temp2;
          }
          void calg(int x,int y,int z,int a)
          {
               int temp1,temp2,temp3;
               temp1=c[x][y]+g[y][z][a][0];
               temp2=c[x][z]+g[z][y][a][0];
               temp3=c[x][a]+g[a][y][z][0];
               if(temp1<temp2 && temp1<temp3)
               g[x][y][z][a]=temp1;
               else if(temp2<temp1 && temp2<temp3)
               g[x][y][z][a]=temp2;
               else
               g[x][y][z][a]=temp3;
               }
               void tsp()
               {
                    //[s]=0
                    for(int i=2;i<=n;i++)
                    g[i][0][0][0]=c[i][1];
                    //[s]=1
                    calg(2,3);
                    calg(2,4);
                    calg(3,4);
                    //[s]=2
                    calg(2,3,4);
                    calg(3,2,4);
                    calg(4,2,3);
                    //[s]=3
                    calg(1,2,3,4);
                    }
               int main()
               {
                   printf("algorithm for tsp");
                   printf("enter the no. of cities:\n");
                   scanf("%d",&n);
                   printf("enter the edge matrix value:\n");
                   for(int i=1;i<=n;i++)
                   {
                                    for(int j=1;j<=n;j++)
                                    {
                                                     printf("c[%d][%d]=",i,j);
                                                     scanf("%d",&c[i][j]);
                                                     }
                                                     }
                                                     tsp();
                                                     printf("\n minium path covered is : %d",g[1][2][3][4]);
                                                     getch();
                                                     return(0);
                                                     }
               
               
               
               
     
