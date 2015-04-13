#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};


struct node * nthNodeFromEnd(struct node * head,int n)
{
struct node *main = head;
struct node *ref =  head;
while(n)
{
ref= ref->next;
n = n-1;
}

while(ref)
{
ref= ref->next;
main = main->next;
}
return main;
}

void deleteList(struct node *node)
{
if(node == NULL)
printf("Nothing to delete its a emty list\n");
struct node *temp = NULL;
while(node->next != NULL)
{
temp = node;
node =node->next;
free(temp);
}
node = NULL;
}


/* Given a reference (pointer to pointer) to the head
  of a list and an int, push a new node on the front
  of the list. */
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
 
/* Drier program to test count function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    
    /* Use push() to construct below list
     1->12->1->4->1  */
    push(&head, 80);
    push(&head, 70);
    push(&head, 60);

    push(&head, 50);
    push(&head, 40);
    push(&head, 30);
    push(&head, 20);
    push(&head, 10);  
    struct node *t = nthNodeFromEnd(head,4);
    printf("Node = %d\t",t->data);
    //printf("\n Deleting linked list");
    //deleteList(head); 
    
    //printf("\n Linked list deleted");
    getchar();
}
