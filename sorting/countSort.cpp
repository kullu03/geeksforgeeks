#include<stdio.h>

/*void printArray(int arr[],int size)
{
for(int i = 0 ; i < size ; i++)
printf("%d\t",arr[i]);
}*/

void countSort(int arr[],int size,int k)
{
int C[k+1];
int B[size];

for(int i = 0; i <= k ; i++ )
C[i] = 0;

for(int j = 0 ; j < size; j++)
{
C[arr[j]] = C[arr[j]] +1;
}


for(int m =1; m <= k ; m++)
{
C[m]  = C[m] + C[m-1];
}

for(int n = size-1 ; n >=0; n--)
{

B[C[arr[n]]-1] = arr[n];
C[arr[n]] = C[arr[n]] -1;
}
for(int i=0;i<13;i++)
printf("%d\t",B[i]);
}

int main()
{

int arr[] = {5,6,7,1,1,2,2,3,3,4,4,7,3};
//printf("Unsorted Array:\n");
//printArray(arr,16);

countSort(arr,13,7);

//printf("Sorted Array:\n");
//for(int i=0;i<16;i++)
//printf("%d\t",arr[i]);

//printArray(arr,16);
return 0;
}
