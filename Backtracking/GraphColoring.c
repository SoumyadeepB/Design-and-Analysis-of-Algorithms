#include<stdio.h>

int main()
{
	int g[150][150]={0},used[150]={0},color[150]={0},u,v,i,n,e;
	
	printf("\n Enter no. of Nodes and Edges : ");
	scanf("%d %d",&n,&e);
	
	for(i=1;i<=e;i++)
	{
		printf("\n Vertex [u,v] containing Edge %d : ",i);
	    scanf("%d %d",&u,&v);
	    g[u][v]=g[v][u]=1;			// marking nodes that have edges between them
	}
	
	color[1]=1;				// first vertex can be assigned any color
	
	for(u=2;u<=n;u++)				// starting scan from 2nd vertex
	 {
	 	for(v=1;v<=n;v++)
	 	{
	 		if(g[u][v]==1 && color[v]!=0) // vertex u,v are connected and v has been 
	 		{							  // assigned a color already (color[v]!=0)
	 			
				 used[color[v]]=1;		  //marking the colors already assigned as 'used'
	 		}
	 	}
	 	
	 	for(i=1;i<=n;i++)
	 	{
	 		if(used[i]==0)			// locating the first unused color
	 		{
	 			color[u]=i;
	 			break;				// break as and when an unused color is traced
	 		}
	 	}
	 	
	 	for(i=1;i<=n;i++)
	 	  used[i]=0;				// mark all vertices as unused for next iteration
	 }
	 
	 for(i=1;i<=n;i++)
	  printf("\n Vertex %d : Color %d",i,color[i]);
	  
	return 0;
}
