#include <bits/stdc++.h>
using namespace std;

int partitionF(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void qs(int arr[], int low, int high)
{
    if (low < high)
    {
        int pIndex = partitionF(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}
void quick_sort(int arr[], int arr_size)
{
    qs(arr, 0, arr_size - 1);
}
int main()
{
    // Input array size
    int n;
    cout << "Enter size of array:";
    cin >> n;

    // Initializing array with size n
    int arr[n];

    // Input array elements
    cout << endl
         << "Enter array elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Calling merge sort function
    quick_sort(arr, n);

    // Printing sorted array elements
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
    return 0;
}
