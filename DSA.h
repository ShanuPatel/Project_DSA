#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
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
};

class BST
{
	int data;
	BST* left;
	BST* right;

	BST* BSTGetNewNode(int data);
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
	}
	void AppendList(Node** Head, int Data)
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
	void InsertAt(Node** Head, int x, int n)
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
	void DeleteNode(Node **Head, int n)
    {
        Node *temp = *Head;

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
        Node *temp2 = temp->GetNext();
        temp->SetNext(temp2->GetNext());
        delete temp2;
        std::cout << "\nAfter Deletion of Node\n";
    }
	//Print Listed using Recurstion
	void Recursion_Print(Node* Head)
	{
		if (Head == nullptr)
		{
			return;
		}

		std::cout << ' ' << Head->GetData(); //comment to Do Reverse the Linked list
		Recursion_Print(Head->GetNext());
		//std::cout << ' ' << Head->GetData();//unComment to Reverse the linked List recursivly
	}
	int LinkedList_Count(Node* Head)
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
	void RunLinkedList()
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
