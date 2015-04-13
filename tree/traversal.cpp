#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
#include <queue>

struct node {

int data;

struct node *left;

struct node *right;

};


// Helper function to create a tree node 

struct node * newNode(int data)
{

struct node * node = (struct node *)malloc(sizeof(struct node));

node->data = data;

node->left = NULL;

node->right = NULL;
return (node);
}

void preorder_traversal(struct node *root)
{

if (root == NULL)
return;
else
{printf("%d\t",root->data);
preorder_traversal(root->left);
preorder_traversal(root->right);
}
}

void inorder_traversal(struct node *root)
{

if (root == NULL)
return;
else{
inorder_traversal(root->left);
printf("%d\t",root->data);
inorder_traversal(root->right);
}
}

void postorder_traversal(struct node *root)
{

if (root == NULL)
return;
else{
postorder_traversal(root->left);
postorder_traversal(root->right);
printf("%d\t",root->data);
}
}


void levelorder_traversal(struct node *root)
{

std::queue<struct node *> q; 
q.push(root);
//printf("root is pushed\n");
while(!q.empty())
{

struct node * t = q.front();
q.pop();
//printf("within while loop\n");
printf("%d\t",t->data);
if(t->left != NULL)
  {q.push(t->left);}
if (t->right != NULL)
{q.push(t->right);}
}



}







// driver program to test indenticalTrees function
int main()
{

struct node * root = newNode(1);

root->left = newNode(2);
root->right = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5);
root->right->left = newNode(6);
root->right->right = newNode(7);
printf("preorder traversal of tree\n");
preorder_traversal(root);
printf("postrder traversal of tree\n");
postorder_traversal(root);
printf("inorder traversal of tree\n");
inorder_traversal(root);
printf("level order traversal\n");
levelorder_traversal(root);

return 0;

}

