#include "DSA.h"

void DSA::R_arr(int arr[], int n )
{
	int start = 0, end = n - 1;
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

void DSA::Min_max_arr()
{
	int i, j, min_idx;
	int arr[] = { 6,5,4,3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
			std::swap(arr[min_idx], arr[i]);
		}
	}
	std::cout << "Smallest Element :"<<arr[0] << "\nLargest Element:"<<arr[n-1];
}

void DSA::Exution()
{
	int arr[] = { 6,5,4,3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	R_arr(arr, n);

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i];
	}
	std::cout << '\n';
}
namespace Testcases
{
	void Heapify(int arr[], int n, int i) {
		int largest = i;
		int L = 2 * i + 1;
		int R = 2 * i + 2;
		if (L < n && arr[L] > arr[largest])
		{
			largest = L;
		}
		if (R<n && arr[R]>arr[largest])
		{
			largest = R;
		}
		if (largest != i)
		{
			std::swap(arr[i], arr[largest]);
			Heapify(arr, n, largest);
		}
	}
	void arr()
	{
		int arr[] = { 11, 12, 13, 5, 5, 6, 7 };
		int n = sizeof(arr) / sizeof(arr[0]);

		for (int i = 0; i < n; i++)
		{
			arr[i];
			Heapify(arr, n, i);
			std::cout << arr[i] << '\n';
		}
	}
	int partition(int arr[], int l, int r)
	{
		int x = arr[r], i = l;
		for (int j = l; j <= r - 1; j++) {
			if (arr[j] <= x) {
				std::swap(arr[i], arr[j]);
				i++;
			}
		}
		std::swap(arr[i], arr[r]);
		return i;
	}
	// This function returns k'th smallest element in arr[l..r] using
	// QuickSort based method.  ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
	int kthSmallest(int arr[], int l, int r, int k)
	{
		// If k is smaller than number of elements in array
		if (k > 0 && k <= r - l + 1) {
			// Partition the array around last element and get
			// position of pivot element in sorted array
			int pos = partition(arr, l, r);

			// If position is same as k
			if (pos - l == k - 1)
				return arr[pos];
			if (pos - l > k - 1) // If position is more, recur for left subarray
				return kthSmallest(arr, l, pos - 1, k);

			// Else recur for right subarray
			return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
		}

		// If k is more than number of elements in array
		return INT_MAX;
	}

	void swap(int* a, int* b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	// Standard partition process of QuickSort().  It considers the last
	// element as pivot and moves all smaller element to left of it
	// and greater elements to right

	void Print()
	{
		int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
		int n = sizeof(arr) / sizeof(arr[0]), k = 5;
		std::cout << "K'th smallest element is " << kthSmallest(arr, 0, n - 1, k);
	}
}

int main()
{
	//DSA daa;
	//daa.Exution();
	//daa.Min_max_arr();
	Testcases::arr();
	Testcases::Print();
}