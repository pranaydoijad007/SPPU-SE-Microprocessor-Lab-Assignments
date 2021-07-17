

#include "iostream"
#include "stdlib.h"
using namespace std;
class sports
{
 private:
	     int c[20],b[20],i,j,n1,n2,n,u[50];
	     int x[50],k=0,cnt=0,cnt2=0;
	     int z[50];
 public:
	     void get();
	     void univ();
	     void cri();
	     void bad();
	     void inter();
	     void uni();
	     void onlycri();
	     void onlybad();
	     void neither();
};
void sports::get()
{
 cout<<"\n Enter the total no. of students: ";
 cin>>n;
}
void sports::univ()
{
 for(i=0;i<n;i++)
 {
  cout<<"\n Enter roll no.: ";
  cin>>u[i];
 }
  cout<<"\n Roll no. of all the students is: ";
  for(i=0;i<n;i++)
  {
   cout<<u[i]<<"   ";
  }
}
void sports::cri()
{
 cout<<"\n Enter the no. of students who play cricket: ";
 cin>>n1;
 cout<<"\n Roll no. of students who play cricket: ";
 for(i=0;i<n1;i++)
 {
  cout<<"\n Enter roll no.: ";
  cin>>c[i];
 }
  cout<<"\n Students who play cricket are: ";
  for(i=0;i<n1;i++)
  {
   cout<<c[i]<<"   ";
  }
}
void sports::bad()
{
 cout<<"\n Enter the no. of students who play badminton: ";
 cin>>n2;
 cout<<"\n Roll no. of students who play badminton: ";
 for(j=0;j<n2;j++)
 {
  cout<<"\n Enter roll no.: ";
  cin>>b[j];
 }
  cout<<"\n Students who play badminton are: ";
  for(j=0;j<n2;j++)
  {
   cout<<b[j]<<"   ";
  }
}
void sports::inter()
{
 for(i=0;i<n1;i++)
 {
  for(j=0;j<n2;j++)
  {
   if(c[i]==b[j])
   {
    cnt++;
	x[k]=c[i];
    k++;
   }
  }
 }
 cout<<"\n Students who play both cricket and badminton are: ";
 for(k=0;k<cnt;k++)
 {
  cout<<x[k]<<"   ";
 }
}
void sports::uni()
{
 i=0;
 j=0;
 k=0;
 while(i<n1 && j<n2)
 {
  if(c[i]<=b[j])
  {
   z[k]=c[i];
   k++;
   i++;
   cnt2++;
  }
  else
  {
   z[k]=b[j];
   k++;
   j++;
   cnt2++;
  }
 }
 while(i<n1)
 {
  z[k]=c[i];
  k++;
  i++;
  cnt2++;
 }
 while(j<n2)
 {
  z[k]=b[j];
  k++;
  j++;
  cnt2++;
 }
 cout<<"\n The students who play cricket or badminton are: ";
 for(int r=0;r<cnt2;r++)
 {
  if(z[r]!=z[r+1])
  {
   cout<<z[r]<<"   ";
  }
 }
}
void sports::onlycri()
{
 cout<<"\n Students who play only cricket are: ";
 for(i=0;i<n1;i++)
 {
  for(k=0;k<cnt;k++)
  {
   if(c[i]==x[k])
   {
	c[i]=0;
   }
  }
 }
 for(i=0;i<n1;i++)
 {
  if(c[i]!=0)
  {
   cout<<c[i]<<"   ";
  }
 }
}
void sports::onlybad()
{
 cout<<"\n Students who play only badminton are: ";
 for(j=0;j<n2;j++)
 {
  for(k=0;k<cnt;k++)
  {
   if(b[j]==x[k])
   {
	b[j]=0;
   }
  }
 }
 for(j=0;j<n2;j++)
 {
  if(b[j]!=0)
  {
   cout<<b[j]<<"   ";
  }
 }
}
void sports::neither()
{
 cout<<"\n The students who play neither cricket nor badminton are: ";
 for(i=0;i<n;i++)
 {
  for(j=0;j<cnt2;j++)
  {
   if(u[i]==z[j])
   {
	u[i]=0;
   }
  }
 }
 for(i=0;i<n;i++)
 {
  if(u[i]!=0)
  {
   cout<<u[i]<<"   ";
  }
 }
}
int main()
{
 sports s;
 int ch;
 s.get();
 do
 {
 cout<<"\n 1. Universal Set ";
 cout<<"\n 2. Cricket Set ";
 cout<<"\n 3. Badminton Set ";
 cout<<"\n 4. Intersection of cricket and badminton ";
 cout<<"\n 5. Union of cricket and badminton ";
 cout<<"\n 6. Only cricket ";
 cout<<"\n 7. Only badminton ";
 cout<<"\n 8. Neither cricket nor badminton ";
 cout<<"\n 9. Exit ";
 cout<<"\n Enter your choice: ";
 cin>>ch;
 switch(ch)
 {
  case 1:
         s.univ();
	     break;
  case 2:
         s.cri();
         break;
  case 3:
         s.bad();
         break;
  case 4:
         s.inter();
	     break;
  case 5:
	     s.uni();
         break;
  case 6:
	     s.onlycri();
	     break;
  case 7:
	     s.onlybad();
	     break;
  case 8:
	     s.neither();
         break;
  case 9:
	     exit(0);
 }
}while(ch>0 && ch<=9);
 return 0;
}
