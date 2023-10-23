#include <iostream>

void selectionsort(int array[], int size);

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

    selectionsort(array, size);

    std::cout << "sorted array: \n";
    
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}


void selectionsort(int array[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int minindex = i;
        for(int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minindex])
            {
                minindex = j;
            }
        }
        
        if (minindex != i)
        {
            int temp = array[i];
            array[i] = array[minindex];
            array[minindex] = temp;
        }
    }
}
