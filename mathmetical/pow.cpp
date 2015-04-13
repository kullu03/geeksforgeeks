#include<stdio.h>

int power(int x,int y)
{
if(y==0)
return 1;

if(y==1)
return x;

int p = power(x,y/2);
if(y %2 == 0)
return p*power(x,y/2);
else
return p*p*power(x,y/2);
}

/* Program to test function power */
int main()
{
    int x = 5;
    int y = 4;
 
    printf("%d", power(x, y));
    getchar();
    return 0;
}
