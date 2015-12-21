#include<stdio.h>
int a[15];


int partition(int beg,int end)
{
   int loc,left,right,flag=0,temp;	
loc=left=beg;
	right=end;
//	printf("\nLoc: %d",loc);
    while(flag!=1)
    {
    	while((a[loc]<a[right]) && (loc!=right))
    	  right--;
    	  
    	  if(loc==right)
    	   flag=1;
    	  else if(a[loc]>a[right])
    	   {
    	   	temp=a[loc];
    	   	a[loc]=a[right];
    	   	a[right]=temp;
    	   	loc=right;
    	   }
    	   
    	  if(flag!=1)
		{
			while((a[loc]>a[left]) && (loc!=left))
			 left++;
			 
			if(loc==left)
			  flag=1;
			else if(a[loc]<a[left])
			 {
			    temp=a[loc];
			    a[loc]=a[left];
			    a[left]=temp;
			    loc=left;	
			 } 
		} 
    }
    return loc;
}

void quicksort(int beg,int end)
{
   int loc;
	if(beg<end)
	 {
	 	loc=partition(beg,end);
	 	quicksort(0,loc-1);
	 	quicksort(loc+1,end);
	 }
}

void main()
{
	
  int n,i;
  
  printf("\n Enter the number of elements : ");
  scanf("%d",&n);
  
   printf("\n Enter the elements : ");
  for(i=0;i<n;i++)
   {
   	printf("\n %d: ",i+1);
   	scanf("%d",&a[i]);
   }	
   
   quicksort(0,n-1);
   
   printf("\n The sorted array is: \n\t");
   for(i=0;i<n;i++)
   
   	printf("%d  ",a[i]);
  	
}
