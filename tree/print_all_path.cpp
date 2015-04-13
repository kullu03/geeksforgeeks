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

void printArray(int arr[],int len)
{
int i;

for(i =0;i<len;i++)
printf("%d\t",arr[i]);

printf("\n");


}

/*void printUtility(struct node *root)
{

int path[1000];
int pathlen =0;
 printPaths(root,path,pathlen);



} */
void printPaths(struct node *root,int path[], int pathlen)
{

if (root == NULL)
return ;
path[pathlen] = root->data;
pathlen = pathlen+1;

if(root->left == NULL && root->right == NULL)
printArray(path,pathlen);

else
{

printPaths(root->left,path,pathlen);
printPaths(root->right,path,pathlen);

}

}

void printUtility(struct node *root)
{

int path[1000];
int pathlen =0;
 printPaths(root,path,pathlen);



}



// driver program to test indenticalTrees function
int main()
{

struct node * root1 = newNode(1);

root1->left = newNode(2);
root1->right = newNode(3);
root1->left->left = newNode(4);
root1->left->right = newNode(5);

 printUtility(root1);
//int s2 = size(root2);
//printf("%d\n",s);
//printf("%d\n",s2);



}

