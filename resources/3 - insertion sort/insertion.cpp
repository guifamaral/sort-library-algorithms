#include <iostream>

void insertionsort(int array[], int size);

int main()
{
    const int arrsize = 20;
    int array[arrsize];
    int size;

    std::cout<<"array size up to " << arrsize <<" \n";
    std::cin >> size;

    if (size <= 0 || size > arrsize)
    {
        std::cout<<"invalid size. size between 1 and " << arrsize << ".\n";
        return 1;
    }

    std::cout<<"enter "<< size << " values for the array: \n";

    for (int i = 0; i < size ; i++)
    std::cin >> array[i];

    std::cout<<"original array: \n";

    for (int i = 0; i < size ; i++)
    {
        std::cout<< array[i] << " ";
    }
    std::cout<<"\n";

    insertionsort(array, size);

    std::cout << "sorted array: \n";
    
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}


void insertionsort(int array[], int size)
{
    for(int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}
