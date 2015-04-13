#include <stdio.h>
#include <stdlib.h>
 
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
 
/* This function is used to increment left subtree */
void increment(struct node* node, int diff);

void convertTree(struct node *node)
{

int left = 0;
int right = 0;
if(node == NULL || node->left == NULL && node->right == NULL)
return ;

else
{

convertTree(node->left);
convertTree(node->right);


if(node->left)
left = node->left->data;

if(node->right)
right = node->right->data;

int diff = left + right - node->data;

if(diff > 0)
node->data = node->data + diff;

if(diff < 0)
increment(node, -diff);

}
}


void increment(struct node * node ,int diff)
{

if(node->left != NULL)
{
node->left->data = node->left->data + diff;
increment(node->left,diff);
}

else if(node->right != NULL)
{
node->right->data = node->right->data + diff;
increment(node->right,diff);
}

}

/* Given a binary tree, printInorder() prints out its
   inorder traversal*/
void printInorder(struct node* node)
{
  if (node == NULL)
    return;
 
  /* first recur on left child */
  printInorder(node->left);
 
  /* then print the data of node */
  printf("%d ", node->data);
 
  /* now recur on right child */
  printInorder(node->right);
}
 
/* Helper function that allocates a new node
 with the given data and NULL left and right
 pointers. */
struct node* newNode(int data)
{
  struct node* node =
      (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
 
/* Driver program to test above functions */
int main()
{
  struct node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);
 
  printf("\n Inorder traversal before conversion ");
  printInorder(root);
 
  convertTree(root);
 
  printf("\n Inorder traversal after conversion ");
  printInorder(root);
 
  getchar();
  return 0;
}

