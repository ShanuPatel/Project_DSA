
#include "DSA.h"
#include <list>

namespace Testcases
	//arr2[]={6,1,2,3,4}
{	//arr[]={1,2,3,4,5}
	  //index 0,1,2,3,4
	//find union of two array
	void UnionArr(int arr[], int arr2[], int n, int m)
	{
		int i=0;
		int j=0;
		while (i<n && j<m)
		{
			if (arr[i] < arr2[j])
				std::cout << arr[i++] << ' ';
			else if (arr2[j] < arr[i])
				std::cout << arr2[j++] << ' ';

			else
			{
				std::cout << arr2[j++] << ' ';
				i++;
			}
		}
		while (i<n)
		{
			std::cout << arr[i++]<< ' ';
		}
		while (j < m)
		{
			std::cout << arr2[j++] << ' ';
		}
	}






	//min max sof the kth element
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

	int R_Integers(int x)
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
	bool Palin(int x)
	{
		if (x < 0 || (x != 0 && x % 10 == 0))
			return false;
		int sum = 0;
		while (x > sum)
		{
			sum = sum * 10 + x % 10;
			x = x / 10;
		}
		std::cout << x;

		return (x == sum) || (x == sum / 10);
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
		Testcases::Palin(121);
	}
}
class HashTable
{
private:
	static const int Hashtag = 10;
	std::list<std::pair<int, std::string>>table[Hashtag];
public:
	bool bIsEmpty()const;
	int HashFunction(int key);
	void insertitem(int Key, std::string value);
	void removeItem(int key);
	void printTable();
};

int main()
{
	DSA daa;
	//daa.Pub_Excute_fun();
	//Testcases::Vector_Excution();
	//int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
	//int arr[] = { 9, 8, 7, 6, 4, 2, 1, 3 };
	int arr[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 6, 1, 2, 3, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int m = sizeof(arr2) / sizeof(arr2[0]);
	/*Testcases::cycle_by_one(arr, n);*/
	//Testcases::Rearrange_negatives(arr, n);
	Testcases::UnionArr(arr, arr2, n, m);
	/*for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << ' ';
	}*/
	std::cin.get();
}

bool HashTable::bIsEmpty() const
{
	int sum{};
	for (int i{}; i < Hashtag; i++)
	{
		sum += table[i].size();
	}
	if (!sum)
		return true;

	return false;
}

int HashTable::HashFunction(int key)
{
	return key % Hashtag;//return modulas of the hashtable that is reminder of the table in this case
}

void HashTable::insertitem(int Key, std::string value)
{
	int hashvalue = HashFunction(Key);
	auto& cell = table[hashvalue];
	auto Itr = begin(cell);
	bool keyexist = false;
	for (; Itr != end(cell); Itr++)
	{
		if (Itr->first == Key) {
			keyexist = true;
			Itr->second = value;
			std::cout << "Warning: key exists :Value replaced" << '\n';
			break;
		}
	}
	if (!keyexist)
	{
		cell.emplace_back(Key, value);
	}
	return;
}

void HashTable::removeItem(int key)
{
	int hashvalue = HashFunction(key);
	auto& cell = table[hashvalue];
	auto Itr = begin(cell);
	bool keyexist = false;
	for (; Itr != end(cell); Itr++)
	{
		if (Itr->first == key) {
			keyexist = true;
			Itr = cell.erase(Itr);
			std::cout << "Info: Item removed:" << '\n';
			break;
		}
	}
	if (!keyexist)
	{
		std::cout << "Warning: Key not found. Pair not removed." << '\n';
	}
	return;
}

void HashTable::printTable()
{
	for (int i{}; i < Hashtag; i++)
	{
		if (table[i].size() == 0)
			continue;

		auto Itr = table[i].begin();
		for (; Itr != table[i].end(); Itr++)
		{
			std::cout << "Info :Key " << Itr->first << "Value: " << Itr->second << '\n';
		}
	}

	HashTable HT;
	if (HT.bIsEmpty())
	{
		std::cout << "GoodJob: Practice on" << '\n';
	}
	else
	{
		std::cout << "try again" << '\n';
	}
	HT.insertitem(905, "Aran");
	HT.insertitem(905, "raran");
	HT.insertitem(775, "bran");
	HT.insertitem(546, "Eran");
	HT.insertitem(123, "Vran");

	HT.printTable();
	HT.removeItem(123);
	HT.removeItem(100);

	if (HT.bIsEmpty())
	{
		std::cout << "GoodJob: Practice on! Check again" << '\n';
	}
	else
	{
		std::cout << "Good Practice more, try again" << '\n';
	}
}