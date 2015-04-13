#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<queue> 
/*  Tree node structure */
struct node
{
    int key;
    struct node *left, *right;
};
 
/* Helper function that allocates a new node with the
   given key and NULL left and right pointer. */
struct node *newNode(char k)
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->key = k;
    node->right = node->left = NULL;
    return node;
}







bool isFullBT(struct node * root)
{

if(root == NULL)
return true;

//if(root->left == NULL && root->right == NULL)
//return true

std::queue<struct node *>q;

q.push(root);
int flag = false;
while(!q.empty())
{

struct node * temp = q.front();
q.pop();

if(temp->left == NULL && temp->right == NULL)
flag = true;

if(temp->left && temp->right)
{
q.push(temp->left);
q.push(temp->right); 
}
if(!temp->left && temp->right || temp->left && !temp->right) 
{
flag = false;
break;
}
}

return flag;

}



// Driver Program
int main()
{
    struct node* root = NULL;
    root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
 
    root->left->right = newNode(40);
    root->left->left = newNode(50);
    root->right->left = newNode(60);
    root->right->right = newNode(70);
 
    root->left->left->left = newNode(80);
    root->left->left->right = newNode(90);
    root->left->right->left = newNode(80);
    root->left->right->right = newNode(90);
    root->right->left->left = newNode(80);
    root->right->left->right = newNode(90);
    root->right->right->left = newNode(80);
    root->right->right->right = newNode(90);
   // root->right->right->right->right = newNode(100);

 
    if (isFullBT(root))
        printf("The Binary Tree is full\n");
    else
        printf("The Binary Tree is not full\n");
 
    return(0);
}
