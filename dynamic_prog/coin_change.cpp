#include<stdio.h>
int allPossiblleChanges(int arr[],int sum,int size)
{
if(sum == 0)
return 1;

if(sum < 0)
return 0;

if(sum >= 1 && size <= 0)
return 0;

return (allPossiblleChanges(arr,sum,size-1) + allPossiblleChanges(arr,sum-arr[size-1],size));

}

int count(int S[],int n,int m)
{
int j, x, y;
int table[n+1][m];
// initialize the table
for(int i = 0; i < m; i++)
table[0][i] = 1;
   // Fill rest of the table enteries in bottom up manner 
    for (int i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
 
            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;
 
            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}


// Driver program to test above function
int main()
{
    int i, j;
    int arr[] = {1,2,3};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d ", count(arr,10,m));
    getchar();
    return 0;
}
