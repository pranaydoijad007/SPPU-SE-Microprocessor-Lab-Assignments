#include"iostream"
#include "stdlib.h"
#include "string.h"
#include"stack"
using namespace std;
class in_post
{
	
	public:
	int getWeight(char );
	void infix2postfix(char [],char [],int );
	int eval(char [],int );
	int evaluate(char ,int ,int );
};
int in_post::getWeight(char ch)
{
	switch (ch)
	{
      case '/':
      case '*': return 2;
      case '+':
      case '-': return 1;
      default : return 0;
    }
}
void in_post::infix2postfix(char infix[], char postfix[], int size)
{
	stack<char>s;
   int weight;
   int i = 0;
   int k = 0;
   char ch;
   while (i < size)
    {
      ch = infix[i];
      if (ch == '(')
	  {
      	s.push(ch);
	    i++;
	    continue;
      }
      if (ch == ')') 
	  {
	    while (!s.empty() && s.top() != '(')
		{
	      postfix[k++] = s.top();
	      s.pop();
        }
	
	    if (!s.empty())
	    {
	      s.pop();
	    }
	    i++;
	    continue;
      }
      weight = getWeight(ch);
      if (weight == 0)
	  {
	     postfix[k++] = ch;
      }
      else 
	  {
	    if (s.empty()) 
		{
	      s.push(ch);
	    }
	    else 
		{
	    while (!s.empty() && s.top() != '(' && weight <= getWeight(s.top())) 
		{
	       postfix[k++] = s.top();
	       s.pop();
		}
	    s.push(ch);
	  }
     }
      i++;
    }
   
    while (!s.empty())
    {
      postfix[k++] = s.top();
      s.pop();
    }
   postfix[k] = 0; 
}

int in_post::evaluate(char operate,int op1,int op2)
{
	switch(operate)
	{
		case '*':return op2*op1;
		case '/':return op2/op1;
		case '+':return op2+op1;
		case '-':return op2-op1;
		default:return 0;
	} 
}
int in_post::eval(char postfix[],int size)
{
	stack<char>s;
	int i=0;
	char ch;
	int val;
	
	while(i<size)
	{
		ch=postfix[i];
	
	    if(isdigit(ch))
	    {
	    	s.push(ch-'0');
	    }
        else
		{
			int op1=s.top();
		     s.pop();
		    int op2=s.top() ;
		     s.pop();
		    val=evaluate(ch,op1,op2);
		    s.push(val);
		}
	    i++;
    } 
    return val;
}

int main()
{
   in_post ip;
   char infix[] = "A*(B+C)/D";
   int size = strlen(infix);
   char postfix[size];
   ip.infix2postfix(infix,postfix,size);
   cout<<"\n\nInfix Expression :: "<<infix;
   cout<<"\n\nPostfix Expression :: "<<postfix;
   cout<<endl;
   cout<<"\nEvaluation of postfix expression: ";
   char post[]="234*+";
   cout<<"\nPostfix expression is: "<<post;
   int size1=strlen(post);
   int val=ip.eval(post,size1);
   cout<<"\nResult: "<<val;
   cout<<endl;
   return 0;
}

