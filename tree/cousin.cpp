#include <stdio.h>
#include <stdlib.h>
 
// A Binary Tree Node
struct node
{
    int data;
    struct node *left, *right;
};
 
// A utility function to create a new Binary Tree Node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}


bool isSibling(struct node *root,struct node *a,struct node *b)
{

if(root == NULL)
return false;
//if(root->left == a && root->right == b || root->right == a && root->left == b)
//return true;
//return isSibling(root->left,a,b) || isSibling(root->right,a,b);
 return ((root->left==a && root->right==b)||
            (root->left==b && root->right==a)||
            isSibling(root->left, a, b)||
            isSibling(root->right, a, b));
}



int level(struct node *root,struct node *node,int l)
{

if(root == NULL)
return 0;

if(root == node)
return l;

int ll = level(root->left,node,l+1);
if( ll != 0)
return ll;


return level(root->right,node,l+1);
}





bool isCousin(struct node *root,struct node *node1,struct node * node2)
{

if(level(root,node1,1)==level(root,node2,1) && !isSibling(root,node1,node2))
return true;
else
return false;
}



// Driver Program to test above functions
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(15);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
 
    struct node *Node1,*Node2;
    Node1 = root->left->left;
    Node2 = root->right->right;
 
    isCousin(root,Node1,Node2)? puts("Yes"): puts("No");
 
    return 0;
}
