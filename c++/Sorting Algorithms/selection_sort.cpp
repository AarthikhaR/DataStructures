#include<iostream>
using namespace std;

int swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int n,k,i,j;
	cout<<"Size of the array = ";
	cin >> n;
	int arr[n];
	cout<<"Enter the elements of the array \n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(i = 0; i < n; i++)
	{
		int min_index = i;
		for(j = i+1;j<n;j++)
		{
			if(arr[min_index] > arr[j])
				min_index = j;
		}
		
		swap(&arr[min_index],&arr[i]);

	}
	cout<<"\nSorted array : \n";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	
}
