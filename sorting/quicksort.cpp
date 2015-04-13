#include<stdio.h>
int partition(int arr[],int start,int last);


void quicksort(int arr[],int s,int l)
{
if(s <= l)
{
int q = partition(arr,s,l);
quicksort(arr,s,q-1);
quicksort(arr,q+1,l);
}
}


void swap(int *a, int *b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}



int partition(int arr[],int start,int last)
{
int x = arr[last-1];
int i = start - 1;
int p = start;

for(int j=p;j < last; j++)
{
if(arr[j] <= x)
{
i = i + 1;
swap(&arr[i],&arr[j]);
}
}
swap(&arr[i+1],&arr[last-1]);
return i+1;
}

void printArray(int arr[],int size)
{
for(int i = 0; i<size; i++)
printf("%d\t",arr[i]);


}
int main()
{
int arr[] = {2,8,7,1,3,5,6,4};
quicksort(arr,0,7);
printf("Sorted Array:\n");
printArray(arr,10);
return 0;
}
