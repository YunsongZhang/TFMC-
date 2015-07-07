#include<iostream>
#include "Junction.cpp"
#include<list>
#include<vector>
#include<cmath>
#include<ctime>

using namespace std;

typedef vector<Node> POINTS;
typedef list<Line> SIDES;
typedef list<Junction> BENDINGS; 

class Network
{
  public:
     Network(int L=30);
     Network() {}
    void percolation(Network net,double Prob);
     friend void InsertCell(Network net,Cell cell);
  private:
     POINTS pts;
     SIDES sides;
     BENDINGS bendings;
//     POINTS AttachedNodes;
//     SIDES AttachedFibers;
//     BENDINGS AttachedBendings;
};
      
Network::Network(int L=30)
{
    POINTS pts1((L+1)*(L+1));
    for (int i=0;i<L+1;i++)
       {
          for(int j=0;j<L+1;j++)
	    {
	        if(i==0||i==L||j==0||j==L)
		   {  pts1[i*(L+1)+j]=Node(j+0.5*i,sqrt(3)*i*0.5,true,true); }
		 else
		   {  pts1[i*(L+1)+j]=Node(j+0.5*i,sqrt(3)*i*0.5); }
             }
	}   // End of initialization of nodes!
    this->pts=pts1;
    POINTS::iterator pointer_node=pts.begin();

    for (int i=1;i<L;i++)
    {
	    for (int j=1;j<L;j++)
	    {    
            //****************************************************************************
            // side (i,j)-->(i+1,j) 
	    // bending junction (i-1,j)<--(i,j)-->(i+1,j)
		    if(i<L)
		    {
		       Line l1=Line((pointer_node+i*(L+1)+j),(pointer_node+(i+1)*(L+1)+j));
		       this->sides.push_back(l1);
		       if (i>0)
            		    {  Line l1b=Line((pointer_node+i*(L+1)+j),(pointer_node+(i-1)*(L+1)+j));
		               this->bendings.push_back(Junction(&l1,&l1b)); 
		             }
	             }  
	    //-----------------------------------------------------------------------

            //***************************************************************************
	    //side  (i,j)-->(i,j+1) 
	    //bending junction  (i,j-1)<--(i,j)-->(i,j+1)
		    if(j<L)
		    {
		       Line l2=Line((pointer_node+i*(L+1)+j),(pointer_node+i*(L+1)+j+1));
		       this->sides.push_back(l2);
		       if (j>0)
            		    {  Line l2b=Line((pointer_node+i*(L+1)+j),(pointer_node+i*(L+1)+j-1));
		               this->bendings.push_back(Junction(&l2,&l2b)); 
		             }
	             }
             //-----------------------------------------------------------------------

             //**************************************************************************
	     //side (i,j)-->(i-1,j+1)
	     //bending junction  (i+1,j-1)<--(i,j)-->(i-1,j+1)
		    if(i>0 && j<L)
		    {
		       Line l3=Line((pointer_node+i*(L+1)+j),(pointer_node+(i-1)*(L+1)+j+1));
		       this->sides.push_back(l3);
		       if (i<L && j>0)
            		    {  Line l3b=Line((pointer_node+i*(L+1)+j),(pointer_node+(i+1)*(L+1)+j-1));
		               this->bendings.push_back(Junction(&l3,&l3b)); 
		             }
	             }
	      //----------------------------------------------------------------------
	       }
     }  // End of initialization of sides and bending junctions

  }    //End of function Network::Network



		    
		    







































    


