#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <memory>
#include <numeric>
#include<stack>
#include <list>
#include<unordered_map>

class DSA
{
	int const MaxPower = 1162261467;
	//Reverse an array
	void R_arr(int arr[], int n);
	int R_Integers(int x);
	void Two_sum();
	std::vector<int> Two_sum_vector(std::vector<int>& nums, int target);
	void Min_max_arr();
	int maxSubArray(std::vector<int>& nums);
	void cycle_by_one(int arr[], int n);
	void Rearrange_negatives(int arr[], int n);
	int getMinDiff(int arr[], int n, int k);
	int jump_To_end(int arr[], int n);
	int findDuplicate3(std::vector<int>& nums);
	int Long_subsequnce(int arr[], int n);
	int Dupli_no_arr(std::vector<int>& nums);
	int Max_profit(std::vector<int>& prices);

	// This function finds factorial of large numbers
	int Multiply_fact_largest(int x, int res[], int Size);
	void Fact_largest(int n);

	int countpair_sum(int arr[], int n, int sum);
public:
	void Rev_Exution();
	void Pub_Excute_fun();
	//Maximum profit by buying and selling a share at most twice
	int maxProfit(int price[], int n);
	//Running Sum of 1d Array
	std::vector<int> RunningSum(std::vector<int>& nums);
	//Defanging an IP Address
	std::string defangIPaddr(std::string& address);
	//Kids With the Greatest Number of Candies
	std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies);
	//Richest Customer Wealth
	int maximumWealth(std::vector<std::vector<int>>& accounts);
	//Shuffle the Array
	std::vector<int> shuffle(std::vector<int>& nums, int n);
	//Number of Good Pairs
	int numIdenticalPairs(std::vector<int>& nums);
	//Design Parking System
	struct ParkingSystem
	{
		std::vector<int> count;

		ParkingSystem(int big, int medium, int small)
		{
			count = { big, medium, small };
		}

		bool addCar(int carType)
		{
			return count[carType - 1]-- > 0;
		}
	};
	//Decompress Run-Length Encoded List
	std::vector<int> decompressRLElist(std::vector<int>& nums);
	//Goal Parser Interpretation
	std::string interpret(std::string command);
	//Shuffle String
	std::string restoreString(std::string s, std::vector<int>& indices);
	//Number of Steps to Reduce a Number to Zero
	int numberOfSteps(int num);
	// Decode XORed Array
	std::vector<int> decode(std::vector<int>& encoded, int first);
	//Count Items Matching a Rule
	int countMatches(std::vector<std::vector<std::string>>& items, std::string ruleKey, std::string ruleValue);
	//Create Target Array in the Given Order
	std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index);
	//Split a String in Balanced Strings
	int balancedStringSplit(std::string s);
	//XOR Operation in an Array
	int xorOperation(int n, int start);
	//Check If Two String Arrays are Equivalent
	bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2);
	//Maximum Nesting Depth of the Parentheses
	int maxDepth(std::string s);
	// Reverse String
	void reverseString(std::vector<char>& s);
	//Single Number
	int singleNumber(std::vector<int>& nums);
	//Fizz Buzz
	std::vector<std::string> fizzBuzz(int n);
	//Majority Element
	int majorityElement(std::vector<int>& nums);
	//Best time to buy and sell the stock II;
	int maxProfit(std::vector<int>& prices);
	//Move Zeroes
	void moveZeroes(std::vector<int>& nums);
	//Excel Sheet Column Number
	int titleToNumber(std::string columnTitle);
	//Roman to Integer
	int romanToInt(std::string s);
	//Pascal's Triangle
	std::vector<std::vector<int>> generate(int numRows);
	// missing number;
	int missingNumber(std::vector<int>& nums);
	//First Unique Character in a String
	int firstUniqChar(std::string s);
	//Intersection of Two Arrays II
	std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2);
	//Happy number
	int digitSquareSum(int n);
	bool isHappy(int n);
	//Climbing Stairs //dyanmic programming
	int climbStairs(int n);
	//Remove Duplicates from Sorted Array
	int removeDuplicates(std::vector<int>& nums);
	//Reverse bits of a given 32 bits unsigned integer.
	uint32_t reverseBits(uint32_t n);
	//Power of Three
	bool isPowerOfThree(int n);
	//Merge two sorted arrays
	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
	//valid parenthesise
	bool isValid(std::string s);
	//Factorial Trailing Zeroes
	int trailingZeroes(int n);
	//Valid Palindrome
	bool isPalindrome(std::string s);
	//Longest Common Prefix
	std::string longestCommonPrefix(std::vector<std::string>& strs);
	//Sqrt(x)
	int mySqrt(int x);
	//Implement strStr()
	int strStr(std::string haystack, std::string needle);
	//count primes
	int countPrimes(int n);
	//Maximum population year
	int maximumPopulation(std::vector<std::vector<int>>& logs); 
};
//Range Sum of BST
class TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	int res = 0;

public:
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* Left, TreeNode* Right) : val(x), left(Left), right(Right) {}

	TreeNode* InsertNode(TreeNode* Root, int data)
	{
		if (Root == nullptr)
		{
			return Root = new TreeNode(data);
		}
		(data < Root->val) ? Root->right = InsertNode(Root->right, data) : Root->left = InsertNode(Root->left, data);
		return Root;
	}

	int rangeSumBST(TreeNode* root, int low, int high)
	{
		if (root == NULL)
			return 0;
		if (root->val >= low and root->val <= high)
			res += root->val;

		rangeSumBST(root->left, low, high);
		rangeSumBST(root->right, low, high);

		return res;
	}

public:
	void printBT(const std::string& prefix, const TreeNode* node, bool isLeft)
	{
		if (node != nullptr)
		{
			std::cout << prefix;

			std::cout << (isLeft ? "|-" : "|_");

			// print the value of the node
			std::cout << node->val << std::endl;

			// enter the next tree level - left and right branch
			printBT(prefix + (isLeft ? "|   " : "    "), node->left, true);
			printBT(prefix + (isLeft ? "|   " : "    "), node->right, false);
		}
	}
	void printBT(const TreeNode* node)
	{
		printBT("", node, false);
	}
};

class BST
{
	int data{};
	std::shared_ptr<BST> Root;
	std::shared_ptr<BST> Left;
	std::shared_ptr<BST> Right;

	std::shared_ptr<BST> BSTGetNewNode(int data);
	void Insert_BST(std::shared_ptr<BST>& root, int data);
	bool search_BST(std::shared_ptr<BST>& root, int data);


public:
	BST() {};
	BST(int data) :data(data), Left(nullptr), Right(nullptr) {}
	void Insert(int data);
	bool Search(int data);
	void Run_BST();
};

//LinkedList
class Node
{
	int data;
	Node* Next;

public:
	int GetData();

	void SetData(int Data);
	Node* GetNext();
	void SetNext(Node* next);
	Node* Insert(Node** Head, int x);
	void AppendList(Node** Head, int Data);
	void PrintList(Node* Head);
	void InsertAt(Node** Head, int x, int n);
	void DeleteNode(Node** Head, int n);
	//Print Listed using Recurstion
	void Recursion_Print(Node* Head);
	int LinkedList_Count(Node* Head);
	Node* removeNthFromEnd(Node* head, int n);
	void RunLinkedList();

};

class DNode
{
public:
	int data;
	DNode* Prev;
	DNode* Next;

public:
	DNode* DGetNewNode(int x);
	void InsertAt(DNode** Head, int x);
	void PrintList(DNode* Head);
	void ReversePrint(DNode* Head);
	int ListCount(DNode* Head);
	void DLinkRun();
};


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

