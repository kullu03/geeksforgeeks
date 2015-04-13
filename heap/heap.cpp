#include<stdio.h>

void maxHeapify(int arr[],int size,int i);
void buildMaxHeap(int arr[],int size)
{
for(int i = size/2; i >= 0 ; i--)
maxHeapify(arr,size,i);
}

void maxHeapify(int arr[],int size,int i)
{
for(int i = 0; i < size ; i++)
{
int left = 2*i+1;
int right = 2*i+2;
int largest = 0;
if(left <= size -1 && arr[left] > arr[i])
{
largest = left;
}
else
largest = i;

if(right <= size -1 && arr[right] > arr[largest])
largest = right;

if(largest != i)
{
int temp = arr[largest];
arr[largest] = arr[i];
arr[i] = temp;
maxHeapify(arr,size,largest);
}
}
}
void heapSort(int arr[],int size)
{
buildMaxHeap(arr,size);
int h = size;
for(int i = size-1 ; i >0; i--)
{
int temp = arr[0];
arr[0] = arr[i];
arr[i] = temp;
h= h-1;
maxHeapify(arr,h,0);
}
}

void printArray(int arr[],int size)
{
for(int i = 0; i < size ; i++)
printf("%d\t",arr[i]);
printf("\n");
}
void printMaxK(int arr[],int size,int k)
{
int h = size;
buildMaxHeap(arr,size);
for(int i = 0; i < k; i++)
{
printf("%d\t",arr[0]);
int temp = arr[0];
arr[0]= arr[h];
arr[h]= temp;
h = h-1;
maxHeapify(arr,h,0);
}


}

int main()
{
int arr[] = {16,4,10,14,7,9,3,2,8,1};
printf("Array before it becomes heap\n:");
printArray(arr,10);

//maxHeapify(arr,10,0);
//buildMaxHeap(arr,10);
//printf("Array as a heap\n:");
//printArray(arr,10);
//printf("Sort using heapsort\n:");
//heapSort(arr,10);
//printArray(arr,10);
printMaxK(arr,10,4);
}
