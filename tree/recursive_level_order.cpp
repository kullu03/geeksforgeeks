#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

int printGivenLevel(struct node *root,int level,int sum);
void spiral(struct node *root,int level,bool flag);
int max(int a,int b)
{
if(a>=b)
return a;
else
return b;
}


int getHeight(struct node *root)
{
if(root == NULL)
return 0;
return 1+ max(getHeight(root->left),getHeight(root->right));
}


void printLevelOrder(struct node * root)
{

int height = getHeight(root);
printf("H=%d\t",height);
bool flag = false;
for(int i = 1; i<= height;i++)
{
if(i%2 != 0)
flag = true;
else 
flag = false;
spiral(root,i,flag);

}
}
void spiral(struct node *root,int level,bool flag)
{

if(root == NULL)
return ;
if(level == 1)
{
printf("%d\t",root->data);
return;
}

else if(flag == true && level >1)
{
spiral(root->left,level-1,flag);
spiral(root->right,level-1,flag);
}
else if(flag == false && level >1)
{

spiral(root->right,level-1,flag);
spiral(root->left,level-1,flag);


}

}


int printGivenLevel(struct node *root,int level,int sum)
{

if(root == NULL)
return 0;

//sum = sum + root->

//sum = l+r;
//printf("%d\t",sum);

if(level == 1)
{

//sum = root->data + sum;
return root->data;
//printf("%d\t",sum);
}

else
{
return printGivenLevel(root->left,level-1,0) + printGivenLevel(root->right,level-1,0);

//printGivenLevel(root->right,level-1,sum);
}
}


/* Driver program to test above functions*/
int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left  = newNode(11);
  root->left->left->right  = newNode(14);
 
  printf("Level Order traversal of binary tree is \n");
  printLevelOrder(root);
 
  getchar();
  return 0;
}
