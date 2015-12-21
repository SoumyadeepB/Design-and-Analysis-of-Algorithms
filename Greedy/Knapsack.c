#include<stdio.h>
double p[100],w[100],pw[100];
int main()
{
	int m,n,i,j,item[100]={0};
	double temp,rem,sol[010]={0},profit=0;
	
    printf("\n Enter the knapsack capacity : ");
	scanf("%d",&m);
	printf("\n n: ");
	scanf("%d",&n);
	printf("\n Weights: ");
	for(i=1;i<=n;i++)
	  scanf("%lf",&w[i]);
	printf("\n Profit: ");
	for(i=1;i<=n;i++)
	  scanf("%lf",&p[i]);
	for(i=1;i<=n;i++)
	{
		pw[i]=p[i]/w[i];
	    item[i]=i;
	}
	printf("\n");
	for(i=1;i<=n;i++)
	 {
	 	for(j=1;j<=n-i;j++)
	 	 {
	 	 	if(pw[j+1]>pw[j])		//sort in decreasing order
	 	 	{
	 	 		temp=pw[j];
	 	 		pw[j]=pw[j+1];
	 	 		pw[j+1]=temp;
	 	 		
	 	 		temp=p[j];
	 	 		p[j]=p[j+1];
	 	 		p[j+1]=temp;
	 	 		
	 	 		temp=w[j];
	 	 		w[j]=w[j+1];
	 	 		w[j+1]=temp;
	 	 		
	 	 		temp=item[j];
	 	 		item[j]=item[j+1];
	 	 		item[j+1]=temp;
	 	 		
	 	 	}
	 	 }
	 }
	 
	 //for(j=1;j<=n;j++)
   // 	printf(" %d  %lf  %lf\n",item[j],p[j],w[j]);
	 
	 rem=m;             // remaining mass
	 printf("\n Items chosen in order : \n");
	 for(i=1;i<=n;i++)
	 {
	 	if(w[i]>rem)
	 	 break;
	 	else
	 	{
	 	  sol[item[i]]=1;
		  printf("\nItem : %d",item[i]);     // item selected
    	}
		 profit +=p[i];
		 rem -=w[i]; 
	 }
	 if(w[i]>rem)
	  {
	   sol[item[i]]=rem/w[i];
	   profit+=p[i]*(rem/w[i]);
      }
	  
	  
	  printf("\n\n Solution : ");
	  for(i=1;i<=n;i++)
	  {
	  	printf(" %.3lf ",sol[i]);
	  }
	  printf("\n\n Profit : %.3lf",profit);
return 0;
}
