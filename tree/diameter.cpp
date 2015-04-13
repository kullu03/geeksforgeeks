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

/*                               

Diameter of tree is defined as maximum node between any two leaf.
*/
int getDiameter(struct node *root)
{

if(root == NULL)
return 0;

int lh = maxHeight(root->left);
int rh = maxHeight(root->right);

int ld = getDiameter(root->left);
int rd = getDiameter(root->right);


// if diameter goes through root node or whatever node we have given in the problem then daimeter is simply sum of (left height + right height +1) of tree. for this case
 // or we have to findout the sub tree which consist daimeter it may be left of root or right of root. 
return max((lh+rh+1),max(ld,rd));

}

// driver program to test indenticalTrees function
int main()
{

struct node * root1 = newNode(1);

root1->left = newNode(2);
root1->right = newNode(3);
struct node * root2 = newNode(1);

int s = getDiameter(root1);
//int s2 = size(root2);
printf("%d\n",s);
//printf("%d\n",s2);



}

