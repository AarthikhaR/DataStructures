#include<iostream>
using namespace std;

int main()
{
	int n,k;
	cout<<"Size of the array = ";
	cin >> n;
	int arr[n];
	cout<<"Value of k = ";
	cin >> k;
	cout<<"Enter the elements of the array \n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	cout<<"\nThe "<<k<<"th smallest number is = "<<arr[k-1];
	cout<<"\nThe "<<k<<"th largest number is  = "<<arr[n-k];
}
