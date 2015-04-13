
#include<iostream>
using namespace std;

class Point
{
int x;
int y;
public: Point(int x1,int y1)
{
x = x1;
y= y1;
}

public: Point(const Point &p2)
{
x = p2.x + 10;
y = p2.y + 15;
}

public: int getx()
{
return x;
}
public: int gety()
{
return y;
}
};


int main()
{

Point p(10,15);
cout << "x = " << p.getx() << "\n";
cout << "y = " << p.gety() << "\n";

// copy constructor
Point p1 = p;
cout << "copy constructor called \n";
cout << "p1.x = " << p1.getx() << "\n";
cout << "p1.y = " << p1.gety() << "\n";


return 0;
}
