#include <iostream>

using namespace std;

void MakeHeap(int arr[], int n, int i)
{
	int max = i;

	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[max]) max = l;

	if (r < n && arr[r] > arr[max]) max = r;

	if (max != i)
	{
		swap(arr[i], arr[max]);
		MakeHeap(arr, n, max);
	}
}

void SortArr(int arr[], int n)
{
	for (int i = n/2-1; i >= 0; i--) MakeHeap(arr, n, i);

	for (int i = n-1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		MakeHeap(arr, i, 0);
	}
}


// Управляющая программа
int main()
{
	
	int arr[] = { 0, 0, 0, 0, 0, 0 };
	
	int n = sizeof(arr) / sizeof(arr[0]);

	for (size_t i = 0; i < n; i++)
	{
		arr[i] = rand();
	}

	cout << "Unsorted array is \n";
	for (int i = 0; i < n; ++i) cout << arr[i] << " ";
	cout << "\n";

	SortArr(arr, n);

	cout << "Sorted array is \n";
	for (int i = 0; i < n; ++i) cout << arr[i] << " ";
	cout << "\n";
}