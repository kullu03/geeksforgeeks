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

int max(int a,int b)
{

if(a>=b)
return a;
else
return b;

}

int maxHeight(struct node *root)
{

if (root == NULL)
return 0;
if(root->left == NULL && root->right == NULL)
return 1;

else
return (1+ max(maxHeight(root->left),maxHeight(root->right)));

}

int isAVLTree(struct node * root)
{

if(root == NULL)
return 1;
if((abs(maxHeight(root->left) - maxHeight(root->right))>1))

return 0;
else
return isAVLTree(root->left)&& isAVLTree(root->right);


}





// driver program to test indenticalTrees function
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    //root->left->right = newNode(5);
    //root->left->left->left = newNode(8);
 
    if(isAVLTree(root))
      printf("Tree is balanced");
    else
      printf("Tree is not balanced");   
 
    getchar();
    return 0;
}

