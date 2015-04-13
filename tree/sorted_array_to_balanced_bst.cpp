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



void preorder_traversal(struct node *root)
{

if (root == NULL)
return;
else
{printf("%d\t",root->data);
preorder_traversal(root->left);
preorder_traversal(root->right);
}
}






struct node * sortedArrayToBalancedBST(int arr[],int low,int high)
{


if(low> high)
return NULL;
struct node * root;
//int mid = (low+high)/2;

struct node;

if(low <= high)
{
int mid = (low+high)/2;

root = newNode(arr[mid]);

 root->left = sortedArrayToBalancedBST(arr,low,mid-1);
  root->right = sortedArrayToBalancedBST(arr,mid+1,high);

}
//struct node * root->right = sortedArrayToBalancedBST(arr,mid+1,high,int size);
return root;

}





/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    /* Convert List to BST */
    struct node *root = sortedArrayToBalancedBST(arr, 0, n-1);
    printf("\n PreOrder Traversal of constructed BST ");
    preorder_traversal(root);
 
    return 0;
}
