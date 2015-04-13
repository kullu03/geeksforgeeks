#include<stdio.h>
#include<malloc.h>
// node structure

struct node{
int data;
struct node *next;
};


struct node * newNode(int data)
{

struct node *temp = (struct node *)malloc(sizeof(struct node));
temp->next =NULL;
temp->data = data;
}

void push(struct node **head,int data)
{

struct node *new_node = newNode(data);
new_node->next = *head;
*head = new_node;
}

void printList(struct node * node)
{
if(node == NULL)
{
printf("List is empty\n");
return;
}
while(node != NULL)
{
printf("%d\t",node->data);
node = node->next;
}
}


struct node * iterative(struct node * node)
{
struct node *prev = node;
struct node * head = node->next;
struct node *temp = node->next->next;

while(node->next->next != NULL)
{

temp = node->next->next;
node->next->next = node;
if(temp->next == NULL)
node->next = temp;
else
node->next = temp->next;
node = temp;
//prev = node;
}
if(node->next->next == NULL)
{
node->next->next = node;
//if(temp->next == NULL)
//node->next = temp;
//else
node->next = NULL;}
return head;
}

struct node *pairSwap(struct node *head)
{

if(head == NULL || head->next == NULL)
return head;
struct node * temp = head->next->next;
struct node* newhead = head->next;
head->next->next = head;
head->next = pairSwap(temp);
return newhead;
}

struct node *last(struct node *head)
{
struct node * curr = head;
struct node * prev = head;
while(curr->next != NULL)
{

prev = curr;
curr = curr->next;
}
prev->next = NULL;
curr->next = head;
head = curr;
return head;
}

struct node * reverse(struct node **node)
{
struct node * prev = NULL;
struct node * curr = *node;
//if(curr->next == NULL || curr == NULL)
//return curr;
//else
//{
while(curr)
{
struct node *temp = curr->next;
curr->next = prev;
prev = curr;
curr  = temp;
}
//}
return prev;
}
// Driver program to test the function

struct node *recReverse(struct node * node)
{
if(node->next == NULL)
return node;
else
{



}

}

int main()
{

struct node *head = NULL;

push(&head,10);
push(&head,20);
push(&head,30);
push(&head,40);
push(&head,50);
push(&head,60);
push(&head,70);
//push(&head,80);
//push(&head,90);

printf("list before pairwise swap\n");
printList(head);
struct node * t = reverse(&head);
printf("list after pairwise swap\n");

printList(t);
}


