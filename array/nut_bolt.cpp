#include<stdio.h>

// this problem is solved using partition method pd quicksort
void swap(char *a,char *b)
{
char temp;
temp = *a;
*b = *a;
*a = temp;
}

int partition(char arr[],int start,int size,char pivot)
{

int i = start-1;
int j = start;
for(j =start; j < size; j++)
{
if(arr[i] < pivot)
{
 i = i+1;
char temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
//swap(&arr[i],&arr[j]);
}
char temp = arr[i+1];
arr[i+1] = arr[size];
arr[size] = temp;
//swap(&arr[i+1],&pivot);
return i+1;
}
}

void matchNutsAndBolts(char nuts [],char bolts [],int low, int high)
{

if(low < high)
{
int pivot = partition(nuts, low, high, bolts[high]);
partition(bolts, low, high, nuts[pivot]);
matchNutsAndBolts(nuts, bolts, low, pivot-1);
matchNutsAndBolts(nuts, bolts, pivot+1, high);
}
}

void printArray(char arr[],int size)
{
for(int  i = 0; i < size ; i++)
printf("%c\t",arr[i]);
printf("\n");
}

int main()
{
  // Nuts and bolts are represented as array of characters
        char nuts[] = {'@', '#', '$', '%', '^', '&'};
        char bolts[] = {'$', '%', '&', '^', '@', '#'};
 
        // Method based on quick sort which matches nuts and bolts
        matchNutsAndBolts(nuts, bolts, 0, 5);
 
        printf("Matched nuts and bolts are :\n ");
        printArray(nuts,5);
        printArray(bolts,5);
        return 0;
}
