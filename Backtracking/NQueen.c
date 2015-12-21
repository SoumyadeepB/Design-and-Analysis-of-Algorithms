#include<stdio.h>
#include<math.h>
int s[10],z=1;
int place(int r,int c)                // r: row , c: column
{
	int j;
	for(j=1;j<r;j++)
	{
		if( (c==s[j]) || (fabs(j-r)==fabs(c-s[j])))
		  return 0;
				  
	}
	return 1;
}

void NQueen(int r,int n)
{
	int c,i;
	for(c=1;c<=n;c++)
	{
		if(place(r,c))
		{
			s[r]=c;
			if(r==n)
			{
				printf("\n Solution %d: ",z++);
				for(i=1;i<=n;i++)
				{
					printf(" %d ",s[i]);
				}
			}
			else
			NQueen(r+1,n);
		}
	}
}
int main()
{
	int n,r;
	printf("\n N : ");
	scanf("%d",&n);
	NQueen(1,n);
	return 0;
}
