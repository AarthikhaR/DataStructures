#include<iostream>
using namespace std;

int main()
{
	int n,i,j;
	cout<<"Size of the array = ";
	cin >> n;
	int arr[n];
	cout<<"Enter the elements of the array \n";
	for(i=0;i<n;i++)
		cin>>arr[i];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	cout<<"Array after sorting: \n";
	for(i=0;i<n;i++)
		cout << arr[i] << " ";
}
