#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
#include<queue>



struct node {
int data ;

struct node *left;

struct node *right;

};


struct node * newNode(int data)
{

struct node * node  = (struct node * )malloc(sizeof(struct node));

node->data = data;
node->left = NULL;
node->right = NULL;

return(node); 



}

int max(int a,int b)
{

if(a>=b)
return a;
else
return b;

}

int maxHeight(struct node *root)
{

if (root == NULL)
return 0;
//if(root->left == NULL && root->right == NULL)
//return 1;

else
return (1+ max(maxHeight(root->left),maxHeight(root->right)));

}

// This is iterative version of get height of the tree //

int getHeight(struct node * root)
{

if(root == NULL)
return 0;

std :: queue<struct node *> q ;

q.push(root);

int height = 0;

int nc = 0;

while(1)
{
nc = q.size();

if(nc == 0)
return height;

height++;

while(nc)
{

struct node * temp = q.front();
q.pop();
if(temp->left)
q.push(temp->left);
if(temp->right)
q.push(temp->right);
nc = nc-1;
}

}
return height;
}


// driver program to test indenticalTrees function
int main()
{

struct node * root1 = newNode(1);

root1->left = newNode(2);
root1->right = newNode(3);
struct node * root2 = newNode(1);

int s = getHeight(root1);
//int s2 = size(root2);
printf("%d\n",s);
//printf("%d\n",s2);



}

