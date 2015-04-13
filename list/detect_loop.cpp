#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
  int data;
  struct node* next;
};
 
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

bool isLoop(struct node *head)
{

if(head ==NULL)
{
printf("List is empty");
return NULL;
}

struct node * slow = head;
struct node *fast = slow;
while(slow && fast && fast->next != NULL)
{
slow = slow->next;
fast = fast->next->next;
if(slow == fast)
{
// detect the start of cycle
slow = head;
while(slow != fast)
{
slow = slow->next;
fast = fast->next;
}
printf("Start of the loop is : %d\n",slow->data);
return true;
}
}
return false;
}
int main()
{
  /* Start with the empty list */
  struct node* head = NULL;
 
  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 10);
 
  /* Create a loop for testing */
  head->next->next->next = head;
  if(isLoop(head))
  printf("Yes");
else
printf("NO");
 
  getchar();
}

