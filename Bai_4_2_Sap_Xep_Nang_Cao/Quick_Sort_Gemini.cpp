#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

// Using std::swap is generally better than a custom swap function
// as it can be specialized for different types.

template <class T>
void PrintVector(const std::vector<T> &arr)
{
    for (const auto &elem : arr)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template <class T>
void QuickSortRecursive(std::vector<T> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    // Simple pivot selection (middle element)
    T pivot = arr[left + (right - left) / 2];
    int i = left;
    int j = right;

    while (i <= j)
    {
        // Find element on left that should be on right
        while (arr[i] < pivot)
        {
            i++;
        }
        // Find element on right that should be on left
        while (arr[j] > pivot)
        {
            j--;
        }

        // Swap elements, and move left and right indices
        if (i <= j)
        {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Recurse
    if (left < j)
    {
        QuickSortRecursive(arr, left, j);
    }
    if (i < right)
    {
        QuickSortRecursive(arr, i, right);
    }
}

template <class T>
void QuickSort(std::vector<T> &arr)
{
    if (arr.size() <= 1)
    {
        return; // Already sorted
    }
    QuickSortRecursive(arr, 0, arr.size() - 1);
}

int main()
{
    std::vector<int> data = {8, 7, 2, 1, 0, 9, 6, 4, 3, 5};

    std::cout << "Original array: ";
    PrintVector(data);

    QuickSort(data);

    std::cout << "Sorted array:   ";
    PrintVector(data);

    std::vector<char> char_data = {'z', 'a', 'c', 'b', 'x', 'y'};
    std::cout << "\nOriginal char array: ";
    PrintVector(char_data);

    QuickSort(char_data);

    std::cout << "Sorted char array:   ";
    PrintVector(char_data);

    return 0;
}
