#include "DSA.h"

//reverse of array
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

//reverse of integer
int DSA::R_Integers(int x)
{

	int r = 0;
	int sum = 0;
	bool minus = false;
	if (x < 0)
		minus = true;
	while (abs(x) > 0)
	{
		r = abs(x) % 10;
		sum = sum * 10 + r;
		x /= 10;
	}
	if (minus)
		sum *= -1;
	if (sum > INT_MAX || sum < INT_MIN)
		return 0;
	return sum;
}

// max min heap of array
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

//Kadanes algo
int DSA::maxSubArray(std::vector<int>& nums)
{
	int sum = 0;
	int Max = INT_MIN;
	for (auto Itr : nums)
	{
		sum += Itr;
		Max = std::max(sum, Max);
		if (sum < 0)
			sum = 0;
	}
	return Max;
}

//cyclic rotate the array by one
void DSA::cycle_by_one(int arr[], int n)
{
	{
		for (int i = 0; i <= n - 1; i++)
		{
			std::swap(arr[i], arr[n - 1]);
		}
	}
}

//move all negative at the starting of the list
void DSA::Rearrange_negatives(int arr[], int n)
{
	{
		int j = 0;
		for (int i = 0; i <= n - 1; i++)
		{
			if (arr[i] < 0)
			{
				if (i != j)
					std::swap(arr[i], arr[j]);
				else
					j++;
			}
		}
	}
}

//Minimize the maximum difference between the heights
int DSA::getMinDiff(int arr[], int n, int k)
{
	std::sort(arr, arr + n);
	int i, mx, mn, ans;
	ans = arr[n - 1] - arr[0];  // this can be one possible solution

	for (i = 0; i < n; i++)
	{
		if (arr[i] >= k)  // since height of tower can't be -ve so taking only +ve heights
		{
			mn = std::min(arr[0] + k, arr[i] - k);
			mx = std::max(arr[n - 1] - k, arr[i - 1] + k);
			ans = std::min(ans, mx - mn);
		}
	}
	return ans;
}

//sum of two numbers
void DSA::Two_sum()
{
	int arr[] = {3,2,3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 6;
	int i, j;
	int temp_indx, temp_indx2;
	for (i = 0; i < n; i++)
	{
		temp_indx = i;
		//std::cout << arr[temp_indx] << "i ";
		for (j = i + 1; j < n; j++)
		{
			temp_indx2 = j;
			if (arr[temp_indx] + arr[temp_indx2] == k)
			{
				std::cout << "indeies:" << i << " indices:" << j << '\n';
			}
			else
			{
				break;
			}
		}
	}
}

//Two sum problem 4ms brute
std::vector<int> DSA::Two_sum_vector(std::vector<int>& nums, int target)
{
	{
		std::vector<int> results;
		int temp_indx, temp_indx2;
		for (size_t i = 0; i < nums.size(); i++)
		{
			temp_indx = i;
			//std::cout << arr[temp_indx] << "i ";
			for (size_t j = i + 1; j < nums.size(); j++)
			{
				temp_indx2 = j;
				if (i == j)
				{
					continue;
				}
				else
				{
					int sum = nums[temp_indx] + nums[temp_indx2];
					if (sum == target)
					{
						if (results.size() < 2)
						{

							results.push_back(i);
							results.push_back(j);
							std::cout << "indeies:" << i << " indices:" << j << '\n';
						}
						else
						{
							break;
						}
					}
					else
					{
						continue;
					}
				}
				return results;
			}
		}
		return results;
	}
}

void DSA::Rev_Exution()
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

void DSA::Pub_Excute_fun()
{
	DSA daa;
	daa.Two_sum();
}

