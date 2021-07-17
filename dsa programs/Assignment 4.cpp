/*
 * sllopr.cpp
 *
 *  Created on: Jan 1, 2002
 *      Author: student
 */

/*
 * sll2816.cpp
 */
/*
 * sll28.cpp
 *
 *  Created on: Jan 1, 2002
 *      Author: student
 */





#include"iostream"
#include"string.h"
using namespace std;
struct node
{
	int prn;
	char name[20];
	node*next;
}*president,*temp,*temp1,*temp2,*temp3,*president1,president2;
class sll
{
public:
	void create();
	void displ();
	void disppresident();
	void inserthead();
	void insertlast();
	void insertbetw();
	void deletehead();
	void deletelast();
	void deletebetw();
	void reverse(node *president);
	int concat(node *president1,node *president2);
};
void sll::create()
{
	char op='y';
	president=NULL;
	do
	{
	temp=new node;
	cout<<"\nEnter the PRN NO.: ";
	cin>>temp->prn;
	cout<<"\nEnter name: ";
	cin>>temp->name;
	temp->next=NULL;

	    if(president==NULL)
	    {
	      president=temp;
		  temp1=president;
	    }
	    else
	    {
		   while(temp1->next!=NULL)
		   {
			 temp1=temp1->next;
		   }
		   temp1->next=temp;
	    }
	    cout<<"Do you want to continue?(y/n)";
	    cin>>op;
	}while(op=='y');
}

void sll::disppresident()
{
	temp3=president;
    cout<<"\n\nPresident is \n PRN NO.: "<<temp3->prn<<"\n Name: "<<temp3->name;
}

void sll::displ()
{
	cout<<"\n Linked list is:";
	for(temp=president;temp->next!=NULL;temp=temp->next)
	{
		cout<<"\n"<<temp->prn<<" ";
		cout<<"\t"<<temp->name<<" ";
	}
	cout<<"\n"<<temp->prn<<"";
	cout<<"\t"<<temp->name;
	temp=president;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	cout<<"\n\nTotal no. of nodes are: "<<count;
}

void sll::inserthead()
{
	temp=new node;
    cout<<"\n\nEnter the PRN NO.you want to insert at first positon:";
	cin>>temp->prn;
	cout<<"\n\n Enter name you want to insert at first positon: ";
	cin>>temp->name;
	temp->next=NULL;
	temp->next=president;
	president=temp;
	cout<<"New linked list with inserted element is:";
	for(temp=president;temp->next!=NULL;temp=temp->next)
		{
			cout<<"\n"<<temp->prn<<" ";
			cout<<"\t"<<temp->name<<" ";
		}
		cout<<"\n"<<temp->prn;
		cout<<"\t"<<temp->name<<" ";
}

void sll::insertlast()
{
	temp=new node;
	cout<<"\n\nEnter the PRN NO. you want to insert at last positon:";
	cin>>temp->prn;
	cout<<"\n\n Enter name you want to insert at first positon: ";
	cin>>temp->name;
	temp->next=NULL;
	temp1=president;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp1->next=temp;
	cout<<"New linked list with inserted element is:";
	for(temp=president;temp->next!=NULL;temp=temp->next)
	{
		cout<<"\n"<<temp->prn<<" ";
		cout<<"\t"<<temp->name<<" ";
	}
		cout<<"\n"<<temp->prn;
		cout<<"\t"<<temp->name<<" ";

}

void sll::insertbetw()
{
	int x,z;
	temp=new node;
	cout<<"\n\nEnter the PRN NO. want to insert between link list:";
	cin>>temp->prn;
	cout<<"\n\nEnter the name want to insert between link list:";
	cin>>temp->name;
	temp->next=NULL;
	cout<<"Enter an PRN No. after which do you want to insert: ";
	cin>>x;
	temp1=president;
	while(temp1->next!=NULL)
	{
		if(temp1->prn==x)
		{
			temp->next=temp2;
			temp1->next=temp;
			break;


		}
		else
		{
			temp1=temp1->next;
			temp2=temp1->next;
		}

	}
	cout<<"New linked list with inserted element is:";
    for(temp=president;temp->next!=NULL;temp=temp->next)
	{
    	cout<<"\n"<<temp->prn<<" ";
        cout<<"\t"<<temp->name<<" ";

	}
        cout<<"\n"<<temp->prn<<" ";
        cout<<"\t"<<temp->name<<" ";
}


void sll::deletehead()
{
	temp=president;
	president=president->next;
	temp->next=NULL;
	cout<<"\n After deleting first element new linked list is: ";
	for(temp=president;temp->next!=NULL;temp=temp->next)
			{
				cout<<"\n"<<temp->prn<<"  ";
				cout<<"\t"<<temp->name<<" ";
			}
			cout<<"\n"<<temp->prn;
			cout<<"\t"<<temp->name<<" ";
}

void sll::deletelast()
{
	temp1=temp=president;
	while(temp->next!=NULL)
	{
		temp1=temp;
		temp=temp->next;
	}
	  temp1->next=NULL;
	  delete temp;
	  cout<<"\n\nNew linked list with deleted last element is:";
	   	for(temp1=president;temp1->next!=NULL;temp1=temp1->next)
	   	{
	   		cout<<"\n"<<temp1->prn<<" ";
	   		cout<<"\t"<<temp1->name<<" ";
	   	}
	   		cout<<"\n"<<temp1->prn;
	   		cout<<"\t"<<temp1->name<<" ";
}

void sll::deletebetw()
{
	int key;
	cout<<"\n\nEnter PRN NO. you want to delete: ";
	cin>>key;
	temp=president;
	while(temp->next!=NULL)
	{
		if(temp->prn==key)
		{
			temp1->next=(temp->next);
			temp->next=NULL;
			delete temp;
			break;
		}
		else
		{
			temp1=temp;
			temp=temp->next;
		}
	}
	for(temp1=president;temp1->next!=NULL;temp1=temp1->next)
		   	{
		   		cout<<"\n"<<temp1->prn<<" ";
		   		cout<<"\t"<<temp1->name<<" ";
		   	}
		   		cout<<"\n"<<temp1->prn;
		   		cout<<"\t"<<temp1->name<<" ";
}

void sll::reverse(node *president)
{
  if(president==NULL)
  return;
  else
  reverse(president->next);
  cout<<"\n"<<president->prn<<" ";
  cout<<"\t"<<president->name<<" ";
}

int sll::concat(node *president1,node *president2)
{
	node *temp;
	if(president1==NULL)
	{
		return (node *president2);
	}
	if(president2==NULL)
	{
		return (president1);
	}
	temp=president1;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=president2;
	return(president1);
}

int main()
{
	sll s1,s2,s;
	cout<<"\nEnter first list";
	s1.create();
	s1.displ();
    int ch;
    char opt='y';
    do
    {
    cout<<"\n\n1.Insert at first position\n2.Insert at last poion\n3.Insert between\n4.Delete first\n5.Delete last\n6.Delete between\n7.Reverse\n8.Display president\n9.Concatenate";
	cout<<"\nEnter your choice: ";
	cin>>ch;

     switch(ch)
	{

	  case 1:s1.inserthead();
	         break;
	  case 2:s1.insertlast();
	         break;
	  case 3:s1.insertbetw();
	  	 	 break;
	  case 4:s1.deletehead();
	         break;
	  case 5:s1.deletelast();
	        break;
	  case 6:s1.deletebetw();
	         break;
	  case 7:s1.reverse(president);
	          break;
	  case 8:s1.disppresident();
	 	     break;
	  case 9:s.concat(president1,president2);
	         break;
	}
	  cout<<"\n\nDo you want to continue?(y/n)";
	  cin>>opt;
	}while(opt=='y');
	cout<<"\nEnter second list";
	s2.create();
	s2.displ();

	return 1;
}










