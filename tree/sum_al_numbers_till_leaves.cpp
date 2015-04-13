// C program to find sum of all paths from root to leaves
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *left, *right;
};
 
// function to allocate new node with given data
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}


int sumOfAllNumbersOnLeavesPath(struct node * root,int val)
{

if(root == NULL)
return 0;

val = val * 10 + root->data;

if(root->left == NULL && root->right == NULL)
return val;

return sumOfAllNumbersOnLeavesPath(root->left,val) + sumOfAllNumbersOnLeavesPath(root->right,val);
}


// Driver function to test the above functions
int main()
{
    struct node *root = newNode(6);
    root->left        = newNode(3);
    root->right       = newNode(5);
    root->right->right= newNode(7);
    root->left->left  = newNode(2);
    root->left->right = newNode(5);
    root->right->right = newNode(4);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);
    printf("Sum of all paths is %d", sumOfAllNumbersOnLeavesPath(root,0));
    return 0;
}
