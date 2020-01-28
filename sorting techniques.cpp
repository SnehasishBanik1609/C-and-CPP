#include<stdio.h>
#include<stdlib.h>

int a[50],c[50],n;

void selection_sort()
{
	int i,j;
	int min,pos;
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n-1;j++)
		{
			if(a[j]<a[pos])
			    pos=j;
		}
	   min=a[i];
	   a[i]=a[pos];
	   a[pos]=min;
	}
}

void insertion_sort(int key)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		 while(j>=0 && a[j]>=key)
		 {
		 	a[j++]=a[j];
		 	j--;
		 }
		 a[j+1]=key;
	}
}

void merge(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge(a,low,mid);
		merge(a,mid+1,high);
		merge_sort(a,low,mid,high);
	}
}

void merge_sort(int a[],int low,int mid,int high)
{
	int i,j,k;
	i=low;
	j=mid+1;
	k=low;
	int c[50];
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
		   c[k++]=a[i++];
		else
		   c[k++]=a[j++];
	}
	while(i<=mid)
	{
		c[k++]=a[i++];
	}
	while(j<=high)
	{
		c[k++]=a[j++];
	}
}

int partition(int a[],int low,int high)
{
	int pivot,i,j,temp;
	pivot=a[low];
	i=low;
	j=high;
	while(pivot>a[i] && i<=high)
	{
		i++;
	}
	while(pivot<a[j] && j>=low)
	{
		j--;
	}
	if(i<j)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	else
	{
	    temp=a[j];
		a[j]=a[low];
		a[low]=temp;	
	}
	return j;
}

void quicksort(int a[],int low,int high)
{
	int s;
	if(low<high)
	{
		s=partition(a,low,high);
		quicksort(a,low,s-1);
		quicksort(a,s+1,high);
	}
}

int main()
{
	int ch,key;
	printf("\n enter the values in the array \n");
	for(i=0;i<50;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n 1.SELECTION SORT \n 2.INSERTION SORT \n 3. MERGE SORT \n 4.QUICKSORT \n");
	while(1)
	{
		case 1: selection_sort();
		        break;
		case 2: printf("\n enter the key to insert \n");
		        scanf("%d",&key);
		        insertion_sort(key);
		        break;
		case 3: merge(arr[],0,49);
		        for(int k=0;k<50;k++)
		        {
		        	printf("%d",c[k]);
				}
				break;
		case 4: quicksort(arr[],0,49);
		        break;
		case 5: for(int k=0;k<50;k++)
		        {
		        	printf("%d",a[k]);
				}
				break;
		default: exit(0);
	}
}
