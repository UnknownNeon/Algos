#include <iostream>
#include <vector>

namespace sort
{
    void swap(int *a, int *b)
    {
        int temp = *b;
        *b = *a;
        *a = temp;
    }
    int partition(std::vector<int> &arr, int low, int high) // High and low includes 0
    {
        int pivot = arr[low];
        int j = low;

        for (int i = j; i <= high; i++)
        {
            if (arr[i] < pivot)
            {
                j++;
                sort::swap(&arr[j], &arr[i]);
            }
        }

        sort::swap(&arr[low], &arr[j]);
        return j;
    };
    void quicksort(std::vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int part = sort::partition(arr, low, high);

            quicksort(arr, low, part - 1);
            quicksort(arr, part + 1, high);
        }
    };
}

// Driver code :
int main()
{

    std::vector<int> arr = {6, 6, 6, 6, 21, 325, 64, 1, 5, 4, 3, 2, 1};
    std::cout << "Unsorted array : " << std::endl;
    for (int i : arr)
    {
        std::cout << i << " " << std::endl;
    }

    sort::quicksort(arr, 0, arr.size() - 1);

    std::cout << "Sorted Array " << std::endl;
    for (int i : arr)
    {
        std::cout << i << " " << std::endl;
    }
}