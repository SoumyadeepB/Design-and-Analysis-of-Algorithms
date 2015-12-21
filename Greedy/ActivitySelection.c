#include<stdio.h>

int main()
{
	int job[100],s[100],f[100],a[100]={0},n,fin,i,j,index,temp;
	printf("\n No. of Jobs : ");
	scanf("%d",&n);
	
	printf("\n Enter Starting and Finishing times respectively : ");
	 for(i=1;i<=n;i++)
	 {
	 	 job[i]=i;
	 	 scanf("%d %d",&s[i],&f[i]);
	 }
	
	for(i=1;i<=n;i++)
	 for(j=1;j<=n-i;j++)
	  {
	  	if(f[j]>f[j+1])
	  	{
	  		temp=f[j];				// sort finishng times in ascending order
	  		f[j]=f[j+1];
	  		f[j+1]=temp;
	  								
	  		temp=s[j];				// sort start times according to finishing time's order
	  		s[j]=s[j+1];
	  		s[j+1]=temp;
	  		
	  		temp=job[j];
	  		job[j]=job[j+1];
	  		job[j+1]=temp;
	  		
	  	}
	  }

	 for(j=1;j<=n;j++)
    	printf(" %d %d %d\n",job[j],s[j],f[j]);
	  
	  a[1]=job[1];
	  index=1;
	  fin=f[1];
	  
	  	
	for(i=1;i<=n;i++)
	   {
	  	 	if(s[i]>=fin)
	  	 	{
	  	 		a[++index]=job[i];
	  	 		fin=f[i];
	  	 	}
	   } 
	   
	    
	    printf("\n The order of activities: ");
	    for(i=1;i<=index;i++)
	     printf(" %d ",a[i]);
	    
	    return 0;
}

