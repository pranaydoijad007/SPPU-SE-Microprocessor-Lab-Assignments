#include"iostream"
using namespace std;

class result
{
	int a[5][2];
public:
	void avg(int a[][2]);
	void maxmin(int a[][2]);
	void count(int a[][2]);
};
void result::avg(int a[][2])
{
	int i,sum,avg;
	for(i=0;i<5;i++)
	{
		if(a[i][1]<=50)
		{
		sum=sum+a[i][1];
		}
	}
	avg=sum/5;
	cout<<"Average of the marks:"<<avg<<endl;
}

void result::maxmin(int a[][2])
{
	int i,max,min,t,u;
	max=a[0][1];
	for(i=0;i<5;i++)
	{
		if(a[i][1]>max)
			{
			max=a[i][1];
			t=i;
			}
	}
	cout<<"Maximum marks are:"<<max<<endl;
	cout<<"Maximum marks are scored by roll no:"<<a[t][0]<<endl;

	min=a[0][1];
	for(i=0;i<5;i++)
	{
		if(a[i][1]<min)
			{
			min=a[i][1];
			u=i;
			}
	}
	cout<<"Minimum marks are:"<<min<<endl;
	cout<<"Minimum marks are scored by roll no:"<<a[u][0]<<endl;
}

void result::count(int a[][2])
{
	int c1,c2,c3,c4,c5,c6,i;
	c1=c2=c3=c4=c5=c6=0;
	for(i=0;i<5;i++)
	{
		if(a[i][1]>0 && a[i][1]<=10)
		{
			c1++;
		}
		if(a[i][1]>10 && a[i][1]<=20)
		{
			c2++;
		}
		if(a[i][1]>20 && a[i][1]<=30)
		{
			c3++;
		}
		if(a[i][1]>30 && a[i][1]<=40)
		{
			c4++;
		}
		if(a[i][1]>40 && a[i][1]<=50)
		{
			c5++;
		}
		if(a[i][1]==99)
		{
			c6++;
		}
	}
	cout<<"Count of students in the range 0-10:"<<c1<<endl;
	cout<<"Count of students in the range 10-20:"<<c2<<endl;
	cout<<"Count of students in the range 20-30:"<<c3<<endl;
	cout<<"Count of students in the range 30-40:"<<c4<<endl;
	cout<<"Count of students in the range 40-50:"<<c5<<endl;
	cout<<"Count of absent students:"<<c6<<endl;
	cout<<"Roll no of absent students are:";
	for(i=0;i<5;i++)
	{
		if(a[i][1]==99)
		cout<<a[i][0]<<endl;
	}
}

int main()
{
	int a[5][2],i,j;
	char ch='y';
	result s1;
	cout<<"Enter roll no. & marks of 5 students:";
	for(i=0;i<5;i++)
	{
		for(j=0;j<2;j++)
		{
		cin>>a[i][j];
	    }

	}

	do
	{int se;
		cout<<"Select your choice"<<endl;
		cout<<"Press 1 if you want to display the result"<<endl;
		cout<<"Press 2 if you want to display the average of marks"<<endl;
		cout<<"Press 3 if you want to display the maximum & minimum of the marks"<<endl;
		cout<<"Press 4 if you want to display the range of students"<<endl;
		cin>>se;

	switch(se)
	{
	case 1:
	  cout<<"Roll no     Marks";
	  for(i=0;i<5;i++)
	  {cout<<endl;
		for(j=0;j<2;j++)
		{
			cout<<a[i][j]<<"            ";
		}
	  }
	  cout<<endl;
	  break;
	case 2:
	  s1.avg(a);
	  break;
	case 3:
	  s1.maxmin(a);
	  break;
	case 4:
	  s1.count(a);
	  break;
	default:
		cout<<"Wrong choice"<<endl;
		break;
	}
	}while(ch=='y');

	cout<<"Do you want to re-enter the option(y/n)"<<endl;
	cin>>ch;
	return 1;
}
