// Question given a key in a BT. We have to find out closet key in the tree with respect to given key.
// Idea: idea is simple the closet leaf will exist in either in ancesstor on or in decentants. We compare both values from ancesstor and decendant. What ever is min we return that value.

// A C++ program to find the closesr leaf of a given key in Binary Tree
#include <iostream>
#include <climits>
#include<stdio.h>
using namespace std;
 
/* A binary tree Node has key, pocharer to left and right children */
struct node
{
    char data;
    struct node* left, *right;
};
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pocharers. */
struct node *newNode(char k)
{
    struct node *temp = new node;
    temp->data = k;
    temp->right =  temp->left = NULL;
    return temp;
}

int findUtils(struct node *root,struct node * ancesstor[], int index,int key);
int getMin(int a,int b)
{
return (a < b)?a:b;
}

int findClosest(struct node *root, char k)
{
    // Create an array to store ancestors
    // Assumptiom: Maximum height of tree is 100
    struct node *ancestors[100];
 
    return findUtils(root,ancestors,0,k);
}
int closetDown(struct node * root)
{
if(root == NULL)
return INT_MAX;

if(root->left == NULL && root->right == NULL)
return 0;

return 1 + getMin(closetDown(root->left),closetDown(root->right));

}

int findUtils(struct node *root,struct node * ancesstor[], int index,int key)
{

// Base case
    if (root == NULL)
        return INT_MAX;

if(key == root->data)
{

int res =  closetDown(root);

for(int i = index -1 ; i >= 0 ; i--)

res = getMin(res,index-i+closetDown(ancesstor[i]));
printf(" leaf ====%c\n",ancesstor[index]->data);
return res;
}

ancesstor[index] = root;

return getMin(findUtils(root->left,ancesstor,index+1,key),findUtils(root->right,ancesstor,index+1,key));

}

/* Driver program to test above functions*/
int main()
{
    // Let us construct the BST shown in the above figure
    struct node *root        = newNode('A');
    root->left               = newNode('B');
    root->right              = newNode('C');
    root->right->left        = newNode('E');
    root->right->right       = newNode('F');
    root->right->left->left  = newNode('G');
    root->right->left->left->left  = newNode('I');
    root->right->left->left->right = newNode('J');
    root->right->right->right      = newNode('H');
    root->right->right->right->left = newNode('K');
 
    char k = 'H';
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
    k = 'C';
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
    k = 'E';
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
    k = 'B';
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
 
    return 0;
}
