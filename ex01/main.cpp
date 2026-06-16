#include <iostream>
#include <string>
#include "iter.hpp"

template<typename T>
void print(T const& elem) {
	std::cout << elem << " ";
}

template<typename T>
void increment(T& elem) {
	elem++;
}

int main() {
	int intArr[] = {1, 2, 3, 4, 5};
	std::size_t intLen = 5;

	std::cout << "int array:    ";
	iter(intArr, intLen, print<int>);
	std::cout << std::endl;

	iter(intArr, intLen, increment<int>);
	std::cout << "after incr:   ";
	iter(intArr, intLen, print<int>);
	std::cout << std::endl;

	std::string strArr[] = {"hello", "world", "42"};
	std::size_t strLen = 3;

	std::cout << "string array: ";
	iter(strArr, strLen, print<std::string>);
	std::cout << std::endl;

	double dblArr[] = {3.14, 2.71, 1.41};
	std::size_t dblLen = 3;

	std::cout << "double array: ";
	iter(dblArr, dblLen, print<double>);
	std::cout << std::endl;

	const int constArr[] = {10, 20, 30};
	std::size_t constLen = 3;

	std::cout << "const int:    ";
	iter(constArr, constLen, print<int>);
	std::cout << std::endl;

	return 0;
}
