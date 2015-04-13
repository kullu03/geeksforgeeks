public class Vertex{
int key;
ArrayList<int>connectedTo;
public Vertex(int v)
{
this.key = v;
this.connectedTo = new ArrayList<int>();
}
}



public class Graph
{
int numOfVertex;
ArrayList<Vertex>verList ;
public Graph(int v)
{
this.numOfVertex = 0;
this.verList  = new ArrayList<Vertex>();
}

public addVertex(int w)
{
this.numOfVertex = this.numOfVertex + 1;
Vertex V = new Vertex(w);
verList.add(V);
}
public void addEdge(int v,int w)
{



}

}

class Test
{
public static void main(String [] args)
{



}




}
