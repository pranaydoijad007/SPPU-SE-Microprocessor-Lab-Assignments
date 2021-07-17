/*
 * qc.cpp
 *
 *  Created on: Jan 1, 2002
 *      Author: student
 */
#include"iostream"
using namespace std;
# define size 10
class qc
{
	int q[size],p,i;
	int front;
	int rear;
    public:
	qc()
    {
		front=-1;
		rear=-1;
    }
	   void insert(int );
	   void delt();
	   void disp();
};
void qc::insert(int x)
{
		if(front==-1 && rear==-1)
		{
			front=rear=0;
			q[rear]=x;
		}
		else
		{
			if(front==((rear+1)%size))
		    {
			cout<<"\nQueue full";
		    }
		   else
		   {
	        rear=(rear+1)%size;
	        q[rear]=x;
	        cout<<"Element inserted";
		   }
		}
}
void qc::delt()
{
	if(front==-1)
		{
			cout<<"\nQUEUE EMPTY";
		}
		else
		{
			p=q[front];
			front=((front+1)%size);
		}

		cout<<"\nElement deleted from front end is:"<<p;
}
void qc::disp()
{
	for(i=front;i!=rear;i=((i+1)%size))
   {
	   cout<<q[i]<<" ";
   }
   cout<<q[i];
}
int main()
{
	int x;
	qc q;
	char op='y';
	int ch;
	do
	{
		cout<<"\n1.INSERT \n2.DELETE \n3.Display";
		cout<<"\nEnter your choice ";
		cin>>ch;
		switch(ch)
		{
		case 1:cout<<"\nEnter element: ";
		       cin>>x;
			   q.insert(x);
		       break;
		case 2:q.delt();
	           cout<<"\nQueue is: ";
	           q.disp();
		       break;
	    case 3:cout<<"\nQueue is: ";
	    	   q.disp();
	           break;
		}
		cout<<"\nDo you want to continue(y/n): ";
		cin>>op;
		}while(op=='y');
	return 1;
}


