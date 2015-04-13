#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;

void sortWave(int arr[],int size)
{

int i =0;
int j = i+1;
while(size > 0 && i<=size && j<=size)
{
if(arr[i]<arr[j])
{
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
i =i+2;
j =j+2;
size = size-1;
}
else
{
size = size-1;
i= i+2;
j =j+2;
}

}

}


// Driver program to test above function
int main()
{
    int arr[] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
int n = sizeof(arr)/sizeof(arr[0]);

    cout << "before sort:" <<"\n";
        for (int i=0; i<n; i++)
       cout << arr[i] << " ";

   // int n = sizeof(arr)/sizeof(arr[0]);
    sortWave(arr, n);
    cout << "Sorted array \n";
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    return 0;
}
