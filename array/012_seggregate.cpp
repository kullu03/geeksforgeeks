#include<stdio.h>



void swap(int * a,int * b)
{
int * temp;

*temp = *a;
*a= *b;
*b= *temp;
}

void printArray(int arr[],int size)
{

printf("After seggregation array looks like \n");

for(int i = 0; i < size; i++)
printf("%d\t",arr[i]);

}


void seggregate(int arr[],int size)
{

int l=0,m=0,h=size-1;

while(m < h)
{
switch(arr[m])
{

case 0:
swap(&arr[l],&arr[m]);
m++;
l++;
break;

case 1:
m++;
break;

case 2:

swap(&arr[m],&arr[h]);
h--;
}
}
}

int main()
{
int arr[] = {0,1,1,0,2,1,2,0,0,0,1};

seggregate(arr,11);

printArray(arr,11);

return 1;

}
