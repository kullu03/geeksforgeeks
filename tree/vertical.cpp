// vertical order of tree is based on the principal of HD(horizontal distance). HD for root is 0 and left chils is -1 and right chils is +1

// vertical order is all about printing all node once at same horizontal distance from root.
// C++ program for printing vertical order of a given binary tree
#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
// Structure for a binary tree node
struct Node
{
    int key;
    Node *left, *right;
};
 
// A utility function to create a new node
struct Node* newNode(int key)
{
    struct Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}



void getVerticalOrder(Node* root, int hd, map<int, vector<int> > &m)
{
    // Base case
    if (root == NULL)
        return;
 
    // Store current node in map 'm'
    m[hd].push_back(root->key);
 
    // Store nodes in left subtree
    getVerticalOrder(root->left, hd-1, m);
 
    // Store nodes in right subtree
    getVerticalOrder(root->right, hd+1, m);
}


void printVerticalOrder(struct Node *root)
{
map < int,vector<int> > m;

int hd = 0;

getVerticalOrder(root, hd,m);

    // Traverse the map and print nodes at every horigontal
    // distance (hd)
    map< int,vector<int> > :: iterator it;
    for (it=m.begin(); it!=m.end(); it++)
    {
       cout << it->second[0] << " ";
        cout << endl;
    }
}

// Driver program to test above functions
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right = newNode(6);
    //root->right->right = newNode(7);
    //root->right->left->right = newNode(8);
    //root->right->right->right = newNode(9);
    //cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}
