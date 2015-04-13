#define bool int

#define false 0
#define true 1

#define MIN 0

#define MAX 100


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
 

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

bool isBst(struct node * root,int min,int max )
{

if(root == NULL)
return true;

if(root->data < min || root->data > max)
return false;

return (isBst(root->left,min,root->data) && isBst(root->right,root->data,max));

}

int size (struct node *root)
{
if(root == NULL)
return 0;

else 
return (1+ size(root->left) + size(root->right));

}

int max(int a, int b)
{
if (a>b)
return a;
else
return b;

}

int getLargestBst(struct node * root)
{
if(isBst(root,MIN,MAX))
return(size(root));
return max(getLargestBst(root->left),getLargestBst(root->right));


}


/* Driver program to test above functions*/
int main()
{
    /* Let us construct the following Tree
          50
       /      \
     10        60
    /  \       /  \
   5   20    55    70
            /     /  \
          45     65    80
  */
 
  struct node *root = newNode(50);
  root->left        = newNode(10);
  root->right       = newNode(60);
  root->left->left  = newNode(5);
  root->left->right = newNode(20);
  root->right->left  = newNode(55);
  root->right->left->left  = newNode(45);
  root->right->right = newNode(70);
  root->right->right->left = newNode(65);
  root->right->right->right = newNode(80);
 
  /* The complete tree is not BST as 45 is in right subtree of 50.
     The following subtree is the largest BST
        60
      /  \
    55    70
   /     /  \
 45     65    80
  */
  printf(" Size of the largest BST is %d", getLargestBst(root));
 
  getchar();
  return 0;
}
