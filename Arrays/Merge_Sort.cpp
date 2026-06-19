#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void m_sort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    m_sort(arr, low, mid);
    m_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void merge_sort(int arr[], int arr_size)
{

    m_sort(arr, 0, arr_size - 1);
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
    merge_sort(arr, n);

    // Printing sorted array elements
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
    return 0;
}
