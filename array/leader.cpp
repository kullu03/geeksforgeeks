
#include<stdio.h>

void printLeaders(int arr[],int size)
{

printf("%d\t",arr[size-1]);

int max= arr[size-1];

for(int j = size-2;j>0;j--)
{

if(arr[j]>max)
{

printf("%d\t",arr[j]);
max =arr[j];


}



}














}














int main()
{
  int arr[] = {16, 17, 4, 3, 5, 2};
  printLeaders(arr, 6);
  getchar();
}
