#include "Line.cpp"
#include<iostream>

using namespace std;

class Junction
{
  public:
    static const double alpha;  //bending 
    Junction(Line* L1=0,Line* L2=0)
    { this->side1=L1;
      this->side2=L2;
     }
     ~Junction() {  }

     private:
      Line* side1;
      Line* side2;
 };


