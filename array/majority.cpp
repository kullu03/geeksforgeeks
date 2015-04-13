
#include<stdio.h>





int findCandidate(int a[],int size)
{
int count =1;
int mi =0;
for(int i =1;i<size;i++)
{

if(a[mi] == a[i])
count++;
else
count--;
if(count ==0)
{

mi = i;
count =1;
}

}
return a[mi];

}



void printMajority(int a [], int n)
{
int c=0;
int i,mi;
for(i<0;i<n;i++)
{
for(int j=0;j<n;j++)
{

if(a[i]==a[j])
{
c = c+1;

if(c > n/2)
{

printf("Majority exist\n");
mi = i;
printf("%d\t",a[mi]);
return;
}

}
c =0;
mi =0;
}
}
printf("NO at all");

}













int main()
{
    int a[] = {1, 3,3, 3, 1};
    int c = findCandidate(a, 5);
printf("%d\t",c);
    getchar();
    return 0;
}
