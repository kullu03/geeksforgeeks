#include <stdio.h>
#include <stdlib.h>
#include<queue> 
// A binary tree node
struct node
{
    int data;
     int dis;
    struct node *left, *right;
};
 
// A utility function to allocate a new tree node
struct node* newNode(int data)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    node->dis = 0;
    return node;
}



bool allLeavesAtSameLevel(struct node *root)
{
int static d = 0;
int flag = false;
if(root == NULL)
return true;

std:: queue<struct node *>q;

q.push(root);

while(!q.empty())
{

int s = q.size();

while(s>0)
{

struct node *temp = q.front();
printf("%d\t : %d\t",temp->data,temp->dis);
q.pop();

// first time we saw the leaf node 
if(temp->left == NULL && temp->right == NULL && flag == false)
{
d = temp->dis;
flag = true;
}

if(temp->left == NULL && temp->right == NULL && temp->dis != d)
{

return false;

}


if(temp->left)
{
temp->left->dis = temp->dis +1;
q.push(temp->left);
}
if(temp->right)
{
temp->right->dis = temp->dis +1;
q.push(temp->right);

}
s = s-1;
}

}
if (q.empty()== true)
return flag;

}

bool check(struct node *root)
{
static int d = 0;
bool flag = false;
if(root == NULL)
return true;
std::queue<struct node *>nq;
std::queue<int>lq;
nq.push(root);
lq.push(0);
while(!nq.empty())
{

struct node *temp = nq.front();
nq.pop();
int l = lq.front();
lq.pop();

// We see first time leaf 
if(temp->left == NULL && temp->right == NULL && flag == false)
{
d = l;
flag = true;
}

if(temp->left)
{
nq.push(temp->left);
lq.push(l+1);
}

if(temp->right)
{
nq.push(temp->right);
lq.push(l+1);
}

if(temp->left == NULL && temp->right == NULL && l != d)
return false;
}
return true;
}


// Driver program to test above function
int main()
{
    // Let us create tree shown in thirdt example
    struct node *root = newNode(12);
    root->left = newNode(5);
    root->right = newNode(25);

    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
    if (check(root))
        printf("Leaves are at same level\n");
    else
        printf("Leaves are not at same level\n");
    getchar();
    return 0;
}

