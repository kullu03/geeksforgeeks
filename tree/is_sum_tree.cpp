


#include<stdio.h>
#include<stack>

 
/* A tree node structure */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
 
    return temp;
}


bool isSumProperty(struct node *root)
{
int l = 0;
int r = 0;
if(root == NULL)
return true;

if(root->left == NULL && root->right == NULL)
return true;
if(root->left)
l = root->left->data;
if(root->right)
r = root->right->data;
if(root->data != (l+r))
return false;

return isSumProperty(root->left) && isSumProperty(root->right);



}
int getLevel(struct node * root,int level,int data)
{
if(root == NULL)
return 0;

if(root->data == data)
return level;

getLevel(root->left,level+1,data) || getLevel(root->right,level+1, data);

}

int getLevelIterative(struct node * root,int data)
{

std::stack<struct node *>s;
std::stack<int>ls;
s.push(root);
int level = 1;
ls.push(level);
while(!s.empty())
{

struct node * temp = s.top();
if(!ls.empty())
{
level = ls.top();
ls.pop();
}
s.pop();
if(temp->data == data)
return level;
level = level +1;
if(temp->left)
s.push(temp->left);
if(temp->left || temp->right)
ls.push(level);
if(temp->right)
s.push(temp->right);

}



}

/* Driver function to test above functions */
int main()
{
    struct node *root = new struct node;
    int x;
 
    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);
 
   
      bool b = isSumProperty(root);
      if (b)
        printf(" Yes");
      else
        printf("No");
 
    
 
    getchar();
    return 0;
}
