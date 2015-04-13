#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the linked list */
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
 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
}
 
struct node * removeDuplicates(struct node * head)
{
if(head == NULL)
{
printf("Empty list\n");
return NULL;
}
struct node * t1= head;
struct node * t2 = t1->next;
struct node * t= NULL;

while(t2)
{

while(t1->data == t2->data)
{
t = t2;
if(t2->next)
t2= t2->next;
free(t);
}
t1->next = t2;
t1 = t1->next;
t2 = t2->next;
}
return head;
}


/* Drier program to test above functions*/
int main()
{
  /* Start with the empty list */
  struct node* head = NULL;

  /* Let us create a sorted linked list to test the functions
   Created linked list will be 11->11->11->13->13->20 */
  push(&head, 60);
  push(&head, 60);
/*  push(&head, 43);
  push(&head, 21);
  push(&head, 11);
  push(&head, 11);
  push(&head, 11);
*/
  printf("\n Linked list before duplicate removal  ");
  printList(head);

  /* Remove duplicates from linked list */
  removeDuplicates(head);

  printf("\n Linked list after duplicate removal ");
  printList(head);

  getchar();
}



