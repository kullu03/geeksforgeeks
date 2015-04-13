#include<stdio.h>
#include<vector>
#include<algorithm>
#define True 1
#define False 0

#define bool int

// O(N2) solution 

bool hasPairWithSum(int arr[],int sum,int size)
{

for(int i = 0 ; i< size; i++)
{

int second = sum - arr[i];

for(int j = 0; j< size ; j++)
{

if(arr[i]==second)
return True;

}

}
return False;

}

// using sorting O(N) solution

bool hasPairWithSum1(int arr[],int sum,int size)
{

int left =0; int right = size-1;
while(left < right)
{

if(arr[left]+arr[right]==sum)
return True;
if(arr[left]+arr[right] > sum)
{

right --;

}

else
{

left++;

}

}

return False;

}


int main()
{
    int A[] = {1, 4, 6,8,10,45};
    std::vector<int> myvector (A, A+6);
    std::sort(myvector.begin(), myvector.end());
    int n = 16;
    int arr_size = 6;
 
    int  r =  hasPairWithSum1(A,n, arr_size);
if(r)
printf("Yes it is !!!\n");
else
printf("No\n");
 
    getchar();
    return 0;
}
