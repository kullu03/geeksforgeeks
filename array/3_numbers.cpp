#include<stdio.h>

void get3Numbers(int arr[],int size)
{

int *small = new int[size-1];
int *large = new int[size-1];
int min = 0;
int max = size -1;

for(int i =1;i <= size-1;i++)
{
if(arr[i] <= arr[min])
{
min = i;
small[min] = -1;
}
else
small[i] = min;

large[max] = -1;

for(int i = size -2; size >=0 ; i--)
{

if(arr[i] >= arr[max])
{
max = i;
large[i] = -1;
}
else
large[i] = max;
}

for(int i = 0 ; i < size ; i++)
{
if(small[i]!=-1 && large[i]!= -1)
printf("%d\t%d\t%d\t",arr[i],arr[small[i]],arr[large[i]]);

}

}

}


// Driver program to test above function
int main()
{
    int arr[] = {12, 11, 10, 5, 6, 2, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    get3Numbers(arr, n);
    return 0;
}
