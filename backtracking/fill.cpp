#include<stdio.h>



bool fillUtil(int arr[],int curr ,int n)
{
if(curr == 0)
return true;

for(int i = 0 ; i < 2*n -curr-1; i ++)
{

if(arr[i] == 0 && arr[i+curr+1] == 0)
{

arr[i] = arr[curr+i+1] = curr;
if(fillUtil(arr,curr-1,n))
return true;

// backtrack if does not work 
arr[i] = arr[i+curr+1] = 0;
}
}
}


void fill(int n)
{

int arr[2*n];
for(int i = 0; i < 2*n; i++)
arr[i] = 0;

if(fillUtil(arr,n,n))
{
for(int j = 0 ; j < 2*n; j++)
printf("%d\t",arr[j]);
}
else
printf("Not possible to put it !!\n");
}


int main()
{
int n = 7;
fill(7);
return 0;
}
