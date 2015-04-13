#include<malloc.h>
#include <iostream>
#include <queue>
using namespace std;
 
struct node {
int data;
struct node *left;
struct node *right;
};

struct node * newNode(int data)
{

struct node * temp = (struct node *) malloc(sizeof(struct node));

temp->data = data;
temp->left = NULL;
temp->right = NULL;
return temp;
}


struct node * getNextRight(struct node *root,int key)
{

if(root == NULL)
return NULL;
std::queue<struct node *>q;
std::queue<int>lq;
q.push(root);
lq.push(0);
while(!q.empty())
{

struct node *temp;
int level = lq.front();
lq.pop();
temp = q.front();
q.pop();

//if(temp->right && temp->data == key && size == 0)
//return temp->right;
if( key == temp->data)
{
if(!q.empty() && level == lq.front())
{
lq.pop();
temp = q.front();
q.pop();
return temp;
}
}
if(temp->left)
{
q.push(temp->left);
lq.push(level+1);
}
if(temp->right)
{
q.push(temp->right);
lq.push(level+1);
}
}

return NULL;

}



int main()
{
    // Let us create binary tree given in the above example
    node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(6);
    root->right->right = newNode(5);
    root->left->left = newNode(8);
    root->left->right = newNode(4);
 
 struct node * temp =    getNextRight(root, 8);
if(temp)
printf("%d\t",temp->data);
    //test(root, 2);
    //test(root, 6);
    //test(root, 5);
    //test(root, 8);
    //test(root, 4);
    return 0;
}
