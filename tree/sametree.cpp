#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>


struct node {

int data;

struct node *left;

struct node *right;

};


// Helper function to create a tree node 

struct node * newNode(int data)
{

struct node * node = (struct node *)malloc(sizeof(struct node));

node->data = data;

node->left = NULL;

node->right = NULL;
return (node);
}

int indenticalTrees(struct node *a,struct node *b)
{

// return true if both tree are empty
if (a == NULL && b == NULL)
 return 1;

// if both trees are non empty
if(a != NULL && b != NULL)
{

return (a->data == b->data && indenticalTrees(a->left,b->left) && indenticalTrees(a->right, b->right));
}
// if only one is empty
else
{

return 0;
}
}
// driver program to test indenticalTrees function
int main()
{

struct node * root1 = newNode(1);

root1->left = newNode(2);
root1->right = newNode(3);
struct node * root2 = newNode(1);

if (indenticalTrees(root1,root2))
	printf("Both trees are indentical");
else
	printf("both trees are not same");


}
