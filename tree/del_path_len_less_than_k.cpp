// C++ program to remove nodes on root to leaf paths of length < K
#include<iostream>
using namespace std;
 
struct Node
{
    int data;
    Node *left, *right;
};
 
//New node of a tree
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}




struct Node * delPathLessThanKLength(struct Node *root,int level,int pathlen)
{

if(root == NULL)
return NULL;

root->left = delPathLessThanKLength(root->left,level+1,pathlen); 
root->right = delPathLessThanKLength(root->right,level+1,pathlen);


if(root->left == NULL && root->right == NULL && level < pathlen)
{
delete root;
return NULL;
}

return root;
}

//Method to print the tree in inorder fashion.
void printInorder(Node *root)
{
    if (root)
    {
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
}

// Driver method.
int main()
{
    int k = 4;
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(7);
    root->right->right = newNode(6);
    root->right->right->left = newNode(8);
    cout << "Inorder Traversal of Original tree" << endl;
    printInorder(root);
    cout << endl;
    cout << "Inorder Traversal of Modified tree" << endl;
    Node *res = delPathLessThanKLength(root,1,k);
    printInorder(res);
    return 0;
}
