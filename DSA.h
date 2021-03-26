#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

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
};

class BST
{
	int data;
	BST* left;
	BST* right;

	BST* GetNewNode(int data);
	BST* Insert_BST(BST* root, int data);
	bool search_BST(BST* root, int data);

public:

	void Run_BST();
};

//LinkedList
class Node
{
	int data;
	Node* Next;

public:
	int GetData()
	{
		return data;
	}
	void SetData(int Data)
	{
		data = Data;
	}

	Node* GetNext()
	{
		return Next;
	}

	void SetNext(Node* next)
	{
		Next = next;
	}

	Node* Insert(Node** Head, int x)
	{
		Node* temp = new Node();

		temp->SetData(x);
		temp->SetNext(*Head);

		*Head = temp;
		return *Head;
		delete temp;
	}

	void PrintList(Node* Head)
	{
		std::cout << "Data list : ";

		while (Head != nullptr)
		{
			std::cout << " " << Head->GetData();
			Head = Head->GetNext();
		}
		std::cout << "\n";
	}
	void RunLinkedList()
	{
		Node* Head = nullptr;
		int x, n;

		std::cout << "Enter the ListRange:\n";
		std::cin >> n;
		for (int i = 0; i < n; i++)
		{
			std::cout << "Enter The " << i << " Number: \n";
			std::cin >> x;
			Insert(&Head, x);
			PrintList(Head);
		}
	}
};
