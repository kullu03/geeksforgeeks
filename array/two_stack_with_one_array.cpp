#include<iostream>
#include<stdlib.h>

using namespace std;

class twoStacks
{

int *arr;
int top1;
int top2;
int size;
public:
twoStacks(int n)
{

arr = new int[n];
size = n;
top1 =-1;
top2 = size;
}

void push1(int data)
{

if(top1 < top2 - 1)
{

top1++;
arr[top1] = data;

}
}
void push2(int data)
{

if(top1 < top2 -1)
{

top2--;
arr[top2] = data;

}
}

int pop1()
{
int temp;
if(top1 != -1)
{
temp = arr[top1];
top1--; 
}
return temp;
}

int pop2()
{
int temp;
if(temp != size)
{

temp = arr[top2];
top2--;
}
return temp;
}

};




int main()
{
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is " << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is " << ts.pop2();
    return 0;
}
