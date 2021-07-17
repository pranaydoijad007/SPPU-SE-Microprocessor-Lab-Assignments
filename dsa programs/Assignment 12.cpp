#include"iostream"
using namespace std;
class search

{
	int a[20],n;
	public:
		void get();
		void display();
		void bin_search();
		void fib_search();
};
void search::get()
{
	cout<<"How many students has attended training?"<<endl;
	cin>>n;
	cout<<"Enter Roll No.s of students who had attended training?"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void search::display()
{
	cout<<"Roll no.s of students who had attended training are"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void search::bin_search()
{
	int x,low,high,mid,flag=0;
	cout<<"\n Which Roll No. you want to search?"<<endl;
	cin>>x;
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		
		 if(x<a[mid])
		{
			high=mid-1;
		}
		else if(x>a[mid])
		{
			low=mid+1;
		}
		else
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		cout<<"Student has attended training"<<endl;
		    cout<<"Record found at position "<<mid+1<<endl;
	}
	else
	cout<<"Student has not attended training"<<endl;
}
void search::fib_search()
{
	int x,i;
	cout<<"Enter the roll no. of student you want to search"<<endl;
	cin>>x;
	int flag=0;
	int fm2=0;
	int fm1=1;
	int fm=fm1+fm2;
	while(fm<=n)
	{
	
		fm2=fm1;
	    fm1=fm;
	    fm =fm2+fm1;
    }
    int offset=0;
    while(fm>1)
    {
    	int i=offset+fm2;
    	if(a[i]<x)
    	{
    	   fm=fm1;
	       fm1=fm2;
	       fm2=fm-fm1;
	       offset=i;
	    }
	    else if(a[i]>x)
	    {
	      fm=fm2;
	      fm1=fm1-fm2;
	      fm2=fm-fm1;
	    }
	    else if(a[i]==x)
	    {
	    	flag=1;
	    	break;
	     
		}
	}
    if(flag==1)
    {
    	cout<<"Student has attended the training"<<endl;
  
	}
	else
	cout<<"Student has not attended the training"<<endl;
}
int main()
{
	search s;
	s.get();
	s.display();
	int ch;
	char op;
	do
	{
		cout<<"1.Binary Search"<<endl<<"2.Fibonacci Search"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:s.bin_search();
			       break;
			case 2:s.fib_search();
			       break;
		    default:cout<<"Invalid Choice"<<endl;
			        break;		   
				   
		}
		cout<<"Do you want to continue?[y/n]"<<endl;
	    cin>>op;
	}while(op=='y');
	
}



