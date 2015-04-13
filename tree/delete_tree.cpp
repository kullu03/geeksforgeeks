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



void inOrder(struct node* node)
{
  if (node == NULL)
    return;
   
  inOrder(node->left);
  printf("%d ", node->data);
 
  inOrder(node->right);
}

void  mirrorTree(struct node *root)
{

if (root == NULL)
return ;

struct node * t;
t = root->left;
root->left = root->right;
root->right = t;

mirrorTree(root->left);
mirrorTree(root->right);

}




// driver program to test indenticalTrees function
int main()
{

struct node * root1 = newNode(1);

root1->left = newNode(2);
root1->right = newNode(3);
root1->left->left = newNode(4);
root1->left->right = newNode(5);
root1->right->left = newNode(6);
root1->right->right = newNode(7);

inOrder(root1);
mirrorTree(root1);
inOrder(root1);

//int s2 = size(root2);
//printf("%d\n",s);
//printf("%d\n",s2);



}

