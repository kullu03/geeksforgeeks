#include<stdio.h>

int fixedPoint(int arr[],int low,int high)
{

if(high >= low)
{
int mid = (low+high)/2;
if (mid == arr[mid])
return mid;

if(mid > arr[mid])
return fixedPoint(arr,mid+1,high);
else
return fixedPoint(arr,low,mid-1);
}
return -1;
}

/* Driver program to check above functions */
int main()
{
    int arr[] = {5,3,4,12,10,0,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Fixed Point is %d", fixedPoint(arr, 0, n-1));
    getchar();
    return 0;
}
