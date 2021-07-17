/*
 * seq.cpp
 *
 *  Created on: Jan 1, 2002
 *      Author: student
 */
#include"iostream"
using namespace std;
class search
{
	int n,a[20],flag=0,i,pos,x;
    public:
	void get();
	void disp();
	void soseqsearch(int );
	void unseqsearch(int );
	void sentinel(int );

};
void search::get()
{
	cout<<"\nEnter no. of elements: ";
	cin>>n;
	cout<<"\nEnter elements: ";
	for(i=0;i<n;i++)
	{
	  cin>>a[i];
	}

}
void search::disp()
{
	cout<<"\nElements are: ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
void search:: soseqsearch(int x)
{
	i=0;
	while(i<n&&x>a[i])
	{
		i++;
	}
	if(i<n&&x==a[i])
	{
		cout<<"\nElement found at location "<<i;
	}
	else
	{
		cout<<"\nElement not found";
	}
}
void search::unseqsearch(int x)
{
	for(i=0;i<n;i++)
	{
		if(x==a[i])
		{
			flag=1;
			pos=i;
			break;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==1)
	{
		cout<<"\nElement found at location: "<<pos;
	}
	else
	{
		cout<<"\nElement not found";
	}
}
void search::sentinel(int x)
{
	a[n]=x;
   for(i=0;a[i]!=x;i++)
   {
   }

   if(i!=n)
   {
	   cout<<"\nElement found at location: "<<i;
   }
   else if(i==n)
   {
	   cout<<"\nElement not found ";
   }
}
int main()
{
	int x,ch;
	char op='y';
	search s,s1,s2;
	do
	{
	cout<<"\n1.FOR SEQUENTIAL SEARCH \n2.FOR SENTINEL SEARCH";
	cout<<"\nEnter your choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:cout<<"\n\n**************Sorted sequential search************* ";
		       cout<<"\nEnter elements in sorted order";
	           s1.get();
	           s1.disp();
	           cout<<"\nEnter element to search:  ";
	           cin>>x;
	           s1.soseqsearch(x);
	           cout<<"\n\n------------------------------------------------------------";
	           cout<<"\n\n************Unsorted sequential search************ ";
	           cout<<"\nEnter elements in unsorted order";
	           s.get();
	           s.disp();
	           cout<<"\nEnter element to search:  ";
	           cin>>x;
	           s.unseqsearch(x);
               cout<<"\n\n------------------------------------------------------------";
               break;
        case 2:cout<<"\n\n*************Sentinel search***************";
               cout<<"\nEnter elements: ";
	           s2.get();
	           s2.disp();
	           cout<<"\nEnter element to search:  ";
	           cin>>x;
	           s2.sentinel(x);
	           cout<<"\n\n------------------------------------------------------------";
	           break;
	}
	cout<<"\n\nDo you want to continue?(y/n): ";
	cin>>op;
    }while(op=='y');
	return 1;
}

