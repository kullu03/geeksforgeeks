#include<stdio.h>
#include<malloc.h>


struct node {
int data;
struct node *left;
struct node *right;
};

struct node * newNode(int data)
{

struct node *temp = (struct node *)malloc(sizeof(struct node));
temp->data = data;
temp->left = NULL;
temp->right = NULL;
return temp;
}

bool visit(struct node * root)
{
if(root == NULL)
return false;
if(root->left == NULL && root->right == NULL)
return true;
else if(root->left != NULL && root->right != NULL)
return false;
if(root->left)
visit(root->left);
if(root->right)
visit(root->left);
return true;
}


struct node * buildBst(int arr[],int * preindex,int low,int high,int size)
{

if(*preindex > size || low >high)
return NULL;
struct node *root = newNode(arr[*preindex]);
*preindex = *preindex + 1;

// if current subarray has only one element.No need to recur
if(low == high)
return root;
int i;
for(i = low ; i <= high; ++i)
{
if(root->data < arr[i])
break;
}
root->left = buildBst(arr,preindex,*preindex,i-1,size);
root->right = buildBst(arr,preindex,i,high,size);
return root;

}
void preorder(struct node *temp)
{
if(temp == NULL)
return;
else
{
printf("%d\t",temp->data);
preorder(temp->left);
preorder(temp->right);
}

}

void isOnlyChild(int arr[],int low,int size)
{
//int mid = 0;
int p =0;
int high = size-1;
 struct node * temp = buildBst(arr,&p,low,high,size);
printf("Preorder traversal:\n");
preorder(temp);

bool t = visit(temp);
if(t)
printf("Yes only one child\n");
else
printf("having more than one child\n");

}


int main()
{

int arr[]={10,5,1,7,40,50};
//int *p = arr[0];
 isOnlyChild(arr,0,5);
return 0;


}


