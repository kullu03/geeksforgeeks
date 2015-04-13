#define true 1
#define false 0
#define bool int
#include<stdio.h>
#include<malloc.h>
/* A binary tree node has data, left child and right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node =
        (struct node*)malloc(sizeof(struct node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    return(node);
}
 





bool areIdentical(struct node *t,struct node *s)
{
    /* base cases */
if (t == NULL && s == NULL)
        return true;
 
if (t == NULL || s == NULL)
        return false;
if(t->data != s->data)
return false;

return areIdentical(t->left,s->left) && areIdentical(t->right,s->right);

}




bool isSubTree(struct node *t,struct node *s)
{

if(s == NULL)
return true;

if(t == NULL)
return false;

if(areIdentical(t,s))
return true;

return isSubTree(t->left,s->left) || isSubTree(t->right,s->right);

}


/* Driver program to test above function */
int main()
{
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
 
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    struct node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);
 
 
    if (isSubTree(T, S))
        printf("Tree S is subtree of tree T");
    else
        printf("Tree S is not a subtree of tree T");
 
    getchar();
    return 0;
}
