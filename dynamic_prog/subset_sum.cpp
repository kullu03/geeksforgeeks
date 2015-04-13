// This problem is NP-complete problem. So No polynomial time algorithm exist for this. Below is the recursive implementation of order exponential of input.
#include<stdio.h>

bool  isSubsetSum(int arr[],int size,int sum)
{
if(sum == 0)
return true;
if(size == 0 && sum >=0)
return false;
if(sum >= arr[size-1])
return isSubsetSum(arr,size-1,sum);
return (isSubsetSum(arr,size-1,sum) || isSubsetSum(arr,size-1, sum-arr[size]));

}

// Driver program to test above function
int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 34;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, n, sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}
