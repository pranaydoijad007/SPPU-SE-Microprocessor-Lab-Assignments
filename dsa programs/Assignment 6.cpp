/*
 * merge.cpp
 *
 *  Created on: Aug 11, 2016
 *      Author: student
 */
#include"iostream"
using namespace std;
struct node
{
	int data;
	node *prev;
	node *next;
};
class link
{
	node *head,*temp,*temp1,*p;
  public:
	void create();
	void disp();
	void merge(link ,link );
};
void link::create()
{

    int n;
    cout<<"\nEnter no. of nodes: ";
	cin>>n;
	cout<<"\nENTER NUMBERS IN SORTED ORDER";
	head=NULL;
	for(int i=0;i<n;i++)
	{
	temp=new node;
	cout<<"\nEnter number: ";
	cin>>temp->data;
	temp->next=NULL;
	temp->prev=NULL;

	if(head==NULL)
	{
		head=temp;

	}
	else
	{
		temp1=head;
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		//if(temp1->data<temp->data)
		temp1->next=temp;
		temp->prev=temp1;

	}
	}
}
void link::disp()
{
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		cout<<"<-|"<<temp->data<<"|->";
	}
	    //cout<<"<-|"<<temp->data<<"|";

}
void link::merge(link l1,link l2)
{
   if(l1.head->data<l2.head->data)
   {
	   head=p=l1.head;
	   l1.head=l1.head->next;
   }
   else
   {
	   head=p=l2.head;
	    l2.head=l2.head->next;
   }
   while(l1.head!=NULL && l2.head!=NULL)
   {
	   if(l1.head->data<=l2.head->data)
	   {
		   p->next=l1.head;
		   l1.head->prev=p;
		   l1.head=l1.head->next;
		   p=p->next;
	   }
	   else
	   {
		   if(l2.head->data<=l1.head->data)
		   {
			   p->next=l2.head;
			   l2.head->prev=p;
			   l2.head=l2.head->next;
			   p=p->next;
		   }
	   }
    }
   while(l1.head!=NULL)
   {
	   p->next=l1.head;
	   l1.head->prev=p;
	   l1.head=l1.head->next;
	   p=p->next;
   }
   while(l2.head!=NULL)
      {
   	   p->next=l2.head;
   	   l2.head->prev=p;
   	   l2.head=l2.head->next;
   	   p=p->next;
      }

}
int main()
{
	link l,l1,l2;
	cout<<"\nEnter 1st list in sorted order:";
	l.create();
	cout<<"\n1st list is:";
	l.disp();
	cout<<"\n\nEnter 2nd list in sorted order:";
	l1.create();
	cout<<"\n2nd list is:";
	l1.disp();
	cout<<"\nMerged list: ";
	l2.merge(l,l1);
	l2.disp();
	return 1;
}



