
#include "DSA.h"

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
	void Heapify()
	{
		int arr[] = { 11, 12, 13, 5, 5, 6, 7 };
		int n = sizeof(arr) / sizeof(arr[0]);
		int i(0);
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
		std::cout << "Max_Heapify: ";
		for (int i = 0; i < n; i++)
		{
			arr[i];
			Heapify(arr, n, i);
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
	}

	void Heapsort()
	{
		int arr[] = { 11, 12, 13, 5, 5, 6, 7 };
		int n = sizeof(arr) / sizeof(arr[0]);
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			Heapify(arr, n, i);
			std::cout << arr[i] << '\n';
		}
		for (int i = n - 1; i > 0; i--)
		{
			std::swap(arr[0], arr[i]);
			Heapify(arr, i, 0);
		}
		for (int i = 0; i < n; i++)
		{
			arr[i];
			std::cout << arr[i] << ' ';
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

	int kthSmallest(int arr[], int l, int r, int k)
	{
		// If k is smaller than number of elements in array
		if (k > 0 && k <= r - l + 1) {
			int pos = partition(arr, l, r);

			// If position is same as k
			if (pos - l == k - 1)
				return arr[pos];
			if (pos - l > k - 1)
				return kthSmallest(arr, l, pos - 1, k);

			return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
		}
		return INT_MAX;
	}

	void swap(int* a, int* b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	void Print()
	{
		int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
		int n = sizeof(arr) / sizeof(arr[0]), k = 5;
		std::cout << "K'th smallest element is " << kthSmallest(arr, 0, n - 1, k);
	}

	void Vector_Excution()
	{
		std::vector<int> nums = { 3,2,3 };
		/*nums.push_back(2);
		nums.push_back(7);
		nums.push_back(11);
		nums.push_back(15);*/
		int target = 6;
		//Testcases::Two_sum_vector(nums, target);
		//std::cout << "indeies:" << i << " indices:" << j << '\n';

	}
}

int main()
{
	DSA daa;
	daa.Pub_Excute_fun();
	Testcases::Vector_Excution();
}