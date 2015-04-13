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

void _deleteTree(struct node* node)
{
  if (node == NULL)
    return;

  _deleteTree(node->left);
  _deleteTree(node->right);
  printf("%d ", node->data);
  free(node);

}


/* Deletes a tree and sets the root as NULL */
void deleteTree(struct node** node_ref)
{
  _deleteTree(*node_ref);
  *node_ref = NULL;
}

/*void _deleteTree(struct node* node)
{
  if (node == NULL)
    return;
   
  _deleteTree(node->left);
  _deleteTree(node->right);
  printf("%d ", node->data);
  free(node);

}*/



// driver program to test indenticalTrees function
int main()
{

struct node * root1 = newNode(1);
//struct node ** n = root1;
root1->left = newNode(2);
root1->right = newNode(3);
root1->left->left = newNode(4);
root1->left->right = newNode(5);
root1->right->left = newNode(6);
root1->right->right = newNode(7);

deleteTree(&root1);
//mirrorTree(root1);
//inOrder(root1);

//int s2 = size(root2);
//printf("%d\n",s);
//printf("%d\n",s2);

//post_order(root1);


}

