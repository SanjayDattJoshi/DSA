//BruteForce Solution
int reverse_Pairs(int arr[], int n){
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>2*arr[j]) count++;
        }
    }
    return count;
}

//Optimal Solution takes O(2*nlogn) TC and O(n) for SC.
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
int countPairs(int arr[], int low, int mid, int high){
    int right = mid+1;
    int count = 0;
    for(int i= low; i<=mid; i++){
        while(right<=high && arr[i]>2*arr[right]) right++;
        count += (right- (mid + 1));
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
    count += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return count;
}
int reverse_Pairs(int arr[], int n){
    return m_sort(arr,0,n-1);
}
