#include<stdio.h>
#include<stdlib.h>
// O(N) solution for finding duplicate but  array element must be in between 0 to n-1,where size is n

void printReapeating(int A[],int size)
{

for(int i =0; i<=size-1;i++)
{

if(A[(abs(A[i]))]>0)
{

A[(abs(A[i]))] = -A[(abs(A[i]))];

}

else
{
printf("%d\t",abs(A[i]));

}

}

}


int main()
{
  int arr[] = {1, 2, 3, 1, 3, 6, 6};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printReapeating(arr, arr_size);
  getchar();
  return 0;
}
