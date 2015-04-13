#include<stdio.h>

int getMissingNumber(int arr [],int low,int high,int diff)
{
if(high <= low)
{
printf("Must have two numbers!!!\n");
return 0;
}
int mid = (low+high)/2;

// element just after the mid is missing
if(arr[mid+1]-arr[mid] != diff)
return arr[mid]+diff;

// element just before the mid is missing

if(mid>0 && arr[mid]-arr[mid-1]!= diff)
return arr[mid-1]+diff;

// check if AP is till mid of array
if(arr[mid]==arr[0]+mid*diff)
{
return getMissingNumber(arr,mid+1,high,diff);
}

return getMissingNumber(arr,low,mid-1,diff);
}


/* Driver program to check above functions */
int main()
{
    int arr[] = {2, 4, 8, 10, 12, 14};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("The missing element is %d", getMissingNumber(arr,0, n,2));
    return 0;
}
