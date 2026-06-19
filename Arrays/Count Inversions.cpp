//BruteForce Solution
int numberOfInversions(int arr[], int n){
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count;
}


//Optimal Solution with TC of O(nlogn) and SC of O(n).
int merge(int arr[], int low, int mid, int high)
{
    int count = 0;
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
            count += (mid-left+1);
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
    return count;
}

int m_sort(int arr[], int low, int high)
{
    int count = 0;
    if (low >= high)
        return count;
    int mid = (low + high) / 2;
    count += m_sort(arr, low, mid);
    count += m_sort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count;
}
int numberOfInversions(int arr[], int n){
    return m_sort(arr, 0, n-1);
}
