#include <iostream>

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

void radix(int array[], int size)
{
    int max = fmax(array, size);

    for (int exp=1; max/exp > 0; exp*=10)
    {
        count(array, size, exp);
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

    radix(array, size);

    std::cout << "Sorted array: \n";

    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

