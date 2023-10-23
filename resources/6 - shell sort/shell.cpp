#include <iostream>

void shellsort(int array[], int size);

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

    shellsort(array, size);

    std::cout << "Sorted array: \n";

    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

void shellsort(int array[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}
