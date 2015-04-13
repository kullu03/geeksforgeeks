#include<stdio.h>
#include<queue>
#include <hash_map>
#include <iostream>
#define _DEFINE_DEPRECATED_HASH_CLASSES 0



struct node{
int data;
int hd;
struct node *left;
struct node *right;
};

/*struct Qitem{
struct node Node;
int hd;
};*/


struct node *newNode(int data)
{
struct node *temp = (struct node *)malloc sizeof((struct node));
temp->data = data;
temp->left = NULL;
temp->right = NULL;
temp->hd = 0;
return temp;
}


void printTopView(struct node *root)
{
if(root == NULL)
return;

std::queue<struct node *>q;
std::hash_map<int,struct node *> table;

q.push(root);

while(!q.empty())
{

struct node *temp = q.front();
q.pop();
int hd = temp->hd;
if(!table.contains[hd])
{
printf("%d\t",table[hd]->data);
table[hd] = temp;
}
if(temp->left)
{
temp->left->hd = hd+1;
q.push(temp->left);
}
if(temp->right)
{
temp->right->hd = hd+1;
q.push(temp->right);
}
}
}

int main()
{

struct node *root = newNode(1);
root->left = newNode(2);
root->right = newNode(3);
root->left->right = newNode(4);
root->left->right->right = newNode(5);
root->left->right->right->right = newNode(6);
printf("Following are nodes in top view of Binary Tree");
printTopView(root);
return 0;
}
