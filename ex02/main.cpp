#include <iostream>
#include <string>
#include "Array.hpp"

static void testOutOfBounds(Array<int>& arr, unsigned int index) {
    try {
        arr[index];
        std::cout << "FAIL: no exception thrown for index " << index << std::endl;
    } catch (std::exception& e) {
        std::cout << "PASS: caught out-of-bounds at index " << index
                  << " — " << e.what() << std::endl;
    }
}

int main() {
    // Default constructor
    {
        Array<int> empty;
        std::cout << "Default size: " << empty.size() << std::endl;
        testOutOfBounds(empty, 0);
    }

    // Constructor with n
    {
        Array<int> arr(5);
        std::cout << "Size-5 array size: " << arr.size() << std::endl;
        for (unsigned int i = 0; i < arr.size(); ++i)
            arr[i] = (int)(i * 10);
        for (unsigned int i = 0; i < arr.size(); ++i)
            std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    // Copy constructor — deep copy
    {
        Array<int> original(3);
        original[0] = 1; original[1] = 2; original[2] = 3;
        Array<int> copy(original);
        copy[0] = 99;
        std::cout << "original[0] after copy mutated: " << original[0]
                  << " (expect 1)" << std::endl;
        std::cout << "copy[0]: " << copy[0] << " (expect 99)" << std::endl;
    }

    // Assignment operator — deep copy & self-assignment
    {
        Array<int> a(2);
        a[0] = 7; a[1] = 8;
        Array<int> b(4);
        b = a;
        b[0] = 42;
        std::cout << "a[0] after assign+mutate b: " << a[0]
                  << " (expect 7)" << std::endl;
        std::cout << "b[0]: " << b[0] << " (expect 42)" << std::endl;
        // Self-assignment
        a = a;
        std::cout << "a[1] after self-assign: " << a[1]
                  << " (expect 8)" << std::endl;
    }

    // const operator[]
    {
        Array<int> arr(3);
        arr[0] = 10; arr[1] = 20; arr[2] = 30;
        const Array<int>& cref = arr;
        std::cout << "const cref[1] = " << cref[1] << " (expect 20)" << std::endl;
        try {
            cref[5];
            std::cout << "FAIL: no exception on const out-of-bounds" << std::endl;
        } catch (std::exception& e) {
            std::cout << "PASS: const out-of-bounds caught — " << e.what() << std::endl;
        }
    }

    // Works with non-int type
    {
        Array<std::string> sa(2);
        sa[0] = "hello"; sa[1] = "world";
        std::cout << "string array: " << sa[0] << " " << sa[1] << std::endl;
    }

    return 0;
}
