#include<stdio.h>

int a[100],temp[100];

void merge(int beg,int mid,int end)
{
	int i,j,k,index;
	i=index=beg;
	j=mid+1;
	
	while(i<=mid && j<=end)
	{
		if(a[i]<a[j])
		{
			temp[index]=a[i];
			i++;
		}
		else if(a[j]<a[i])
	    {
			temp[index]=a[j];
			j++;
		}		
			index++;
	}
	if(i>mid)
	{
		while(j<=end)
		{
			temp[index++]=a[j++];
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index++]=a[i++];
		}
	}
	
	for(k=beg;k<index;k++)
	{
		a[k]=temp[k];
	}
}

void mergeSort(int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		mergeSort(beg,mid);
		mergeSort(mid+1,end);
		merge(beg,mid,end);
	}
}
int main(){
   int i,n;

   printf("Enter the size of the array : ");
   scanf("%d",&n);

   printf("Enter the elements :\n");
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);

   mergeSort(0,n-1);
   printf("\n\n");
   printf("Elements in sorted order : ");
  for(i=0;i<n;i++)
      printf("%d ",a[i]);
   return 0;
}
