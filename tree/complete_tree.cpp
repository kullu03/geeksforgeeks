
/* C program to checks if a binary tree complete ot not */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
/*  Tree node structure */
struct node
{
    int key;
    struct node *left, *right;
};
 
/* Helper function that allocates a new node with the
   given key and NULL left and right pointer. */
struct node *newNode(char k)
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->key = k;
    node->right = node->left = NULL;
    return node;
}
 
/* This function counts the number of nodes in a binary tree */
unsigned int countNodes(struct node* root)
{
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}

bool isCompleteTree(struct node * root,unsigned int i ,unsigned int size)
{
if(root == NULL)
return true;
if(i >= size)
return false;


return  (isCompleteTree(root->left,2*i+1 , size) && isCompleteTree(root->right,2*i+2,size));


}



// Driver program
int main()
{
    // Le us create tree in the last diagram above
    struct node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    //root->right->right->right = newNode(67);
 
    unsigned int node_count = countNodes(root);
    unsigned int index = 0;
 
    if (isCompleteTree(root, index, node_count))
        printf("The Binary Tree is complete\n");
    else
        printf("The Binary Tree is not complete\n");
    return (0);
}



