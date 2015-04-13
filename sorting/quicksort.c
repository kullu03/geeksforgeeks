#include<stdio.h>

//exchange utility

void exchange(int *a,int *b)
{

int temp;
temp = *a;
*b= *a;
*a=temp;
}

//quicksort routine

/*void quicksort(int a[],int start,int last)
{
int q;
if(start<last)
{
 q=partition(a,start,last);
quicksort(a,start,q-1);
quicksort(a,q+1,last);
}
}*/
int partition(int a[],int start,int last)
{
int x=a[last];
int i=start-1;
int j;
for(j=start;j<last;j++)
{
if(a[j]<=x)
{
i=i+1;
//exchange(&a[i],&a[j]);
int temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
//exchange(&a[i+1],&a[last]);
a[last]=a[i+1];
a[i+1]=x;
return i+1;

}

void quicksort(int a[],int start,int last)
{
int q;
if(start<last)
{
 q=partition(a,start,last);
quicksort(a,start,q-1);
quicksort(a,q+1,last);
}
}



//driver program to test quicksort routine

int main()
{

int arr[]={9,78,34,6,2,3,90,12,79,67};
int size= sizeof(arr)/sizeof(arr[0]);
quicksort(arr,0,size-1);
printf("After quicksort Array is:\n");
for(int i=0;i<size;i++)
printf("%d\t",arr[i]);

return 0;
}
