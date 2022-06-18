/*
* main.cpp
* 2022-06-18
* Collin Abraham
* 
* This program explores the features of C++ 14 
* Many of the changes to this standard were fixes and updates to the changes in C++ 11
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/* cpp14 - auto return type
* allow the compiler to implicitly decide the return type of functions
* 
* This function counts the number of elements within a vector that are even numbers
*/
template<typename VEC_TYPE>
auto count_stuff(const vector<VEC_TYPE>& vec, const int& someValue) {
	const auto theCount = count(begin(vec), end(vec), someValue);
	return theCount; 
}

/* cpp14 - generic lambda parameter types 
* allows lambdas to use generic types within parameters.. more useful templated features
* 
* This function takes a vector<T> by reference, sorts it in descending order then uses a for_each to print the contents 
* both lambdas use generic types 
*/
template<typename VEC_TYPE>
void sort_vec_desc(vector<VEC_TYPE>& vec) {
	sort(begin(vec), end(vec), [](auto& lhs, auto& rhs) { return lhs > rhs; } );

	cout << endl << "After sorting, vector now contains: \n";
	for_each(begin(vec), end(vec), [](const auto x) { cout << x << " "; });
}

/* cpp14 - generic lambda capture types
* allows the capture cause of a lambda to be generic 
* 
* This function calls std::transform on a vector.. 
* in the capture clause there is a generic lambda, declaring "value", and using a lambda to give it the value of 2
* Each element in the vector is then multiplied by value
* In practice this lambda within the capture is pretty ugly and error prone, but here I'm demonstrating that it is a possible functionality
* 
* Note: type of value is decided impliclity based on the return type of the internal lambda 
*/
template<typename VEC_TYPE>
void double_vector(vector<VEC_TYPE>& vec) {
	transform(begin(vec), end(vec), begin(vec),	[value = []() { return 2; }() ](auto& c) { return c * value; });

	cout << endl << "After transforming, vector now contains: \n";
	for_each(begin(vec), end(vec), [](const auto x) { cout << x << " "; });
}

/* cpp14 - constexpr gets an overhaul
* constexpr now allows loops, multiple branches, multiple variable declarations, multiple return statements
* constexpr can call any function as long as it's also a constant expression 
* 
* This function does some arbirary calculations of creating ints, adding them together into a constexpr, 
* using a conditional statement to offer two return options.
* This would not have compiled in cpp11.
*/
constexpr auto cpp14_constexpr() {
	const int someVal1 = 55;
	const int someVal2 = 44;

	constexpr auto newVal = someVal1 + someVal2;
	
	if (newVal % 2 == 0)
		return "Even result";
	else
		return "Odd result";
}

int main() {

	const int testValue = 5;
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	cout << "Occurences of number " << testValue << " in vector: " << count_stuff(vec, testValue) << endl;

	cout << endl << "---------------------" << endl;
	sort_vec_desc(vec);

	cout << endl << "---------------------" << endl;
	double_vector(vec);

	cout << endl << "---------------------" << endl;
	cout << cpp14_constexpr();
}