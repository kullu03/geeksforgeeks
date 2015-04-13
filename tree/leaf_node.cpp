#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<stack>

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

int leafCount(struct node *root)
{

if (root == NULL)
return 0;
if(root->left == NULL && root->right == NULL)
return 1;

else
return (leafCount(root->left)+leafCount(root->right));

}

void spiralPrint(struct node * node)
{

if(node == NULL)
return ;

std::stack<struct node*>S1;
std::stack<struct node*>S2;

S1.push(node);

while((!S1.empty()) || (!S2.empty()))
{


while(!S1.empty())
{

struct node * t = S1.top();
S1.pop();
printf("%d\t",t->data);

if(t->right)
S2.push(t->right);
if(t->left)
S2.push(t->left);
}

while(!S2.empty())
{

struct node * t = S2.top();
S2.pop();
printf("%d\t",t->data);
if(t->left)
S1.push(t->left);
if(t->right)
S1.push(t->right);
}
}
}




// driver program to test indenticalTrees function
int main()
{

struct node * root1 = newNode(1);

root1->left = newNode(2);
root1->right = newNode(3);
root1->left->left = newNode(4);
root1->left->right = newNode(5);
root1->left->left->left = newNode(6);
root1->left->left->right = newNode(7);


int s=  leafCount(root1);
//int s2 = size(root2);
printf("%d\n",s);
//printf("%d\n",s2);



}

