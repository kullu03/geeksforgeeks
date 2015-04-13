#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>




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

/* Function to find LCA of n1 and n2. The function assumes that both
   n1 and n2 are present in BST */
struct node *lca(struct node* root, int n1, int n2)
{
    if (root == NULL) return NULL;
 
    // If both n1 and n2 are smaller than root, then LCA lies in left
    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);
 
    // If both n1 and n2 are greater than root, then LCA lies in right
    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);
 
    return root;
}


// driver program to test indenticalTrees function
int main()
{

struct node * root1 = newNode(1);

root1->left = newNode(2);
root1->right = newNode(3);
struct node * root2 = newNode(1);

int s = maxHeight(root1);
//int s2 = size(root2);
printf("%d\n",s);
//printf("%d\n",s2);



}

