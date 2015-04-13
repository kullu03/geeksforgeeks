#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
struct node *kAltReverse(struct node *head,int k)
{
if(head == NULL)
return NULL;

struct node *prev = NULL;
struct node *curr = head;
struct node *cn = NULL;
int c = 0;
while(curr != NULL && c < k)
{
cn = curr->next;
curr->next = prev;
prev = curr;
curr = cn;
c = c+1;
}
c =0;
if(curr != NULL)
head->next = curr;
printf("cuu== %d\n",curr->data);
// skip the k node

while(curr != NULL && c < k-1)
{
curr = curr->next;
c =c+1;
}
if(curr != NULL)
curr->next = kAltReverse(curr->next,k);
return prev;
}

struct node * revInGrp(struct node *head,int k)
{
int c = 0;

struct node * curr = head;
struct node *prev = NULL;
struct node *cn = NULL;
while(curr != NULL && c < k)
{
cn = curr->next;
curr->next = prev;
prev = curr;
curr = cn;
c = c+1;
}

if(cn != NULL)
{
 head->next = revInGrp(cn,k);
}
return prev;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);   
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print linked list */
void printList(struct node *node)
{
    int count = 0;
    while(node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
        count++;
    }
}   
 
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    // create a list 1->2->3->4->5...... ->20
    for(int i = 12; i > 0; i--)
      push(&head, i);
 
     printf("\n Given linked list \n");
     printList(head);
     head = revInGrp(head,8);
 
     printf("\n Modified Linked list \n");
     printList(head);
 
     getchar();
     return(0);
}
