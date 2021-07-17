/*
 * binar.cpp
 *
 *  Created on: Jan 1, 2002
 *      Author: student
 */
#include"iostream"
using namespace std;
struct node
{
	int no;
	node *prev;
	node *next;
}*temp,*temp1,*temp2;
class dll
{
	int c=0;
   public:
		node *head,*prev;
	 void create();
	 void displ();
	 void onecompl();
	 void twocompl();
	 dll add(dll ,dll ,dll );
};
void dll::create()
{
	char op='y';
	head=NULL;
	do
	{
		temp=new node;
		cout<<"\nEnter the number.: ";
		cin>>temp->no;
		temp->next=NULL;
		temp->prev=NULL;
		if(head==NULL)
		{
			head=temp;
			temp1=head;
		}
		else
		{
			while(temp1->next!=NULL)
			{
				temp1=temp1->next;
			}
				temp1->next=temp;
				temp->prev=temp1;


		}
		cout<<"Do you want to continue?(y/n)";
	    cin>>op;
	}while(op=='y');
 }
void dll::displ()
{
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		cout<<temp->no<<" ";
	}
}
void dll::onecompl()
{
	temp1=head;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	for(temp=temp1;temp!=NULL;temp=temp->prev)
	{
		if(temp->no==0)
		{
			temp->no=1;
		}
		else if(temp->no==1)
		{
			temp->no=0;
		}
	}
}
void dll::twocompl()
{
   for(temp=head;temp->next!=NULL;temp=temp->next)
   {

   }
   int j=0;
   for(temp1=temp;temp1->prev!=NULL;temp1=temp1->prev)
   {
	   if(j==0)
	   {
		   temp1->no=temp1->no+1;
		   if(temp1->no==2)
		   {
			   temp1->no=0;
			   c=1;
		   }
		   else if(temp1->no==0)
		   {
			    temp->no=0;
			    c=0;
		   }
		   else
		   {
			   temp->no=1;
			   c=0;
		   }
	   }
	   else
	   {
		   temp1->no=temp1->no+c;
		   if(temp1->no==1)
		   {
			   temp1->no=1;
			   c=0;
		   }
		   else if(temp1->no==0)
		   {
			   temp1->no=0;c=0;
		   }
		   else
		   {
			   temp1->no=0;
			   c=1;
		   }
	   }
	   j=j+1;
   }
}
dll dll::add(dll d1,dll d2,dll d3)
{
	int x,y,z,c=0;
	while(d1.head->next!=NULL)
		d1.head=d1.head->next;
	while(d2.head->next!=NULL)
	  d2.head=d2.head->next;
	d3.head=NULL;
	x=y=0;
	while(d1.head!=NULL || d2.head!=NULL)
	{
		if(d1.head!=NULL)
		{
			x=d1.head->no;
            d1.head=d1.head->prev;
		}
		if(d2.head!=NULL)
		{
			y=d2.head->no;
		    d2.head=d2.head->prev;
	    }
		z=(x+y+c)%2;
		c=(x+y+c)/2;
		if(d3.head==NULL)
		{
			d3.head=new node;
			d3.head->next=d3.head->prev=NULL;
		}
		else
		{
			d3.head->prev=new node;
			(d3.head->prev)->next=d3.head;
			d3.head->prev=(d3.head->prev);
			d3.head=d3.head->prev;
			d3.head->prev=NULL;
		}
		d3.head->no=z;
	}
	if(c==1)
	{
		d3.head->prev=new node;
		d3.head->prev->next=d3.head;
		d3.head=d3.head->prev;
		d3.head->prev=NULL;
		d3.head->no=c;
	}
	return d3;
}
int main()
{
	dll d,d1,d2,d3;
	cout<<"\n\nEnter first number: ";
	d1.create();
	cout<<"\nBinary no.1 is: ";
	d1.displ();
	cout<<"\n\nEnter second number: ";
	d2.create();
	cout<<"\nBinary no.2 is: ";
	d2.displ();
	cout<<"\nAdition is: ";
    d3=d.add(d1,d2,d3);
    d3.displ();
	cout<<"\nOne's compliment is: ";
	d1.onecompl();
	d1.displ();
	cout<<"\nTwo's compliment is: ";
	d1.twocompl();
	d1.displ();
   
    return 0;
}




