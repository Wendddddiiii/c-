#include <iostream>
#include <vector>

int main() {
	std::vector<int> temperatures = {32, 34, 33, 28, 35, 28, 34};

	for (int i = 0; i < temperatures.size(); ++i) { // (*)
		std::cout << temperatures.at(i) << " ";
	}
	std::cout << "\n";

	for (const auto &temp : temperatures) {         // (^)
		std::cout << temp << " ";
	}
	std::cout << "\n";

	for (auto iter = temperatures.cbegin(); iter != temperatures.cend(); ++iter) { // (&)
		std::cout << *iter << " ";
	}
	std::cout << "\n";
}
//Why is the for-loop marked with an (*) potentially more unsafe than the others?
//1. It is a C-style for-loop, and the comparison of signed vs. unsigned integers can produce surprising results.
// it directly accesses elements using an index (i) and the .at(i) function. 
//If the index i goes out of the valid range (0 to temperatures.size() - 1), it results in undefined behavior. 
// Using .at(i) involves an additional bounds check compared to direct element access (temperatures[i])

//2. We want to iterate through temperatures in reverse. Which loop in this code is easiest to change and why?
// (&): just change the cbegin and cend to rbegin and rend.

//3. What differences, if any, are there between temperatures.begin() and temperatures.rend()
// An end-iterator, whether from end() or rend() is "one-past-the-end", and so is never dereferenceable, unlike begin().


//begin()  v.s. cbgein()
//begin() is for non-const containers returns an iterator
//cbegin() always returns a const_iterator, c stands for const, regardless of the container is const or non-const

//forward iterators: can be incremented(moved forward), can be dereferenced, can be compared for equality
//bidirectional iterators: have all capabilities of forward iterators, can also be decremented(moved backward) 

//std::set provides bidirectional iterators.
//std::list<int> li, which is a standard doubly-linked list of integers.

//find searches for an exact value
// find_if searches based on a condition



