// it is also NP-Complete problem so no polynomial time algorithm exist for it. Recursive sol have O(2^n) complexity.

#include<stdio.h>
bool hasPartion(int arr[],int size,int sum)
{
if(sum == 0)
return true;

if(size == 0 && sum !=0)
return false;

if(arr[size-1] > sum)
return hasPartion(arr,size-1,sum);

return hasPartion(arr,size-1,sum) || hasPartion(arr,size-1,sum-arr[size-1]);

}

bool findPartion(int arr[],int size)
{

int sum = 0;

for(int i = 0; i<size; i++)
sum = sum+arr[i];
if(sum %2 != 0)
return false;
else
return hasPartion(arr,size,sum/2);
}


// Dynamic Programming soln

int max(int a,int b)
{
if(a>=b)
return a;
else
return b;

}

bool hasSol(int arr[],int size)
{
int sum = 0;
for(int i = 0 ; i<size; i++)
sum = sum +arr[i];
if(sum%2 != 0)
return false;

int table[size+1][sum/2];

for(int i = 0; i<= size; i++)
table[i][0] = 1;

for(int j = 0 ; j < sum/2; j++)
{
table[0][j] = 0;
}

for(int i = 1; i <= size; i++)
for(int j = 1; j < sum/2; j++)
{

table[i][j] = max(table[i][j],table[i-1][j- table[j-1]]);

}
return table[size][sum/2];
}


int main()
{
  int arr[] = {3, 1, 5, 9, 12};
  int n = sizeof(arr)/sizeof(arr[0]);
  if (hasSol(arr, n) == true)
     printf("Can be divided into two subsets of equal sum");
  else
     printf("Can not be divided into two subsets of equal sum");
  getchar();
  return 0;
}
