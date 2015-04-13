#include <stdio.h>
#include <stdlib.h>
#include<queue> 
// Binary Tree node
struct node
{
    int data;
    struct node* left, *right;
};
 
// A utility function to allocate a new tree node with given data
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left =  node->right = NULL;
    return (node);
}


int diff(struct node *root)
{
int oddSum = 0;
int evenSum = 0;
int level = 1;
std::queue<struct node *>q;
q.push(root);

while(!q.empty())
{

int s = q.size();

while(s > 0)
{

struct node *temp = q.front();
q.pop();

if(level%2 == 0)
evenSum = evenSum + temp->data;
else
oddSum = oddSum + temp->data;

if(temp->left)
q.push(temp->left);
if(temp->right)
q.push(temp->right);
s = s-1;
}
level = level+1;
}

return oddSum - evenSum;
}



// Driver program to test above functions
int main()
{
    struct node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left  = newNode(1);
    root->left->right = newNode(4);
    root->left->right->left = newNode(3);
    root->right->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(7);
    printf("%d is the required difference\n", diff(root));
    getchar();
    return 0;
}
