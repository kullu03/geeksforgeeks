import java.util.Stack;

class Node
{
int data;
Node left;
Node right;
 Node(int d)
{
this.data = d;
left = right = null;
}
}


 class Tree
{
Node root;
 Tree(Node r)
{
this.root = r;
}

 void inorder()
{
Node curr = this.root;
java.util.Stack<Node> s  = new java.util.Stack<Node>();
boolean done = false;

while(!done)
{

if(curr != null)
{
s.push(curr);
curr = curr.left;
}
else{
if(!s.isEmpty())
{
curr = s.pop();
System.out.println(" "+curr.data);
curr = curr.right;
}
else
done = true;
}
}
}
}

public class Test{

public static void main(String args[])
{

  Node t = new Node(1);
 Tree r = new Tree(t);

  t.left        = new Node(2);
  t.right       = new Node(3);
  t.left.left  = new Node(4);
  t.left.right = new Node(5); 

r.inorder();


}



}
