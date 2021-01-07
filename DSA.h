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

public:

	void Rev_Exution();
	void Pub_Excute_fun();
};
