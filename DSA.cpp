#include "DSA.h"

#define MAX 500
// minimum number of jump to the end
int DSA::jump_To_end(int arr[], int n)
{
	if (n == 1)
	{
		return 0;
	}
	int res = INT_MAX;

	for (int i = n - 2; i >= 0; i--)
	{
		if (i + arr[i] >= n - 1)
		{
			int sub = jump_To_end(arr, i + 1);
			if (sub != INT_MAX)
			{
				res = std::min(res, sub + 1);
			}
		}
	}
	return res;
}
int DSA::findDuplicate3(std::vector<int>& nums)
{
	if (nums.size() > 1)
	{
		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}
	return -1;
}

//Longest consecutive subsequence
int DSA::Long_subsequnce(int arr[], int n)
{
	int	Init_no = 0;
	int Count = 0;

	std::sort(arr, arr + n);

	std::vector<int>vec;
	vec.push_back(arr[0]);

	for (int i = 1; i < n; i++)
	{
		if (arr[i] != arr[i - 1])
		{
			vec.push_back(arr[i]);
		}
	}
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (i < 0 && vec[i] == vec[i - 1] + 1)
		{
			Count++;
		}
		else
		{
			Count = 1;
		}
		Init_no = std::max(Init_no, Count);
	}
	return Init_no;
}

int DSA::Dupli_no_arr(std::vector<int>& nums)
{
	int temp = {};
	std::sort(nums.begin(), nums.end());
	for (size_t i = 0; i < nums.size(); i++)
	{
		temp = nums[i];
		if (nums[i + 1] == temp)
		{
			std::cout << temp;
		}
	}
	return temp;
}

int DSA::Max_profit(std::vector<int>& prices)
{
	int Max_profit = 0;
	int Min_price = INT_MAX;

	for (size_t i = 0; i < prices.size(); i++)
	{
		Min_price = std::min(Min_price, prices[i]);
		Max_profit = (std::max(Max_profit, prices[i] - Min_price));
	}
	return Max_profit;
}

int DSA::Multiply_fact_largest(int x, int res[], int Size)
{
	int carry = 0;
	for (int i = 0; i < Size; i++)
	{
		int prod = res[i] * x + carry;
		res[i] = prod % 10;
		carry = prod / 10;
	}
	while (carry)
	{
		res[Size] = carry % 10;
		carry = carry / 10;
		Size++;
	}
	return Size;
}

void DSA::Fact_largest(int n)
{
	int res[MAX];
	res[0] = 1;
	int R_size = 1;
	for (int x = 2; x <= n; x++)
	{
		R_size = Multiply_fact_largest(x, res, R_size);
	}
	std::cout << '\n';
	std::cout << "Factorial of given number is \n";
	for (int i = R_size - 1; i >= 0; i--)
		std::cout << res[i];
}

//Count pairs with given sum
int DSA::countpair_sum(int arr[], int n, int sum)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] + arr[j] == sum)
				count++;
		}
	}
	return count;
}

std::vector<int> DSA::RunningSum(std::vector<int>& nums)
{
	for (size_t i = 1; i < nums.size(); i++)
	{
		nums[i] += nums[i - 1];
	}
	return nums;
}

std::string DSA::defangIPaddr(std::string& address)
{
	for (int i = address.size() - 2; i >= 0; i--)
	{
		if (address[i + 1] == '.')
			address = address.substr(0, i + 1) + "[.]" + address.substr(i + 2);
	}
	return address;
}

std::vector<bool> DSA::kidsWithCandies(std::vector<int>& candies, int extraCandies)
{
	std::vector<bool> out;
	int Max = *max_element(candies.begin(), candies.end());
	for (size_t i = 0; i < candies.size(); i++)
	{
		(candies[i] + extraCandies >= Max) ? out.push_back(true) : out.push_back(false);
	}
	return out;
}

int DSA::maximumWealth(std::vector<std::vector<int>>& accounts)
{
	int Richest = 0;
	for (std::vector<int>& customers : accounts)
	{
		Richest = std::max(Richest, std::accumulate(customers.begin(), customers.end(), 0));
	}
	return Richest;
}

std::vector<int> DSA::shuffle(std::vector<int>& nums, int n)
{
	std::vector<int> v;
	int j = n;
	for (int i = 0; i < n; i++)
	{
		v.push_back(nums[i]);
		v.push_back(nums[j]);
		j++;
	}
	return v;
}

int DSA::numIdenticalPairs(std::vector<int>& nums)
{
	int count = 0;
	std::unordered_map<int, int>u_mp;
	for (auto& i : nums)
	{
		count += u_mp[i]++;
	}
	std::cout << count;
	return count;
}

std::vector<int> DSA::decompressRLElist(std::vector<int>& nums)
{
	std::vector<int> ans;
	for (size_t i = 0; i < nums.size(); i += 2)
	{
		ans.insert(ans.end(), nums[i], nums[i += 1]);
	}
	return ans;
}

//commit issue solved
std::string DSA::interpret(std::string command)
{
	std::string ans;
	size_t i = 0;
	while (i < command.size())
	{
		if (command[i] == 'G')
		{
			ans += 'G';
			++i;
		}
		else if (command[i + 1] == ')')
		{
			ans += 'o';
			i += 2;
		}
		else
		{
			ans += "al";
			i += 4;
		}
	}
	return ans;
}
std::string DSA::restoreString(std::string s, std::vector<int>& indices)
{
	std::string S = s;
	for (size_t i = 0; i < indices.size(); i++)
	{
		S[indices[i]] = s[i];
	}
	return s;
}

int DSA::numberOfSteps(int num)
{
	int count = 0;
	while (num != 0)
	{
		if (num % 2 != 1)
		{
			num = num / 2;
			count++;
		}
		if (num % 2 == 1)
		{
			num = num - 1;
			count++;
		}
	}
	return count;
}

std::vector<int> DSA::decode(std::vector<int>& encoded, int first)
{
	std::vector<int> ans;
	size_t i = 0;
	ans.push_back(first);
	while (i < encoded.size())
	{
		ans.push_back(ans[i] ^ encoded[i]);
		i++;
	}
	return ans;
}

int DSA::countMatches(std::vector<std::vector<std::string>>& items, std::string ruleKey, std::string ruleValue)
{
	int count = 0, pos = 0;
	if (ruleKey[0] == 't')
	{
		pos = 0;
	}
	else if (ruleKey[0] == 'c')
	{
		pos = 1;
	}
	else
	{
		pos = 2;
	}
	for (auto& itr : items)
	{
		if(itr[pos]==ruleValue)
		{
			count++;
		}
	}
	return count;
}

std::vector<int> DSA::createTargetArray(std::vector<int>& nums, std::vector<int>& index)
{
	std::vector<int> v;
	for (size_t i = 0; i < index.size(); i++)
	{
		v.insert(v.begin() + index[i], nums[i]);
	}
	return v;
}

int DSA::balancedStringSplit(std::string s)
{
	int count = 0, pair_count = 0;
	for(size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == 'R')
		{
			count++;
		}
		else if (s[i] == 'L')
		{
			count--;
		}
		if (count == 0)
		{
			pair_count++;
		}
	}
	return pair_count;
}

int DSA::xorOperation(int n, int start)
{
	int  ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans ^= start + 2 * i;
	}
	return ans;
}

bool DSA::arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2)
{
	std::string s, s1;
	for (size_t i = 0; i < word1.size(); ++i)
	{
		s += word1[i];
	}
	for (size_t i = 0; i < word2.size(); ++i)
	{
		s1 += word2[i];
	}
	if (s == s1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int DSA::maxDepth(std::string s)
{
	int count = 0, count_pair = 0;
	for (char& i : s)
	{
		if (s[i] == '(')
		{
			count++;
			count_pair += std::max(count, count_pair);
		}
		else if (s[i] == ')')
		{
			count--;
		}
	}
	return count_pair;
}

void DSA::reverseString(std::vector<char>& s)
{
	int i = 0, n = s.size() - 1;
	while(i < n)
	{
		std::swap(s[i++], s[n--]);
	}
}

int DSA::singleNumber(std::vector<int>& nums)
{
	int ans = 0;
	for (int& i : nums)
	{
		ans ^= i;
	}
	return ans;
}

std::vector<std::string> DSA::fizzBuzz(int n)
{
	std::vector<std::string>ans;
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			ans.push_back("FizzBuzz");
		}
		else if (i % 3 == 0)
		{
			ans.push_back("Fizz");
		}
		else if (i % 5 == 0)
		{
			ans.push_back("Buzz");
		}
		else
		{
			ans.push_back(std::to_string(i));
		}
	}
	return ans;
}

int DSA::majorityElement(std::vector<int>& nums)
{
	int count = 0, n = 0;

	for (int i = 0; i < n; i++)
	{
		if (n == 0)
		{
			count = nums[i];
			n = 1;
		}
		else
		{
			if (count == nums[i])
			{
				n++;
			}
			else
			{
				n--;
			}
		}
	}
	return count;
}

int DSA::maxProfit(std::vector<int>& prices)
{
	int max_profit = 0;
	for (size_t i = 1; i < prices.size(); i++)
	{
		if (prices[i] > prices[i - 1])
		{
			max_profit += prices[i] - prices[i - 1];
		}
	 }
	return max_profit;
}

void DSA::moveZeroes(std::vector<int>& nums)
{
	int zeros = 0;
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] != 0)
		{
			nums[zeros++] = nums[i];
		}
	}
	for (size_t i = zeros; i < nums.size(); i++)
	{
		nums[i] = 0;
	}
}

int DSA::titleToNumber(std::string columnTitle)
{
	int ans = 0;
	for (const auto& i : columnTitle)
	{
		ans *= 26;
		ans += i - 'A' + 1;
	}
	return ans;
}

int DSA::romanToInt(std::string s)
{
	std::unordered_map<char, int> nums = {
	  {'I', 1},
	  {'V', 5},
	  {'X', 10},
	  {'L', 50},
	  {'c', 100},
	  {'D', 500},
	  {'M', 1000} };
	int ans = nums[s.back()];
	for (int i = s.length() - 2; i >= 0; --i)
	{
		if (nums[s[i]] < nums[s[i + 1]])
		{
			ans -= nums[s[i]];
		}
		else
		{
			ans += nums[s[i]];
		}
	}
	return ans;
}

std::vector<std::vector<int>> DSA::generate(int numRows)
{
	std::vector<std::vector<int>> res;
	for (int i = 0; i < numRows; i++)
	{
		std::vector<int> rows(i + 1, 1);
		for (int j = 1; j < i; j++)
		{
			rows[j] = res[i - 1][j - 1] + res[i - 1][j];
		}
		res.push_back(rows);
	}
	return res;
}

int DSA::missingNumber(std::vector<int>& nums)
{
	{
		int ans = 0;//(nums.size() + 1) * (nums.size() + 2) / 2;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			ans += (i + 1) - nums[i];
		}
		return ans;
	}
}

int DSA::firstUniqChar(std::string s)
{
	std::vector<int> freq(26, 0);
	for (size_t i= 0; i < s.length(); ++i)
	{
		freq[s[i] - 'a'] += 1;
	}
	for (size_t i = 0; i < s.length(); ++i)
	{
		if(freq[s[i] - 'a'] == 1)
		return i;
	}
	return -1;
}

std::vector<int> DSA::intersect(std::vector<int>& nums1, std::vector<int>& nums2)
{
	std::vector<int> ans;
	std::unordered_map<int, int> u_Map;
	for (size_t i = 0; i < nums1.size(); i++)
	{
		u_Map[nums1[i]]++;
	}
	for (size_t i = 0; i < nums2.size(); i++)
	{
		if (u_Map.find(nums1[i]) != u_Map.end() && --u_Map[nums2[i]] >= 0 )
		{
			ans.push_back(nums2[i]);
		}
	}
	return ans;
}

int DSA::digitSquareSum(int n)
{
	int sum = 0, tmp;
	while (n) {
		tmp = n % 10;
		sum += tmp * tmp;
		n /= 10;
	}
	return sum;
}

bool DSA::isHappy(int n)
{
	int slow, fast;
	slow = fast = n;
	do {
		slow = digitSquareSum(slow);
		fast = digitSquareSum(fast);
		fast = digitSquareSum(fast);
		if (fast == 1) return 1;
	} while (slow != fast);
	return 0;
}

int DSA::climbStairs(int n)
{
	int first = 1, second = 2;
	if (n <= 2)
		return n;
	for (int i = 3; i < n; ++i)
	{
		int temp = second;
		second += first;
		first = temp;
	}
	return (first + second);
}

int DSA::removeDuplicates(std::vector<int>& nums)
{
	int count = 0;

	for (size_t i = 1; i < nums.size(); ++i)
	{
		if (nums[i] == nums[i - 1])
		{
			++count;
		}
		else
		{
			nums[i - count] = nums[i];
		}
	}
	nums.erase(nums.end() - count, nums.end());
	return nums.size();
}

uint32_t DSA::reverseBits(uint32_t n)
{
	uint32_t revRes=0;
	for (int i = 0; i < 32; ++i)
	{
		revRes <<= 1;
		if (n & 1)
		{
			revRes++;
		}
		n >>= 1;
	}
	return revRes;
}

bool DSA::isPowerOfThree(int n)
{
	if (n <= 0 || n > MaxPower)
	{
		return false;
	}
	return MaxPower % n == 0;
}

void DSA::merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
	int i = m - 1, j = n - 1, k = m + n - 1;
	while (j >= 0)
	{
		(i < 0 || nums2[j] >= nums1[i]) ? nums1[k--] = nums2[j--] : nums1[k--] = nums1[i--];
	}
}

bool DSA::isValid(std::string s)
{
	//     Input: s = "()[]{}"
	// Output: true
	std::stack<char> checks;
	for (char& c : s)
	{
		if (c == '(' || c == '{' || c == '[')
		{
			checks.push(c);
		}
		else
		{
			if (checks.empty() || (checks.top() == '(' && c != ')') || (checks.top() == '{' && c != '}') || (checks.top() == '[' && c != ']'))
			{
				return false;
			}
			checks.pop();
		}
	}
	return checks.empty();
}

int DSA::trailingZeroes(int n)
{
	int count = 0;
	for (auto i = 5; n / i > 0; i *= 5)
	{
		count += (n / i);
	}
	return count;
}

bool DSA::isPalindrome(std::string s)
{
	int i = 0, j = s.size() - 1;
	while (i < j)
	{
		if (!isalnum(s[i]))
		{
			i++;
			continue;
		}
		if (!isalnum(s[j]))
		{
			j--;
			continue;
		}
		if (tolower(s[i++]) != tolower(s[j--]))
		{
			return false;
		}
	}
	return true;
}

std::string DSA::longestCommonPrefix(std::vector<std::string>& strs)
{
//Input: strs = ["flower", "flow", "flight"]
//Output : "fl"
	std::string s = "";
	if (strs.size() == 0)
	{
		return s;
	}
	for (size_t i = 0; i < strs[0].size(); i++)
	{
		size_t j = 1;
		while (j < strs.size() && strs[j].size() > i)
		{
			if (strs[j][i] != strs[0][i])
			{
				return s;
			}
			j++;
		}
		if (j == strs.size())
		{
			s += strs[0][i];
		}
	}
	return s;
}

int DSA::mySqrt(int x)
{
	long r = x;
	while (r * r > x)
	{
		r = (r + x / r) / 2;
	}
	return r;
}

int DSA::strStr(std::string haystack, std::string needle)
{
//Input: haystack = "hello", needle = "ll"
//Output : 2
	int m = haystack.size(), n = needle.size();
	for (int i = 0; i < m - n; i++)
	{
		int j = 0;
		while (j < n)
		{
			if (haystack[i + j] != needle[j])
			{
				break;
			}
			j++;
		}
		if (j == n)
		{
			return i;
		}
	}
	return -1;
}

int DSA::countPrimes(int n)
{
//Input: n = 10
//Output : 4
//Explanation : There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
	if (n <= 2) return 0;
	std::vector<bool> passed(n, false);
	int sum = 1;
	double upper = sqrt(n);
	for (int i = 3; i < n; i += 2) {
		if (!passed[i]) {
			sum++;
			//avoid overflow
			if (i > upper) continue;
			for (int j = i * i; j < n; j += i) {
				passed[j] = true;
			}
		}
	}
	return sum;
}

int DSA::maxProfit(int price[], int n)
{
	int* profit = new int[n];
	for (int i = 0; i < n; i++)
	{
		profit[i] = 0;
	}
	int maxPrice = price[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (price[i] > maxPrice)
		{
			maxPrice = profit[i];
		}
		profit[i] = std::max(profit[i + 1], maxPrice - price[i]);
	}
	int minPrice = price[0];
	for (int i = 1; i < n; i++)
	{
		if (price[i] < minPrice)
		{
			minPrice = price[i];
		}
		profit[i] = std::max(profit[i - 1], profit[i] + (price[i] - minPrice));
	}
	int result = profit[n - 1];
	delete[]profit;
	return result;
}

//reverse of array
void DSA::R_arr(int arr[], int n)
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
	std::cout << "Smallest Element :" << arr[0] << "\nLargest Element:" << arr[n - 1];
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
	int arr[] = { 3,2,3 };
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
	int arr[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 6, 1, 2, 3, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int m = sizeof(arr2) / sizeof(arr2[0]);
	std::cout << "MiniumumJumps:" << daa.jump_To_end(arr, n);
	Fact_largest(100);
}

//Douuble Linked list
DNode* DNode::DGetNewNode(int x)
{
	DNode* m_Node = new DNode();

	m_Node->data = x;
	m_Node->Prev = nullptr;
	m_Node->Next = nullptr;
	return m_Node;
}
void DNode::InsertAt(DNode** Head, int x)
{
	DNode* new_Node = DGetNewNode(x);
	new_Node->Next = *Head;
	new_Node->Prev = nullptr;
	if (*Head != nullptr)
	{
		(*Head)->Prev = new_Node;
	}
	*Head = new_Node;
}

void DNode::PrintList(DNode* Head)
{

	DNode* temp = Head;
	std::cout << "Data List:";
	while (temp != nullptr)
	{
		std::cout << " " << temp->data;
		temp = temp->Next;
	}
}
void DNode::ReversePrint(DNode* Head)
{
	DNode* Last = Head;
	if (Head == NULL)
		return;

	while (Head != NULL)
	{
		std::cout << " " << Head->data;
		Last = Head;
		Head = Head->Next;
	}

	std::cout << "\nReverse:";

	std::cout << "\nTraversal in reverse direction \n";
	while (Last != NULL)
	{
		std::cout << " " << Last->data << " ";
		Last = Last->Prev;
	}

	std::cout << std::endl;
}
int DNode::ListCount(DNode* Head)
{
	int count = 0;
	while (Head != nullptr)
	{
		count++;
		Head = Head->Next;
	}
	std::cout << "Number of Elements in the list are: "
		<< count;
	return count;
};
void DNode::DLinkRun()
{
	DNode* Head = nullptr;

	Head->InsertAt(&Head, 2);
	Head->InsertAt(&Head, 4);
	Head->InsertAt(&Head, 6);
	// Head->PrintList(Head);
	Head->ReversePrint(Head);
	Head->ListCount(Head);
	delete Head;
}

std::shared_ptr<BST> BST::BSTGetNewNode(int data)
{
	std::shared_ptr<BST> newNode = std::make_shared<BST>(data);
	newNode->Left = nullptr;
	newNode->Right = nullptr;
	return newNode;
}

void BST::Insert_BST(std::shared_ptr<BST>& root, int data)
{
	if (root == nullptr)
	{
		root = BSTGetNewNode(data);
		return;
	}
	(data > root->data) ? Insert_BST(root->Left, data) : Insert_BST(root->Right, data);
}
void BST::Insert(int data)
{
	Insert_BST(Root, data);
}

bool BST::search_BST(std::shared_ptr<BST>& root, int data)
{
	if (root == nullptr)
		return false;

	else if (root->data == data)
	{
		return true;
	}
	else if (root->data <= data)
	{
		return search_BST(root->Left, data);
	}
	else
	{
		return search_BST(root->Right, data);
	}
}
bool BST::Search(int data)
{
	return search_BST(Root, data);
}

void BST::Run_BST()
{
	Insert(15);
	Insert(55);
	Insert(45);
	Insert(35);
	Insert(25);

	int number;
	std::cout << "Enter the number to be searched\n";
	std::cin >> number;

	(Search(number)) ? std::cout << "Number Found \n" : std::cout << "Not Found\n";
}

int Node::GetData()
{
	return data;
}

void Node::SetData(int Data)
{
	data = Data;
}

Node* Node::GetNext()
{
	return Next;
}

void Node::SetNext(Node* next)
{
	Next = next;
}

Node* Node::Insert(Node** Head, int x)
{
	Node* temp = new Node();

	temp->SetData(x);
	temp->SetNext(*Head);

	*Head = temp;
	return *Head;
}

void Node::AppendList(Node** Head, int Data)
{
	Node* temp = new Node();

	Node* LastNode = *Head;

	temp->SetData(Data);
	temp->SetNext(nullptr);

	if (*Head == nullptr)
	{
		*Head = temp;
		return;
	}
	// else Traverse till last node.

	while (LastNode->GetNext() != nullptr)
	{
		LastNode = LastNode->GetNext();
	}
	LastNode->SetNext(temp);
	return;
}

void Node::PrintList(Node* Head)
{
	std::cout << "Data list : ";

	while (Head != nullptr)
	{
		std::cout << " " << Head->GetData();
		Head = Head->GetNext();
	}
	std::cout << "\n";
}

void Node::InsertAt(Node** Head, int x, int n)
{
	if (n == 0)
	{
		std::cout << "The Given data at 'n' cannot be assigned to null\n";
	}

	Node* temp = new Node();
	temp->SetData(x);
	if (n == 1)
	{
		temp->SetNext(nullptr);
		*Head = temp;
		return;
	}

	Node* temp2 = *Head;
	if (Head == nullptr)
	{
		std::cout << "The Given data cannot be assigned to null\n";
	}
	for (int i = 0; i < n - 2; i++)
	{
		temp2 = temp2->GetNext();
	}

	temp->SetNext(temp2->GetNext());
	temp2->SetNext(temp);
	return;
}

void Node::DeleteNode(Node** Head, int n)
{
	Node* temp = *Head;

	if (n == 1)
	{
		*Head = temp->GetNext();
		delete temp;
		std::cout << "\nAfter Deletion of Head Node\n";
		return;
	}

	for (int i = 0; i < n - 2; i++)
	{
		temp = temp->GetNext();
	}
	Node* temp2 = temp->GetNext();
	temp->SetNext(temp2->GetNext());
	delete temp2;
	std::cout << "\nAfter Deletion of Node\n";
}

void Node::Recursion_Print(Node* Head)
{
	if (Head == nullptr)
	{
		return;
	}

	std::cout << ' ' << Head->GetData(); //comment to Do Reverse the Linked list
	Recursion_Print(Head->GetNext());
	//std::cout << ' ' << Head->GetData();//unComment to Reverse the linked List recursivly
}

int Node::LinkedList_Count(Node* Head)
{
	int count = 0;

	Node* Current = Head;
	while (Current != nullptr)
	{
		count++;
		Current = Current->GetNext();
	}
	std::cout << "\nNumber of Elements: " << count;
	return count;
}

Node* Node::removeNthFromEnd(Node* head, int n)
{
	Node* temp = head, * temp2 = head;
	for (int i = 0; i < n; ++i)
		temp = temp->GetNext();

	// if node is NULL n is equal to the length of the linked list and we have to remove the head
	if (temp == NULL)
		return head->GetNext();

	while (temp->GetNext() != NULL)
	{
		temp = temp->GetNext();
		temp2 = temp2->GetNext();
	}
	temp2->SetNext(temp2->GetNext()->GetNext());
	return head;

}

void Node::RunLinkedList()
{
	Node* Head = nullptr;

	Insert(&Head, 6);
	Insert(&Head, 7);
	Insert(&Head, 8);
	std::cout << "after Appending and inserting\n";
	InsertAt(&Head, 18, 2);
	AppendList(&Head, 16);
	PrintList(Head);
	DeleteNode(&Head, 2);
	std::cout << "Recursive_Print DataList:\n";
	Recursion_Print(Head);
	LinkedList_Count(Head);
	delete Head;
}
