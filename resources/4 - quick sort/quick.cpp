#include <iostream>

void quicksort(int array[], int low, int high);
int partition(int array[], int low, int high);

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

    quicksort(array, 0, size - 1);

    std::cout << "sorted array: \n";
    
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}


void quicksort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivotindex = partition(array, low, high);

        quicksort(array, low, pivotindex - 1);
        quicksort(array, pivotindex + 1, high);
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if(array[j] < pivot)
        {
            i++;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[high]);
    return (i + 1);
}
