#include<stdio.h>
int s[100][100]={0};
void prnths(int i,int j)
{
	if(i==j)
	 printf("A%d ",i);
	else
	{
		printf("(");
		prnths(i,s[i][j]);
		prnths(s[i][j]+1,j);
		printf(")");
		
	}
}
int main()
{
	long int n,p[100],m[100][100],i,j,k,l,temp,min,total=0;
	printf("\nNo. of matrices: ");
	scanf("%d",&n);
	printf("\nEnter the dimensions :");
	for(i=0;i<n;i++)
	{
		printf("Matrix %d: ",i+1);
		scanf("%d %d",&p[i],&p[i+1]);
	}
	
	for(i=1;i<=n;i++)
	{
		m[i][i]=0;
	}
	
	for(l=1;l<=n-1;l++)
	{
		for(i=1;i<=n-l;i++)
		{
			j=i+l;
			min=999999;
			for(k=i;k<j;k++)
			{
				temp=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
				if(temp<min)
				 {
				  min=temp;
				  s[i][j]=k;
			     }
			}
			m[i][j]=min;
		}
	}
	for(i=1;i<=n;i++)
	 {
	 	for(j=i;j<=n;j++)
	 	  {
	 	   printf("s[%d][%d] : %d\n",i,j,s[i][j]);
	 	     
	 	  }printf("\n");
	 }
	 
	 prnths(1,n);
	 printf("\n\nTotal no. of scalar multiplications: %d",m[1][n]);
	 
	 return 0;
}
