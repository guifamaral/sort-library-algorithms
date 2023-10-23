#include "sort.h"
#include <iostream>

void sort:: s_bubble(int array[], int size)
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

void sort:: s_shell(int array[], int size)
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

void sort:: s_selection(int array[], int size)
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

void sort:: s_insertion(int array[], int size)
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

void sort:: s_quick(int array[], int low, int high)
{
    if (low < high)
    {
        int pivotindex = partition(array, low, high);

        s_quick(array, low, pivotindex - 1);
        s_quick(array, pivotindex + 1, high);
    }
}



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


void sort:: s_merge (int array[], int size)
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

    s_merge (left, mid);
    s_merge (right, size - mid);

    merge (array, left, mid, right , size - mid);
}

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

void sort:: s_heap(int array[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }

    for (int i = size - 1; i > 0; i--) {
        std::swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

int fmax(int array[], int size)
{
    int fmax = array[0];
        for (int i; i < size; i++)
        {
            if (fmax < array[i])
            {
                fmax=array[i];
            }   
        }
    return fmax;
}

void count(int array[], int size, int exp)
{

    int ten = 10;
    int basedec[ten] = {0};
    int output[size] = {0};

    for (int i = 0; i < size; i++)
    {
        basedec[(array[i]/exp)%ten]++; 
    }
    
    for (int i = 0; i < ten; i++)
    {
        basedec[i] += basedec[i-1]; 
    }        

    for (int i = size - 1; i >= 0; i--)
    {
        output[basedec[array[i]/exp%ten] - 1] = array[i];
        basedec[(array[i]/exp)%ten]--;
    }

    
    for (int i = 0; i < size; i++)
    {
        array[i] = output[i]; 
    }        

}

void sort:: s_radixlsd(int array[], int size)
{
    int max = fmax(array, size);

    for (int exp=1; max/exp > 0; exp*=10)
    {
        count(array, size, exp);
    }
}