#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>




struct node {
char data ;

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

int search(char in[],char s,int ins,int ine)
{

for(int i = ins; i<= ine; i++)
{

if (in[i] == s)
return i;

}

}

struct node * buildTree(char in [],char pre[],int ins,int ine)
{

static int pi =0;
if(ins > ine)
return NULL;

char s = pre[pi];
pi++;
struct node * root = newNode(s);

if(ins == ine)
return root;

// search the preorder character index in inorder array

int inid = search(in,s,ins,ine);

root->left = buildTree(in,pre,ins,inid-1);
root->right = buildTree(in,pre,inid+1,ine);

return root;

}





void printInorder(struct node * root)
{
if(root == NULL)
return;
 printInorder(root->left);
printf("%c\t",root->data);
 printInorder(root->right);

}



// driver program to test indenticalTrees function
int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  struct node *root = buildTree(in, pre, 0, len - 1);
 
  /* Let us test the built tree by printing Insorder traversal */
  printf("\n Inorder traversal of the constructed tree is \n");
  printInorder(root);
  getchar();
}

