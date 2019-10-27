#include<stdio.h>
int a[100];


int partition(int beg,int end)
{
   int i,j,x,loc,flag=0,temp;	
    i=beg-1;
	loc=end;
	x=a[loc];

	for(j=beg;j<end;j++)
	 {
	 	if(a[j]<=x)
	 	 {
	 	 	i++;
	 	 	temp=a[j];
	 	 	a[j]=a[i];
	 	 	a[i]=temp;
	 	 }
	 		 	
	 }
			temp=a[loc];
	 	 	a[loc]=a[i+1];
	 	 	a[i+1]=temp;
    return i+1;
}

void quicksort(int beg,int end)
{
   int loc;
	if(beg<end)
	 {
	 	loc=partition(beg,end);
	 	quicksort(beg,loc-1);
	 	quicksort(loc+1,end);
	 }
}

int main()
{
	
  int n,i;
  
  printf("\n Enter the number of elements : ");
  scanf("%d",&n);
  
  printf(" Enter the elements : \n");
  for(i=0;i<n;i++)
   {
   	printf("\n %d: ",i+1);
   	scanf("%d",&a[i]);
   }	
   
   quicksort(0,n-1);
   
   printf("\n The sorted array is: \n\t");
   for(i=0;i<n;i++)
   
   	printf("%d  ",a[i]);
  return 0;
}
