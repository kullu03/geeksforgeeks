import java.util.HashMap;
import java.util.Map;

class Node{
int data;
Node next;
Node random;
public Node(int d)
{
this.data = d;
this.next = this.random =  null;
}
}

class LinkedList
{

Node head;
public LinkedList(Node h)
{
this.head = h;
}
// push method to put data always at the head
    // in the linked list.
    public void push(int data)
    {
        Node node = new Node(data);
        node.next = this.head;
        this.head = node;
    }
 
    // Method to print the list.
    void print()
    {
        Node temp = head;
        while (temp != null)
        {
            Node random = temp.random;
            int randomData = (random != null)? random.data: -1;
            System.out.println("Data = " + temp.data +
                               ", Random data = "+ randomData);
            temp = temp.next;
        }
    }
 

public LinkedList clone()
{
HashMap<Node,Node>m = new HashMap<Node,Node>();

if(this.head == null)
return null;
Node temp = this.head;
Node currClone = null;
while(temp != null)
{
currClone  = new Node(temp.data);
m.put(temp,currClone);
temp = temp.next;
}

temp = this.head;
while(temp != null)
{
currClone = m.get(temp);
currClone.next = m.get(temp.next);
currClone.random = m.get(temp.random);
temp = temp.next;
}

return new LinkedList(m.get(this.head));
}
}

// Driver Class
class Main
{
    // Main method.
    public static void main(String[] args)
    {
        // Pushing data in the linked list.
        LinkedList list = new LinkedList(new Node(5));
        list.push(4);
        list.push(3);
        list.push(2);
        list.push(1);
 
        // Setting up random references.
        list.head.random = list.head.next.next;
        list.head.next.random =
            list.head.next.next.next;
        list.head.next.next.random =
            list.head.next.next.next.next;
        list.head.next.next.next.random =
            list.head.next.next.next.next.next;
        list.head.next.next.next.next.random =
            list.head.next;
 
        // Making a clone of the original linked list.
        LinkedList clone = list.clone();
 
        // Print the original and cloned linked list.
        System.out.println("Original linked list");
        list.print();
        System.out.println("\nCloned linked list");
        clone.print();
    }
}

