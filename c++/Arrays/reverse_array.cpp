#include<iostream>
using namespace std;
 
void reverse(int arr[],int start,int end)
{
	int  n = end+1;
	while(start<end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
	cout<<"\nArray after reversing : \n";
	for(int i=0;i<n;++i)
		cout<<arr[i]<<" ";
}
int main()
{
	int i,n;
	cout << "Enter the size of the array = ";
	cin >> n;
	int arr[n];
	cout << "Enter the elements of the array : ";
	for(i=0;i<n;++i)
		cin >> arr[i];
	cout << "\nArray before reversing : \n";
	for(i=0;i<n;++i)
		cout << arr[i]<<" ";
	reverse(arr,0,n-1);
}
