#include <iostream>
#include<stdio.h>
#include<malloc.h>
#include<vector>
using namespace std;

// BST node structure
struct node{
	int data;
	struct node *left;
	struct node *right;
};

// Helper function to create a new BST node
struct node *newNode(int data)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

vector<int > printPath(struct node *node,int key,vector<int>& path)
{
	//if(node == NULL)
	//return ;
	if(node->data == key)
	return path;
	if(key < node->data)
	{      if(node->left)
{
		path.push_back(1);
		return printPath(node->left,key,path);
	}}
	else
        {
	if(node->right)
	{
	path.push_back(0);
	return printPath(node->right,key,path);
	}
} 
	//if onoe of the above
	return *path.push_back(-1);
}

// Driver program to test above function
int main()
{
    /* Create following BST
              5
            /   \
           2     13  */
    node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(13);
   vector<int> v; 
   vector<int> vec = printPath(root,2,v);
   //vector<int>::iterator v = vec.begin();
   //while( v != vec.end()) {
     // std::cout << "value of v = " << *v << endl;
      //v++;
   //}
 
    return 0;
}
