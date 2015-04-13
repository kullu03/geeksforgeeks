// This file is all about printing diff view of a binary tree
// C program to print left view of Binary Tree
#include<stdio.h>
#include<stdlib.h>
#include<queue>
 
struct node
{
    int data;
    struct node *left, *right;
};
 
// A utility function to create a new Binary Tree node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}


void printRightView(struct node *root)
{
if(root == NULL)
printf("Tree is empty !!!! Can We print anything Naahh !!!\n");

std::queue<struct node *>q;
q.push(root);
//int s = q.size();

while(!q.empty())
{

int s = q.size();
while(s >0)
{
struct node * temp = q.front();
q.pop();
// print temp->data when it is last node of the level??
if(s == 1)
printf("%d\t",temp->data);

if(temp->left)
q.push(temp->left);
if(temp->right)
q.push(temp->right);
s =s-1;
}
}
}

void printLeftView(struct node *root)
{

if(root == NULL)
printf("Tree is empty !!!! Can We print anything Naahh !!!\n");

std::queue<struct node *>q;
bool flag =true;
q.push(root);
//int s = q.size();

while(!q.empty())
{

int s = q.size();
while(s >0)
{
struct node * temp = q.front();
q.pop();
// print temp->data only when it is first node at this level ??
if(flag)
printf("%d\t",temp->data);

flag = false;

if(temp->left)
q.push(temp->left);
if(temp->right)
q.push(temp->right);
s =s-1;
}
flag  = true;
}
}

// Driver Program to test above functions
int main()
{
    struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
 
    printRightView(root);
 
    return 0;
}
