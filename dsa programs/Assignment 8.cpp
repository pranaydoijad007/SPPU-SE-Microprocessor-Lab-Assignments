#include"iostream"
#include "stdlib.h"
#include "string.h"
using namespace std;
//#include "cstring"
//#include <sstream>
//using namespace std;
class stack
{
 public:
  string st[20];
  int top;
  stack()
  {
    top=-1;
  }
  void push(string symbol)
  {
    if(full())
    {
      cout<<"\nStack overflow:\n";
    }
    else
    {
      top=top+1;
      st[top]=symbol;
     }
   }
   string pop()
   {string y;
     if(empty())
       return("#");         // Return value '#' indicates stack is empty
     else
     {
     	y=st[top];
     	top--;
	 }
       return(y);
   }
   int empty()
   {
     if(top==-1)
       return(1);
     else
       return(0);
   }
   int full()
   {
     if(top==29)
       return(1);
     else
       return(0);
   }
   void display()
   {
	   for(int i=0;i<=top;i++)
		   cout<<st[i]<<"  ";
   }
};
class expr
{
  char e1[30];
  char res[30];
  public:
  void read();
  int isOperator(char);
  void post_in();
  void post_pre();
  void pre_in();
  void pre_post();
  //int prec(char);
};

void expr::read()
{
     cout<<"\nEnter an  expression:";
     cin>>e1;
}

int expr::isOperator(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='$')
	return 1;
	else
	return 0;
}
//stringstream ss;
void expr::post_in()
{
   int i;
   string s1,s2,s3,x;
   x='\0';

   stack s;
   char symbol;
   int len;
   len = strlen(e1);

   cout<<"Infix expression is:\t";

   for(i=0;i<len;i++)
   {
	   symbol=e1[i];

      if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/')
      {
         s2=s.pop();
         s1=s.pop();
         s3=s1+symbol+s2;
        // strcat(s1,s2);
         s.push(s3);
      }
      else
      {
    	 // ss << symbol;
    	 // ss >> x;
    	  x=symbol;
    	  s.push(x);

      }

   }
   s.display();
}
void expr::post_pre()
{
   int i;
   string s1,s2,s3,x;
   x='\0';

   stack s;
   char symbol;
   int len;
   len = strlen(e1);

   cout<<"Prefix expression is:\t";

   for(i=0;i<len;i++)
   {
	   symbol=e1[i];

      if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/')
      {
         s2=s.pop();
         s1=s.pop();
         s3=symbol+s1+s2;
        // strcat(s1,s2);
         s.push(s3);
      }
      else
      {
    	 // ss << symbol;
    	 // ss >> x;
    	  x=symbol;
    	  s.push(x);

      }

   }
   s.display();
}
void expr::pre_in()
{
   int i;
   string s1,s2,s3,x;
   x='\0';

   stack s;
   char symbol;
   int len;
   len = strlen(e1);

   cout<<"Infix expression is:\t";

   for(i=len;i>=0;i--)
   {
	   symbol=e1[i];

      if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/')
      {
         s1=s.pop();
         s2=s.pop();
         s3=s1+symbol+s2;
        // strcat(s1,s2);
         s.push(s3);
      }
      else
      {
    	 // ss << symbol;
    	 // ss >> x;

    	  x=symbol;
    	  s.push(x);

      }

   }
   s.display();
}
void expr::pre_post()
{
   int i;
   string s1,s2,s3,x;
   x='\0';

   stack s;
   char symbol;
   int len;
   len = strlen(e1);

   cout<<"Infix expression is:\t";

   for(i=len;i>=0;i--)
   {
	   symbol=e1[i];

      if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/')
      {
         s1=s.pop();
         s2=s.pop();
         s3=s1+s2+symbol;
        // strcat(s1,s2);
         s.push(s3);
      }
      else
      {
    	 // ss << symbol;
    	 // ss >> x;
    	  x=symbol;
    	  s.push(x);

      }

   }
   s.display();
}
int main()
{
	     string ch;
	     expr e11,e12;
	     int opt;
	     stack st;
	     while(1)
	        {
	             cout <<"\n1.Postfix to infix \n2.postfix to prefix\n3.Prefix to infix \n4.Prefix to Postfix\n5.exit";
	             cout<<"\nEnter ur choice";
	             cin >> opt;
	             switch(opt)
	              {
	               case 1:
	            	   e11.read();
	            	   e11.post_in();
	            	   break;
	               case 2:
	            	   e11.read();
	            	   e11.post_pre();
	            	   break;
	               case 3:
	            	   e12.read();
	            	   e12.pre_in();
	            	   break;
	               case 4:
	            	   e12.read();
	            	   e12.pre_post();
	            	   break;
	               case 5:  exit(0);
	               }
	         }
	//return 0;
	}
