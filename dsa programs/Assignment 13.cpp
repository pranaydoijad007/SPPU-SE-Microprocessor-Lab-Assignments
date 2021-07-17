#include"iostream"
using namespace std;
class qs
{
	int i,j;
	float pivot,temp;
public:
	void quicksort(float [],int ,int );
	int partition(float [],int ,int );
};
void qs::quicksort(float a[] ,int l ,int u)
{
	if(l<u)
	{
		j=partition(a,l,u);
		quicksort(a,l,j-1);
		quicksort(a,j+1,u);
	}
}
int qs::partition(float a[] ,int l ,int u)
{
	pivot=a[l];
	i=l;
	j=u+1;
	do
	{
		do
		{
			i++;
		}while(a[i]<pivot && i<=u);
		do
		{
			j--;
		}while(a[j]>pivot);
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}while(i<j);
	a[l]=a[j];
	a[j]=pivot;
	cout<<"\nPartition point: "<<j;
	cout<<"\n\nList: ";
	for(i=l;i<=u;i++)
	{
		cout<<a[i]<<" ";
	}
	return j;
}
int main()
{
	int i,n;
	float a[20];
	qs q;
	cout<<"\n\nEnter no. of elements: ";
	cin>>n;
	cout<<"\n\nEnter array elements: ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	q.quicksort(a,0,n-1);
	cout<<"\n\nSorted array: ";
	cout<<"\n\nDescending order: ";
	for(i=n-1;i>=n-5;i--)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n\nAscending order: ";
	for(i=n-5;i<=n-1;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}


