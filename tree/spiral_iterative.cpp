#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<stack>
#include<queue>

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


void spiral(struct node * root)
{

std::queue<struct node *>q;
std::stack<struct node *>s;
if(root == NULL)
printf("tree is empty\n");
q.push(root);
struct node * temp;
bool flag = false;
 int si = 0;
while(!q.empty())
{
 si = q.size();
//printf("hi---%d",si);
while(si > 0 && flag)
{
temp = q.front();
q.pop();
s.push(temp);
si = si - 1;
if(temp->left)
q.push(temp->left);
if(temp->right)
q.push(temp->right);
}

while(!s.empty())
{
struct node * t = s.top();
s.pop();
printf("%d\t",t->data);
}

//level = level+1;

while(si > 0 && flag == false)
{
temp = q.front();
q.pop();
printf("%d\t",temp->data);
if(temp->left)
q.push(temp->left);
if(temp->right)
q.push(temp->right);
si=si-1;
}
flag = !flag;
}
}



int main()
{

struct node * root1 = newNode(1);

root1->left = newNode(2);
root1->right = newNode(3);
root1->left->left = newNode(4);
root1->left->right = newNode(5);
root1->right->left = newNode(6);
root1->right->right = newNode(7);
root1->left->left->left = newNode(8);
root1->left->left->right = newNode(9);
root1->left->right->left = newNode(10);
root1->left->right->right = newNode(11);
root1->right->left->left = newNode(12);
root1->right->left->right = newNode(13);
root1->right->right->left = newNode(14);
root1->right->right->right = newNode(15);



 spiral(root1);
//int s2 = si(root2);
//printf("%d\n",s);
//printf("%d\n",s2);



}

