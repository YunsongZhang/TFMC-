#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Node
{
 public:
  Node(double x=0,double y=0,bool fix_x=false,bool fix_y=false,bool exist=true)
  { 
     this->x=x;  this->y=y;
     this->fix_x=fix_x;
     this->fix_y=fix_y;
     this->exist=exist;
   }

   void show()
   {
    cout<<"("<<x<<","<<y<<")"<<endl;
   }
  private:
     double x;
     double y;
     bool fix_x;
     bool fix_y;
     bool exist;
};

typedef vector<Node> POINTS;

int main()
{
  int L=30;
  POINTS pts((L+1)*(L+1));
  POINTS pts1;
   
    for (int i=0;i<L+1;i++)
       {
          for(int j=0;j<L+1;j++)
	    {
	        if(i==0||i==L||j==0||j==L)
		   {  pts[i*(L+1)+j]=Node(j+0.5*i,sqrt(3)*i*0.5,true,true); }
		 else
		   {  pts[i*(L+1)+j]=Node(j+0.5*i,sqrt(3)*i*0.5); }
             }
	}

      int num=1;
      pts1=pts;
    for(POINTS::iterator p=pts1.begin();p!=pts1.end();p++)
      {
        
	cout<<num++<<": ";
        (*p).show();
      }
}
  
 














