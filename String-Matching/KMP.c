#include<stdio.h>
#include<string.h>

char t[150],p[150];
int pi[150];
void prefix(int m)
{
	int q,k=0;
	pi[1]=0;
	
	for(q=2;q<=m;q++)
	{
		while(k>0 && p[k+1]!=p[q])
		 k=pi[k];
		 
		 if(p[k+1]==p[q])
		  k++;
		  
		  pi[q]=k;
		 
	}
}

void KMP(int n,int m)
{
	int i,q=0;
		
     for(i=1;i<=n;i++)
     {
     	
     	while(q>0 && p[q+1]!=t[i])
     	 q=pi[q];
     	 
     	 if(p[q+1]==t[i])
     	  q++;
     	  
     	  if(q==m)
     	  {
     	  	printf("\nPattern occurs with shift %d ",i-m);
     	  	q=pi[q];
     	  }
     }
}
int main()
{
	int m,n;
	printf("\nEnter the text: ");
	 gets(t);
	 n=strlen(t);
	printf("\nEnter the pattern: ");
	 gets(p);
	 m=strlen(p);
	 prefix(m);
	 KMP(n,m);
	 
	 return 0;
}
