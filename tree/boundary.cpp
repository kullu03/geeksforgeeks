/* program for boundary traversal of a binary tree */
#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node *left, *right;
};
// A utility function to create a node
struct node* newNode( int data )
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}

void printLeft(struct node *root)
{
if(root == NULL)
return;
if(root->left)
{
printf("%d\t",root->data);
printLeft(root->left);
}
else if(root->right)
{

printf("%d\t",root->data);
printLeft(root->right);

}

}

void printLeaves(struct node *root)
{
if(root == NULL)
return;

printLeaves(root->left);
if(root->left == NULL && root->right == NULL)
printf("%d\t",root->data);
printLeaves(root->right);
}


void printRight(struct node *root)
{
if(root == NULL)
return;
if(root->right)
{
printRight(root->right);
printf("%d\t",root->data);
}

else if(root->left)
{
printRight(root->left);
printf("%d\t",root->data);

}
}

void boundaryTraversal(struct node *root)
{
if(root == NULL)
return;

// print root

printf("%d\t",root->data);

// print left part including root
printLeft(root->left);

// print leaves
struct node * t = root;
printLeaves(t);

// print right part of the tree
struct node * r = root;
printRight(r);
}

// Driver program to test above functions
int main()
{
    // Let us construct the tree given in the above diagram
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
 
    boundaryTraversal( root );
 
    return 0;
}
