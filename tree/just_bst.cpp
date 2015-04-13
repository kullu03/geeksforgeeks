#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int minValue(struct node *temp)
{
while(temp->left)
temp = temp->left;

return temp->data;
}

int maxValue(struct node *temp)
{

while(temp->right)
temp = temp->right;
return temp->data;
}




bool isBst(struct node *root)
{
if(root == NULL)
return true;

if(root->left != NULL && root->data < maxValue(root->left))
return false;

if(root->right != NULL &&  minValue(root->right) < root->data)
return false;

if(!isBst(root->left) || !isBst(root->right))
return false;

return true;
}



struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
/* Driver program to test above functions*/
int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(92);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3);
 
  if(isBst(root))
    printf("Is BST");
  else
    printf("Not a BST");
     
  getchar();
  return 0;
}
