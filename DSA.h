#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <memory>
#include <list>

class DSA
{
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
	//Maximum profit by buyingand selling a share at most twice
	int maxProfit(int price[], int n);
	void Rev_Exution();
	void Pub_Excute_fun();
	//Running Sum of 1d Array
	std::vector<int> RunningSum(std::vector<int>& nums);
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

