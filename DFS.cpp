#include "DFS.h"

void DFS::R_arr(int arr[], int n )
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

void DFS::Min_max_arr()
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

void DFS::Exution()
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

int main()
{
	DFS daa;
	//daa.Exution();
	daa.Min_max_arr();
}