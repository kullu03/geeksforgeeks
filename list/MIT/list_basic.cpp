#include<stdio.h>
#include<malloc.h>
// Node of a linked list

struct node {
int data;
struct node *next;
};

// utility function to get the length of list
int length(struct node * head)
{
if(head == NULL)
return 0;
int len = 0;
while(head)
{
len = len +1;
printf("%d\t",head->data);
head = head->next;
}
return len;
}

// utility fuction to make a list {1,2,3}
struct node* BuildOneTwoThree()
{

struct node *head = (struct node *)malloc(sizeof(struct node));
head->data = 1;
head->next = (struct node *)malloc(sizeof(struct node));
head->next->data = 2;
head->next->next = (struct node *)malloc(sizeof(struct node));
head->next->next->data = 3;
head->next->next->next = NULL;
return head;
}
//utility to create a node

struct node * newNode(int data)
{
struct node *temp = (struct node *)malloc(sizeof(struct node));
temp->data = data;
temp->next = NULL;
return temp;
}

// utility function to add a node starting of the linklist
void Push(struct node** headRef, int newData)
{
if(*headRef == NULL)
	*headRef = newNode(newData);
else
{
struct node* temp = newNode(newData);
temp->next = *headRef;
*headRef = temp;
}
}

// driver program to test
void BasicsCaller() {
struct node* head;
int len;
head = BuildOneTwoThree(); // Start with {1, 2, 3}
Push(&head, 13); 
Push(&(head->next), 42); 
len = length(head); 
printf("len = %d\t",len);
}

int main()
{

BasicsCaller();
return 0;


}
