#include <stdio.h>
#include <stdlib.h>
#include<queue> 
// Structure for tree and linked list
struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function for allocating node for Binary Tree.
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
// Utility function for printing tree in In-Order.
void print(struct Node *root)
{
    if (root != NULL)
    {
         print(root->left);
         printf("%d ",root->data);
         print(root->right);
    }
}




struct Node* extractLeafList(struct Node *root, struct Node **head_ref)
{
   // Base cases
   if (root == NULL)  return NULL;
 
   if (root->left == NULL && root->right == NULL)
   {
       // This node is going to be added to doubly linked list
       // of leaves, set right pointer of this node as previous
       // head of DLL. We don't need to set left pointer as left
       // is already NULL
       root->right = *head_ref;
 
       // Change left pointer of previous head
       if (*head_ref != NULL) (*head_ref)->left = root;
 
       // Change head of linked list
       *head_ref = root;
 
       return NULL;  // Return new root
   }
 
   // Recur for right and left subtrees
   root->right = extractLeafList(root->right, head_ref);
   root->left  = extractLeafList(root->left, head_ref);
 
   return root;
}
struct Node * extractLeafNodes(struct Node *root,struct Node **head)
{
//std::queue<struct Node *>q;

if(root == NULL)
return NULL;
extractLeafNodes(root->left,head);

//extractLeafNodes(root->left,head);
if(root->left == NULL && root->right == NULL)
{
       root->right = *head;
 
       // Change left pointer of previous head
       if (*head != NULL) (*head)->left = root;
 
       // Change head of linked list
       *head = root;
 
       return NULL;  // Return new root
}
extractLeafNodes(root->right,head);
//extractLeafNodes(root->left,head);
return root;
}


// Driver program to test above function
int main()
{
     struct Node *head = NULL;
     struct Node *root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     root->right->right = newNode(6);
     root->left->left->left = newNode(7);
     root->left->left->right = newNode(8);
     root->right->right->left = newNode(9);
     root->right->right->right = newNode(10);
 
     printf("Inorder Trvaersal of given Tree is:\n");
     print(root);
 
     root = extractLeafList(root,&head);
 
     printf("\nExtracted Double Linked list is:\n");
     //printList(head);
 
     printf("\nInorder traversal of modified tree is:\n");
    print(root);
     return 0;
}
