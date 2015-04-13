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

// Driver program to test the function

int main()
{

struct node *head = NULL;

push(&head,10);
push(&head,20);
push(&head,30);
push(&head,40);
push(&head,50);
push(&head,60);
printList(head);
}
