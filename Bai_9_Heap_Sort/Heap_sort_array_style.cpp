#include <iostream>
#include <vector>
using namespace std;

template <class T>
void input_vector(vector<T> &a)
{
    for (size_t i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
}

template <class T>
void heapify(vector<T> &a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

template <class T>
void heapsort(vector<T> &a)
{
    int n = a.size();
    
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    
    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
    
    // Print sorted array
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    input_vector(a);
    heapsort(a);
    return 0;
}

