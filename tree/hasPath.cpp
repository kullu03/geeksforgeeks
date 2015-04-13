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

int hasPathSum(struct node *root,int sum)
{

if(root == NULL)
return (sum ==0);

//int subSum = sum-root->data;
else
{
int subSum = sum-root->data;

int ans = 0;

if(root->left == NULL && root->right == NULL && (subSum ==0))
return 1;

if(root->left)
ans = ans || hasPathSum(root->left,subSum);

if(root->right)
ans = ans || hasPathSum(root->right,subSum);

return ans;
}
}


// driver program to test indenticalTrees function
int main()
{

struct node * root1 = newNode(10);

root1->left = newNode(8);
root1->right = newNode(5);
root1->left->left = newNode(7);
root1->left->right = newNode(5);

int s = hasPathSum(root1,21);
printf("%d\t",s);
if(s)
printf("path with this sum exist");
else
{
printf("NO");
//int s2 = size(root2);
//printf("%d\n",s);
//printf("%d\n",s2);
}


}

