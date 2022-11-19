#include<iostream>
using namespace std;

int max_array(int arr[],int n)
{
	int max = arr[0];
	for(int i=0;i<n;i++)
	{
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}

int min_array(int arr[],int n)
{
	int min = arr[0];
	for(int i=0;i<n;i++)
	{
		if(arr[i]<min)
			min=arr[i];
	}
	return min;
}


int main()
{
	int n;
	cout<<"Enter the size of the array = ";
	cin >> n;
	int arr[n];
	cout<<"Enter the elements of the array = ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int max = max_array(arr,n);
	int min = min_array(arr,n);
	cout<<"\nMaximum element is  =  "<<max;
	cout<<"\nMinimum element is  =  "<<min;
}
