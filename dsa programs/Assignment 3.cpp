/*
 * stringop.cpp
 *
 *  Created on: Jul 15, 2016
 *      Author: student
 */
#include"iostream"
#include"string"
using namespace std;
class str
{
 int i,l,m,p,o,flag,k,j;
 char a[100],b[100],c[100],sr[100],x[100];
public:
  void input(char[],char[]);
  void display(char[],char[]);
  void length(char[],char[]);
  void copy(char[],char[]);
  void reverse(char[],char[]);
  void conc(char[],char[]);
  void equal(char[],char[]);
  void sub(char[],char[]);
};
void str::input(char e[],char f[])
{
	cout<<"\n Enter string 1:";
	cin.get(e,100);
	cin.ignore();
	cout<<"\n Enter string 2:";
	cin.get(f,100);
}
void str::display(char e[],char f[])
{
	cout<<"\nString 1:"<<e;
	cout<<"\nString 2:"<<f;
}
void str::length(char e[],char f[])
{
	for(i=0;e[i]!='\0';i++)
	{
		l=i+1;
	}
	for(i=0;f[i]!='\0';i++)
	{
			m=i+1;
    }
	cout<<"\n\nLength of string 1:"<<l;
	cout<<"\n\nLength of string 2:"<<m;
}
void str::copy(char e[],char f[])
{
	for(i=0;e[i]!='\0';i++)
	{
		a[i]=e[i];
	}
	a[l]='\0';
	cout<<"\n\n Copy of string 1 is:"<<a;
}
void str::reverse(char e[],char f[])
{
	p=l;
	for(i=0;i<l;i++)
	{
		b[i]=e[p-1];
		p--;
	}
	b[l]='\0';
	cout<<"\n\nThe reverse of string 1:"<<b;
}
void str::equal(char e[],char f[])
{
	for (i=0;e[i]!='\0';i++)
	{
		if(e[i]==f[i])
		{
			flag=1;
		}
		else
		{
          flag=0;
          break;
		}
	}
	if(flag==1)
	{
		cout<<"\n\nString 1 & string 2 are equal";
	}
	else
	{
		cout<<"\n\nString 1 & string 2 are not equal";
	}
}
void str::conc(char e[],char f[])
{
	o=0;
	for(i=0;i<(l+m);i++)
	{
		if(i<l)
		{
			c[i]=e[i];
		}
		else
		{
			c[i]=f[o];
			o++;
		}
	}
	c[l+m]='\0';
	cout<<"\n\nThe concatenation of strings 1 & 2 is:"<<c;
}
void str::sub(char e[],char f[])
{
	cout<<"\nEnter string to search: ";
	cin.getline(x,100);
	int pos;
	 for(i=0;e[i]!='\0';i++)
	          {
	           for(j=0;f[j]!='\0';j++)
	           {
	        	if(e[i]==x[j])
	        	{
	        	 flag=1;
	        	 pos=i;
	        	}
	           }
	          }
	          for(j=pos+1;f[j]!='\0';j++)
	          {
	           if(e[i]==x[j])
	           {
	        	flag=1;
	           }
	          }
	          if(flag==1)
	          {
	           cout<<"\n It is a substring ";
	          }
	          else
	          {
	           cout<<"\n It is not a substring ";
	          }
}


int main()
{
	char e[100],f[100];
	str s;
	s.input(e,f);
	cin.ignore();
	s.display(e,f);
	s.length(e,f);
	s.copy(e,f);
	s.reverse(e,f);
	s.equal(e,f);
	s.conc(e,f);
	s.sub(e,f);
	return 1;

}


