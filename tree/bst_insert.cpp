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

int isSumProperty(struct node *root)
{
if(root->left == NULL && root->right == NULL)
return 0;
int l=0,r=0;
std::queue<struct node *> q; 
q.push(root);
//printf("root is pushed\n");
while(!q.empty())
{

struct node * t = q.front();
if(t->left == NULL && t->right == NULL)
return 1;
q.pop();
//printf("within while loop\n");
printf("root = %d\n",t->data);
if(t->left != NULL)
  {q.push(t->left);
	 l = t->left->data;
printf(" l= %d",l);
}
if (t->right != NULL)
{q.push(t->right);

 r = t->right->data;
printf(" r= %d",r);
}
if (t->data < l ||  r < t->data)
{
return 0;
}
else{l=0;r=0;}
}

return 1;

}

struct node* insert(struct node* node, int data)

{



struct node *n =  (newNode(data));



if (node == NULL)

return n;



struct node *temp = node;



while(temp)

{

if (data < temp->data)

{

if (temp->left == NULL)

{

temp->left = n;

break;

}

temp  = temp->left;

}

else if (data > temp->data)

{

if (temp->right == NULL)

{

temp->right = n;

break;

}

temp = temp->right;

}

else

break;

}



return node;

}
/*void insert(struct node *root,int data)
{
if(root == NULL)
 newNode(data);

struct node * temp = root;
while(temp!= NULL)
{

if(data <= temp->data)
temp = temp->left;
else
temp = temp->right;
}
temp = newNode(data);

//return root;
}*/

void inorder(struct node * root)
{

if(root == NULL)
return;
inorder(root->left);
printf("%d\t",root->data);
inorder(root->right);

}


// driver program to test indenticalTrees function
int main()
{

struct node * root = newNode(10);
struct node * n;
//root->left = newNode(8);
//root->right = newNode(22);
//root->left->left = newNode(5);
//root->left->right = newNode(9);
//root->right->left = newNode(2);
//root->right->right = newNode(2);
insert(root,22);
insert(root,26);
insert(root,8);
insert(root,12);
insert(root,9);
insert(root,6);
inorder(root);
//printf("%d\t",i);
//if(i)
//printf("BT satisfies Childern sum property\n");
//else
//printf("No Child sum property exist");

return 0;

}

