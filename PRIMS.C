 #include<stdio.h>
 #include<conio.h>
 #define INF 1000
 int vertex[10],wght[10][10],new_wght[10][10],n,closed[10];
 int inclose(int i,int n1)
 {
 int j;
 for(j=0;j<=n1;j++)
 if(closed[j]==i)
 return 1;
 return 0;
  }

  void buildtree()
  {
   int i=0,j,count=0,min,v1=0,v2=0;
   closed[0]=0;
	while(count<n-1)
	{
	min=INF;
	 for(i=0;i<=count;i++)
	 for(j=0;j<n;j++)
	     if(wght[closed[i]][j]<min &&! inclose(j,count))
	     {
	     min=wght[closed[i]][j];
	     v1=closed[i];
	     v2=j;

	     }
	     new_wght[v1][v2] =new_wght[v2][v1]=min;
	     count++;
	     closed[count]=v2;
	     printf("\nscan %d :  %d   ::.............%d  wght=%d\n",count,v1+1,v2+1,min);
	     getch();

	}

  }

  void main()
  {
  int i,j,ed,sum=0;
  clrscr();
  printf("\n\n\t PRIMS ALGORITHM TO FIND SPANNING TREE");
  printf("\n enter the no of NODES:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {

  vertex[i]=i+1;
	 for(j=0;j<n;j++)
	   {
	   wght[i][j]=INF;
	   new_wght[i][j]=INF;

	   }
  }

 printf("GETTING WEIGHT");
 printf("\n\t enter 0 if path does n't exist between{v1,v2} else enter weight");
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
      {
	 printf("\n\t%d ............%d:",vertex[i],vertex[j]);
	 scanf("%d",&ed);
		 if (ed>=1)
		 wght[i][j]=wght[j][i]=ed;

	}
      getch();
	printf("\n\n\t NODES CURRENTLY ADDED TO SPANNING TREE:");
	buildtree();

	printf("\n\n\t MINIMUM PSPANNING TREE");
	printf("\n \t LIST OF EDGES");
	 for(i=0;i<n;i++)
	  for(j=i+1;j<n;j++)
	  if(new_wght[i][j]!=INF)
	  {
	  printf("\n\t %d.........%d   =%d",vertex[i],vertex[j],new_wght[i][j]);
	  sum+= new_wght[i][j];
	  }

  printf("\n\n \t TOTAL WEIGHT = %d",sum);
  getch();

  }
