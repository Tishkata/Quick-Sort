#include <iostream>

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], const int& low, const int& high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(int arr[], const int& low, const int& high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);

        quickSort(arr, pi + 1, high);
    }
}

void printArray(const int arr[], const int& n)
{
    for(int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int array[] = {24, 17, 19, 2, 3, 4, 7, 6, 5};
    const int n = sizeof(array) / sizeof(array[0]);

    quickSort(array, 0, n - 1);

    std::cout << "Quick sorted array: \n";
    printArray(array, n);

    return 0;
}
