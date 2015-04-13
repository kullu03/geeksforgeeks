// constructing queues
#include <iostream>       // std::cout
#include <deque>          // std::deque
#include <list>           // std::list
#include <queue>          // std::queue

int main ()
{
  //std::deque<int> mydeck (3,100);        // deque with 3 elements
  //std::list<int> mylist (2,200);         // list with 2 elements

  std::queue<int> first;                 // empty queue
  //std::queue<int> second (mydeck);       // queue initialized to copy of deque

  //std::queue<int,std::list<int> > third; // empty queue with list as underlying container
  //std::queue<int,std::list<int> > fourth (mylist);
 first.push(10);
first.push(20);

first.push(30);


  std::cout << "size of first: " << first.size() << '\n';
  std::cout << " first element: " << first.front() << '\n';
  std::cout << "second element: " << first.back() << '\n';
  first.pop();
 std::cout << " first element: " << first.front() << '\n';

  //std::cout << "third element: " << f << '\n';
  std::cout << "size of first: " << first.size() << '\n';

  //std::cout << "size of second: " << second.size() << '\n';
  //std::cout << "size of third: " << third.size() << '\n';
  //std::cout << "size of fourth: " << fourth.size() << '\n';

  return 0;
}
