class Node{
int data;
Node next;
public Node(int data)
{
this.data = data;
this.next = null;
}
}

class LinkedList{
Node head;

public LinkedList(Node h)
{
this.head = h;
}

public LinkedList Seggregate()
{

if(this.head == null)
return null;

Node Orihead = this.head;
Node curr = this.head;
Node odd = null;
Node hodd = null;
Node prev = null;


// get the head of even list
while(curr.next != null)
{
 if(curr.data % 2 == 0 )
{
this.head  = curr;
break;
}
curr = curr.next;
}

curr = Orihead;

// get the head of odd list

while(curr.next != null)
{

if(curr.data % 2 != 0)
{
odd = curr;
break;
}
curr = curr.next;
}

curr = Orihead;
Node oddh = odd;
while(curr.next != null)
{
if(curr.next.data % 2 != 0)
{
prev = curr;
odd = curr.next;
curr = curr.next;
prev.next = curr;
odd = odd.next;
odd.next = null;
}
curr = curr.next;
}

// Now add odd list end of even list
Node c = this.head;

while(c.next != null)
{
c = c.next;
}
c.next = oddh;
}
return this.head;

}
