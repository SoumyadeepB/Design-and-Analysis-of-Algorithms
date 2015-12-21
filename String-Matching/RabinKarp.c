#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	char t[100],p[100];
	int t_val=0,p_val=0,x,k=0,i,j,m,n,s,txt,flag=0,q=19;  // q : any prime number
	printf("\nEnter the text: ");
	gets(t);
	printf("\nEnter the pattern: ");
	gets(p);
	n=strlen(t);
	m=strlen(p);
	x=pow(10.0,(double)(m-1));
	
	for(i=0;i<m;i++)
	{
		t_val=(int)( (t_val * 10) + (t[i]-'0'));
		p_val=(int)( (p_val * 10) + (p[i]-'0'));
	}
	
	txt=t_val%q;
	p_val=p_val%q;
	
	for(s=0; s<=n-m ; s++)
	 {
	 	flag=1;
	 	
	 	 if(txt==p_val)
	 	  {
	 	  	for(j=0; j<m ;j++)
	 	  	 {
	 	  	 	if(t[j+s]!=p[j])
	 	  	 	  {
	 	  	 	  	flag=0;
	 	  	 	  	break;
	 	  	 	  }
	 	  	 }
	 	  	 if(flag)
	 	  	  printf("\n %d. Pattern occurs with shift %d .",++k,s);
	 	  }
	 	  
	 	  if(s< n-m )
	 	  {
	 	  	t_val = (( (t_val - ((t[s] - '0') * x)) *10) + (t[s+m] - '0'));
	 	  	txt = t_val % q;
	 	  }
	 }
	 return 0;
}
