#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
void printList(struct node *ptr);

struct node * reverse(struct node * head)
{

struct node *curr = head;
struct node *prev = NULL;
struct node *cn = NULL;
while(curr != NULL)
{
cn = curr->next;
curr->next = prev;
prev = curr;
curr = cn;
}
return prev;
}


bool isPalindrome(struct node *head)
{

// empty list or list having only one element is palindrome
if(head == NULL || head->next == NULL)
return true;

// list having only two element and both element are same 

if(head->data == head->next->data && head->next->next == NULL)
return true;

if(head->data != head->next->data && head->next->next == NULL)
return false;

int c = 0;

struct node *temp = head;
// count the size of list
while(temp != NULL)
{
c = c+1;
temp = temp->next;
}
//printf("%d\t",c);

// break the list in two parts
struct node *slow = head;
struct node *fast = head;
struct node *prev = slow;
while(fast != NULL && fast->next != NULL)
{
prev = slow;
slow = slow->next;
fast = fast->next->next;
}

struct node *second = slow;
prev->next = NULL;
//printList(head);
//printList(second);

struct node *rev = reverse(second);
struct node *first = head;
second = rev;

if(c%2 == 0)
{
while(first != NULL && second != NULL)
{
if(first->data != second->data)
return false;
first = first->next;
second = second->next;
}
return true;
}
else
{

while(first->next != NULL && second != NULL)
{
if(first->data != second->data)
return false;
first = first->next;
second = second->next;
}
return true;
}
// combline the list
prev->next = reverse(rev);
}

/* Push a node to linked list. Note that this function
  changes the head */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to pochar to the new node */
    (*head_ref)    = new_node;
}
 
// A utility function to print a given linked list
void printList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
 
 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
      // push(&head,2);
push(&head,1);
push(&head,1);
push(&head,2);
push(&head,2);
push(&head,2);
push(&head,1);
push(&head,1);


	
       printList(head);
       isPalindrome(head)? printf("Is Palindrome\n\n"):
                           printf("Not Palindrome\n\n");
    
        printList(head);

    return 0;
}

