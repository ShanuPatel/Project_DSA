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

public:

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
