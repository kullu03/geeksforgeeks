#include<stdio.h>
#include<vector>
#include<algorithm>
#define True 1
#define False 0

#define bool int



bool hasTripletWithSum(int arr[],int sum, int size)
{

for(int i =0; i<size-2;i++)
{

int newSum = sum - arr[i];
int left = i+1;
int right = size -2;

while(left < right)
{

if(arr[left]+arr[right] == newSum)
return True;

if(arr[left]+arr[right] < newSum)
{
left++;
}
else
{

right--;

}
}
}
return False;

}


/* Driver program to test above function */
int main()
{
    int A[] = {1, 4, 6,8,10,45};
    int sum = 22;
    int arr_size = sizeof(A)/sizeof(A[0]);
    std::vector<int> myvector (A, A+6);
    std::sort(myvector.begin(), myvector.end());
 
    int r = hasTripletWithSum(A,sum, arr_size);
    if(r)
    printf("Yes it is !!!\n");
    else
    printf("NO NO\n");
 
    getchar();
    return 0;
}
