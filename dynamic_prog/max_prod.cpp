#include<stdlib.h>
#include<stdio.h>
int maxProd(int n)
{
if(n ==2 || n == 3)
return n-1;

int res =1;
while(n > 4)
{
n = n-3;
res = res*3;
}
return (res*n);
}

/* Driver program to test above functions */
int main()
{
    printf("Maximum Product is %d = " ,maxProd(10));
    return 0;
}
