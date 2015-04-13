#include<stdio.h>
 
/* A tree node structure */
struct node
{
  int data;
  struct node *left;
  struct node *right;
};

int toSumTree(struct node *node)
{
    // Base case
    if(node == NULL)
      return 0;
 
    // Store the old value
    int old_val = node->data;
 
    // Recursively call for left and right subtrees and store the sum as
    // new value of this node
    node->data = toSumTree(node->left) + toSumTree(node->right);
 
    // Return the sum of values of nodes in left and right subtrees and
    // old_value of this node
    return node->data + old_val;
}

int tree_to_sum_tree(struct node *root)
{
if(root == NULL)
return 0;
int left=0;
int right =0;
if(root->left == NULL && root->right == NULL)
root->data =0;
else{
if(root->left)
  left = root->left->data;
if(root->right)
 right = root->right->data;
}
//root->data = left+right;
return root->data = left +right  + tree_to_sum_tree(root->left)+tree_to_sum_tree(root->right);

}


// A utility function to print inorder traversal of a Binary Tree
void printInorder(struct node* node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d ", node->data);
     printInorder(node->right);
}
 
/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
  struct node *temp = new struct node;
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
 
  return temp;
}
 
/* Driver function to test above functions */
int main()
{
  struct node *root = NULL;
  int x;
 
  /* Constructing tree given in the above figure */
  root = newNode(10);
  root->left = newNode(-2);
  root->right = newNode(6);
  root->left->left = newNode(8);
  root->left->right = newNode(-4);
  root->right->left = newNode(7);
  root->right->right = newNode(5);
root->left->left->left = newNode(1);
//root->left->left->right = newNode(2);
//root->left->right->left = newNode(3);
//root->left->right->right = newNode(4);
 
  toSumTree(root);
 
  // Print inorder traversal of the converted tree to test result of toSumTree()
  printf("Inorder Traversal of the resultant tree is: \n");
  printInorder(root);
 
  getchar();
  return 0;
}
