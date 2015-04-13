#include <stdio.h>
#include <stdlib.h>
 
/* structure of a linked list node */
struct node
{
     int data;
     struct node *next;
};
struct node * reverse(struct node * root);

struct node *del(struct node *root)
{
if(root == NULL)
return NULL;
struct node * t = reverse(root);

struct node *max = t;
struct node *curr = t;
//struct node * prev = t;
struct node *temp = NULL;
while( curr != NULL && curr->next != NULL)
{
if(curr->next->data < max->data)
{
temp = curr->next;
curr->next = temp->next;
delete temp;
}
else
{
curr = curr->next;
max = curr;
}
}
return reverse(t);
}
struct node * reverse(struct node * root)
{
if(root == NULL)
return NULL;

if(root->next == NULL)
return root;

struct node *curr = root;
struct node *prev = NULL;
struct node *currNext = NULL;

while(curr != NULL)
{
currNext = curr->next;
curr->next = prev;
prev = curr;
curr = currNext;
}
return prev;
}

/* Utility function to insert a node at the begining */
void push(struct node **head_ref, int new_data)
{
     struct node *new_node =
              (struct node *)malloc(sizeof(struct node));
     new_node->data = new_data;
     new_node->next = *head_ref;
     *head_ref = new_node;
}

/* Utility function to print a linked list */
void printList(struct node *head)
{
     while(head!=NULL)
     {
        printf("%d ",head->data);
        head=head->next;
     }
     printf("\n");
}

/* Driver program to test above functions */
int main()
{
    struct node *head = NULL;
 
    /* Create following linked list
      12->15->10->11->5->6->2->3 */
    push(&head,3);
    push(&head,2);
    push(&head,6);
    push(&head,5);
    push(&head,11);
    push(&head,10);
    push(&head,15);
    push(&head,12);
 
    printf("Given Linked List: ");
    printList(head);
 
struct node * t =     del(head);
 
    printf("\nModified Linked List: ");
    printList(t);
 
    getchar();
    return 0;
}

