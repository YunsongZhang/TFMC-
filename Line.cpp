#include "Node.cpp"
#include<iostream>

using namespace std;

class Line
{
  public:
    static const double stiffness;;   // The stiffness coefficient of the "spring"
    Line(Node* p1=0,Node* p2=0,bool exist=true) {this->vertice1=p1; this->vertice2=p2; }
    ~Line() {  }
    void show_line();
   private:
     Node* vertice1;
     Node* vertice2;
     bool exist;
};

 const double Line::stiffness=1.0;
void Line::show_line()
{
  Node point1=*vertice1;
  Node point2=*vertice2;
  point1.show();
  point2.show();
}

int main()
{
  
  Node p1(3,4);
  Node p2(1,2);
  Line l1(&p1,&p2);
  Line l2(&p2,&p1);
  l1.show_line();
  l2.show_line();
  
}

