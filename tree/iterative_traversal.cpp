#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
#include <queue>
#include<stack>

struct node {

int data;

struct node *left;

struct node *right;

};


// Helper function to create a tree node 

struct node * newNode (int data)
{

struct node * node = (struct node *)malloc(sizeof(struct node));

node->data = data;

node->left = NULL;

node->right = NULL;
return (node);
}

void inorder_traversal(struct node *root)
{
struct node *temp=NULL;
if (root == NULL)
return;
std:: stack<struct node *>s;
s.push(root);
while(!s.empty())
{
root = root->left;
if(root != NULL)
s.push(root);

if(root == NULL)
{
root = s.top();
s.pop();
printf("%d\t",root->data);

if(root->right)
{
//printf("%d\t",s.top()->data);
//s.pop();
root = root->right;
s.push(root);

if(root->right->left)
root = root->right->left;
}

}

}
}

void preorder_traversal(struct node * root)
{



if(root == NULL)
return;
std::stack<struct node *>s;

s.push(root);
//printf("%d\t",root->data);
while(!s.empty())
{

struct node * temp = s.top();
s.pop();
printf("%d\t",temp->data);
if(temp->right)
s.push(temp->right);
if(temp->left)
s.push(temp->left);

}

}

/* iterative postorder traversal using 2 stacks */

void postorder_traversal(struct node * root)
{
if(root == NULL)
return ;

std::stack<struct node *>s1;
std::stack<struct node *>s2;
s1.push(root);
while(!s1.empty())
{
struct node * temp = s1.top();
s1.pop();
s2.push(temp);
if(temp->left)
s1.push(temp->left);
if(temp->right)
s1.push(temp->right);
}
while(!s2.empty())
{
printf("%d\t",s2.top()->data);
s2.pop();

}
}

/* Post order traversal using only one stack
 */
void postorder_traversal1(struct node * root)
{

std::stack<struct node *>s;
do{

while(root)
{
s.push(root->left);
s.push(root);
root = root->left;
}

root = s.top();
s.pop();

if(root->data && root->right->data == s.top()->data)
{
struct node *temp = s.top();
s.pop();
s.push(root);
root = temp->left;

}
else{

printf("%d\t",root->data);
root =NULL;

}
}
while(!s.empty());
}





// driver program to test indenticalTrees function
int main()
{

struct node * root = newNode(1);

//root->left = newNode(2);
root->right = newNode(2);
//root->left->left = newNode(4);
//root->left->right = newNode(5);
root->right->left = newNode(3);
root->right->right = newNode(4);
root->right->left->left = newNode(8);
root->right->left->left->right = newNode(9);
root->right->left->left->left = newNode(5);
root->right->right->right = newNode(6);
//printf("preorder traversal of tree\n");
//preorder_traversal(root);
//printf("postrder traversal of tree\n");
//postorder_traversal(root);
printf("inorder traversal of tree\n");
inorder_traversal(root);
//printf("level order traversal\n");
//levelorder_traversal(root);

return 0;

}

