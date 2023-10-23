#include "sort.h"
#include <iostream>

int main() {
    const int arrsize = 10;
    int array[arrsize] = {9, 5, 2, 7, 1, 8, 3, 6, 4, 0};
    int size = arrsize;

    sort sorter; // create an instance of the sort class

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    sorter.s_bubble(array, size); // call the sorting function using the instance

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
