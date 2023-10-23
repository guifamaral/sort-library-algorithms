#include <iostream>

void bubblesort(int array[], int size);

int main()
{
    const int arrsize = 20;
    int array[arrsize];
    int size;

    std::cout<<"array size up to " << arrsize <<" ";
    std::cin >> size;

    if (size <= 0 || size > arrsize)
    {
        std::cout<<"invalid size. size between 1 and " << arrsize << ".\n";
        return 1;
    }

    std::cout<<"enter "<< size << " values for the array:\n";

    for (int i = 0; i < size ; i++)
    std::cin >> array[i];

    std::cout<<"Original array: ";

    for (int i = 0; i < size ; i++)
    {
        std::cout<< array[i] << " ";
    }

    bubblesort(array, size);

    std::cout << "Sorted array: ";
    
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
    
}


void bubblesort(int array[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array [j];
                array[j] = array [j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

