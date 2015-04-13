/* Program to check if a linked list is palindrome */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
/* Link list node */
struct node
{
    char data;
    struct node* next;
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


struct node * reverse(struct node *node)
{

if(node->next == NULL || node == NULL)  
return node;
struct node * prev = NULL;
struct node * curr = node;

while(curr)
{
struct node *temp = curr->next;
curr->next = prev;
prev = curr;
curr  = temp;
}
return prev;
}



bool isPalindrome(struct node *head)
{

if(head->next == NULL || head == NULL)
return true;

struct node * slow = head;
struct node * fast = head;
struct node * mid = NULL;
struct node * prevslow = head;
// move the slow pointer to the middle of the list
while(fast != NULL && fast->next != NULL) 
{
prevslow = slow;
slow = slow->next;
fast = fast->next->next;
}
if(fast != NULL)
mid = prevslow;
else
mid = slow;

struct node * second = reverse(mid);
struct node * first = head;
while(second)
{
if(first->data != second->data)
return false;
first = first->next;
second = second->next;
}
return true;
}
// A utility function to print a given linked list
void printList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%c->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
 
 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    char str[] = "abab";
    int i;
 
    for (i = 0; str[i] != '\0'; i++)
    {
       push(&head, str[i]);
       //printList(head);
       //isPalindrome(head)? printf("Is Palindrome\n\n"):
         //                  printf("Not Palindrome\n\n");
    }
 
if(isPalindrome(head))
printf("Yes");
else
printf("NO");


    return 0;
}
