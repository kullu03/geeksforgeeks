#include<string.h>
#include<stdio.h>
int min(int a,int b,int c)
{

if(a>b && a>c)
return a;
else if(b>a && b>c)
return b;
else
return c;


}
int editDistance(char s[],char t[],int sl,int tl)
{
if(tl == 0 && sl == 0)
return 0;

if(tl ==0)
return sl;

if(sl == 0)
return tl;

int left = editDistance(s,t,sl-1,tl);
int right = editDistance(s,t,sl,tl-1);
int corner = editDistance(s,t,sl-1,tl-1);
return min(left,right,corner);
}

int main()
{
    char X[] = "sunday"; // vertical
    char Y[] = "saturday"; // horizontal
 
    printf("Minimum edits required to convert %s into %s is %d\n",
           X, Y, editDistance(X, Y,strlen(X),strlen(Y)));
    //printf("Minimum edits required to convert %s into %s is %d by recursion\n",
      //     X, Y, EditDistanceRecursion(X, Y, strlen(X), strlen(Y)));
 
    return 0;
}
