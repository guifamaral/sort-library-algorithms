#include <iostream>

void heapify(int array[], int size, int rootIndex) {
    int largest = rootIndex;
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;

    if (leftChild < size && array[leftChild] > array[largest])
        largest = leftChild;

    if (rightChild < size && array[rightChild] > array[largest])
        largest = rightChild;

    if (largest != rootIndex) {
        std::swap(array[rootIndex], array[largest]);
        heapify(array, size, largest);
    }
}

void heapsort(int array[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }

    for (int i = size - 1; i > 0; i--) {
        std::swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

int main()
{
    const int arrsize = 20;
    int array[arrsize];
    int size;

    std::cout << "Array size up to " << arrsize << " \n";
    std::cin >> size;

    if (size <= 0 || size > arrsize)
    {
        std::cout << "Invalid size. Size should be between 1 and " << arrsize << ".\n";
        return 1;
    }

    std::cout << "Enter " << size << " values for the array: \n";

    for (int i = 0; i < size; i++)
        std::cin >> array[i];

    std::cout << "Original array: \n";

    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    heapsort(array, size);

    std::cout << "Sorted array: \n";

    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}