

#include<stdio.h>
 
/* A tree node structure */
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
 

 void printBstRange(struct node *root,int n1,int n2)
{

if(root == NULL)
return;
 printBstRange(root->left,n1,n2);
if(root->data >= n1 && root->data <= n2)
printf("%d\t",root->data);
printBstRange(root->right,n1,n2);
}


/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
  struct node *temp = new struct node;
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
 
  return temp;
}
 
/* Driver function to test above functions */
int main()
{
  struct node *root = new struct node;
  int k1 = 10, k2 = 25;
 
  /* Constructing tree given in the above figure */
  root = newNode(20);
  root->left = newNode(8);
  root->right = newNode(22);
  root->left->left = newNode(4);
  root->left->right = newNode(12);
 
  printBstRange(root, k1, k2);
 
  getchar();
  return 0;
}
