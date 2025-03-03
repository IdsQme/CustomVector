

#include "vector.h"
#include <iostream>

int main()
{
	// Test 1: Basic
	vector<int> vec;
	vec.p_back(10);
	vec.p_back(20);
	vec.p_back(30);

	std::cout << "Vector after push_back (3 elements): ";
	for (size_t i = 0; i < 3; ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	// Test 2: Copy 
	vector<int> vec_copy = vec;
	std::cout << "Copied vector: ";
	for (size_t i = 0; i < 3; ++i)
	{
		std::cout << vec_copy[i] << " ";
	}
	std::cout << std::endl;

	// Test 3: Erase
	vec.erase(1); 
	std::cout << "Vector after erase (index 1): ";
	for (size_t i = 0; i < 2; ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	// Test 4: Insert
	std::cout << "Vector after insert (value 25 at index 1): ";
	for (size_t i = 0; i < 3; ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	// Test 5: pop_back
	vec.pop_back();
	std::cout << "Vector after pop_back: ";
	for (size_t i = 0; i < 2; ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	// Test 6: operator+
	vector<int> vec2;
	vec2.p_back(5);
	vec2.p_back(10);
	vec.p_back(30);
	vector<int> vec_sum = vec + vec2;
	std::cout << "Vector sum (vec + vec2): ";
	for (size_t i = 0; i < 2; ++i)
	{
		std::cout << vec_sum[i] << " ";
	}
	std::cout << std::endl;

	// Test 7: operator- 
	vector<int> vec_diff = vec - vec2;
	std::cout << "Vector difference (vec - vec2): ";
	for (size_t i = 0; i < 2; ++i)
	{
		std::cout << vec_diff[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

