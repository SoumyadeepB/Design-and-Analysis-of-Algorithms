#include<stdio.h>
int a[100];

void maxheapify(int i,int n)
{
	int l=2*i,r=(2*i)+1,max,tmp;
	
	if(l<=n && a[l]>a[i])
	 max=l;
	else
	 max=i;
	 
	 if(r<=n && a[r]>a[max])
	  max=r;
	  
	  if(max!=i)
	   {
	   	tmp=a[i];
	   	a[i]=a[max];
	   	a[max]=tmp;
	   	 maxheapify(max,n);
	   }
	
}
void buildMaxHeap(int n)
{
	int i;
	for(i=(n/2);i>0;i--)
	 maxheapify(i,n);
}
void heapsort(int n)
{
	int i,tmp;
	buildMaxHeap(n);
	
	for(i=n;i>1;i--)
	{
		tmp=a[1];
		a[1]=a[i];
		a[i]=tmp;
		n--;
		maxheapify(1,n);
	}
}
void main()
{
	
  int i,n;
  
  printf("\n Enter the number of elements : ");
  scanf("%d",&n);
  n=n;
  for(i=1;i<=n;i++)
   {
   	printf("\n %d: ",i);
   	scanf("%d",&a[i]);
   }	
   
   heapsort(n);
   
   printf("\n The sorted array is: \n\t");
   for(i=1;i<=n;i++)
   
   	printf("%d  ",a[i]);
  	
}
