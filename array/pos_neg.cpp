#include<stdio.h>
void sort(int a[] ,int size)
{

for(int i=0;i<size;i++)
for(int j=0;j<size;j++)
if(a[i]<a[j])
{
int temp = a[i];
a[i]= a[j];
a[j]= temp;
}
}


void printArray(int arr [],int size)
{

for(int i =0;i<size;i++)
printf("%d\t",arr[i]);

}




void alternatePosNeg(int arr [], int size)
{

sort(arr,size);
//printf("sorted:");
//printArray(arr,size);
int i = 0;
int j = 0;
while(arr[j]<0)
j++;
while((!(arr[i]<0 && arr[j]<0)) ||(!(arr[i]>0 && arr[j]>0))&& i < size && j<size)
{
int temp;
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
i = i+2;
j = j+1;
}

printArray(arr,size);

}


int main()
{

int arr[] = {1,2,-3,4,5,6,-7,8,9};

alternatePosNeg(arr,9);
return 0;

}
