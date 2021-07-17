/*
 * dq.cpp
 *
 *  Created on: Aug 11, 2016
 *      Author: student
 */
#include"iostream"
using namespace std;
# define size 10
class dq
{
	int q[size];
	int front;
	int rear;

  public:
	int i,p;
	void infront(int );
	void inrear(int );
	void deletefront();
	void deleterear();
	void disp();
	dq()
	{
		front=-1;
		rear=-1;
	}
};
void dq::infront(int x)
{
	//front=rear=-1;
	cout<<"\nQueue is: ";
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		q[front]=x;
	}
	else if(front==0)
	{
		cout<<"\nINSERTION NOT POSSIBLE";
	}
	else
	{
      front--;
      q[front]=x;
      cout<<"Element inserted";
	}
}
void dq::inrear(int x)
{
	//front=rear=-1;
	if(front==-1)
	{
		front++;
		rear++;
		q[rear]=x;
	}
	else if(rear>=size)
	{
		cout<<"QUEUE FULL";
		return;
	}
	else
	{
		q[++rear]=x;
	}

}
void dq::deletefront()
{
	//front=rear=-1;
	if(front==-1)
	{
		cout<<"\nQUEUE EMPTY";
	}
	else
	{
		if(front==rear)
		{p=q[front];
			front=rear=-1;
		}
		else
		{p=q[front];
			front++;
		}
	}

	cout<<"\nElement deleted from front end is:"<<p;
}
void dq::deleterear()
{
	p=q[rear];
	cout<<"\nElement deleted from rear end is: "<<p;
}
void dq::disp()
{
	if(rear==-1)
	{
		cout<<"\nQUEUE EMPTY";
	}
	else
	{
	for(i=front;i<=rear;i++)
	{
		cout<<q[i];
	}
	}
}
int main()
{
	dq d,d1;
	int a,ch;char op='y';
	do
	{
	/*cout<<"\nEnter element: ";
	cin>>a;*/
	cout<<"\n1.INSERT FROM FRONT \n2.INSERT FROM REAR \n3.DELETE FROM FRONT \n4.DELETE FROM REAR\n5.dispaly";
	cout<<"\nEnter your choice ";
	cin>>ch;
	switch(ch)
	{
	case 1:cout<<"\nEnter element: ";
	       cin>>a;
		   d.infront(a);
		   //d1.disp();
	       break;
	case 2:cout<<"\nEnter element: ";
	       cin>>a;
		   d.inrear(a);
          // d1.disp();
           break;
    case 3:d.deletefront();
           cout<<"\nQueue is: ";
	      // d1.disp();
	       break;
    case 4:d.deleterear();
           cout<<"\nQueue is: ";
    	   //d1.disp();
    	   break;
    case 5: d.disp();
            break;
	}
	cout<<"\nDo you want to continue(y/n): ";
	cin>>op;
	}while(op=='y');
   return 1;
}

