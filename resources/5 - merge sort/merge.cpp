#include <iostream>

void merge (int array[], int left[], int leftsize, int right[], int rightsize)
{
    int i = 0, j = 0, k = 0;

    while (i < leftsize && j < rightsize)
    {
        if (left[i] < right[j])
        {
            array[k++] = left[i++];
        }
        else
        {
            array[k++] = right [j++];
        }
    }
    
    while (i < leftsize)
    {
        array[k++] = left[i++];
    }
    
    while (j < rightsize)
    {
        array[k++] = right[j++];
    }

}


void mergesort (int array[], int size)
{
    if (size <= 1)
    {
        return; // already sorted
    }

    int mid = size/2;
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++)
    {
        left[i]=array[i];
    }
    
    for (int i = mid; i < size; i++)
    {
        right[i -  mid]=array[i];
    }

    mergesort (left, mid);
    mergesort (right, size - mid);

    merge (array, left, mid, right , size - mid);
}

int main ()
{
    const int arrsize = 20;
    int array[arrsize];
    int size;

    std::cout<<"array size up to " << arrsize << "\n";
    std::cin>>size;

    if (size <= 0 || size > arrsize)
    {
        std::cout<< "invalid size. size between 1 and " << arrsize << "\n";
        return 1;
    }

    std::cout<< "enter " << size << "values for the array: \n";
    
    for (int i = 0; i < size; i++)
    std::cin >> array[i];
    
    
    for (int i = 0; i < size; i++)
    {
        std::cout<< array[i] << " ";
    }
    std::cout << "\n";

    mergesort(array, size);
    
    std::cout << "sorted array \n";

    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

