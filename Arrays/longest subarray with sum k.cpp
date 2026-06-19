
// Problem - 14 --> find longest subarray with sum K.

//BruteForce solution.
//It takes O(n*n*n) TC.
int longest_subarray(int arr[], int n, int sum_equal)
{
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
                
            }
            if (sum == sum_equal)
                    length = max(length, j - i + 1);
        }
    }
    return length;
}

// Optimized brute).
// It takes O(n*n) TC.
int longest_subarray(int arr[], int n, int sum_equal)
{
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == sum_equal)
                length = max(length, j - i + 1);
        }
    }
  return length;
}

// Better solution. and optimal solution if array has -ve values also.
// It takes O(n*n) TC.
int longest_subarray(int arr[], int n, int sum_equal)
{
    long long sum=0;
    int maxlen = 0;
    map<long long, int> mymp;
    for(int i =0; i<n; i++){
        sum += arr[i];
        if(sum == sum_equal){
            maxlen = max(maxlen, i+1);
        }

        long long rem = sum - sum_equal;
        if(mymp.find(rem) != mymp.end()){
            mymp[sum] = i;
        }
        if(mymp.find(sum) == mymp.end()){
            mymp[sum] = i;
        }
    }
    return maxlen;

    // Optimal solution -> takes O(2n) TC at worst case because 
//inner loop not running in every iteration.
int longest_subarray(int arr[], int n, int sum_equal)
{
    int right = 0;
    int left = 0;
    int maxlen = 0;
    long long sum = arr[0];

    while (right < n)
    {
        while (left <= right && sum > sum_equal)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == sum_equal)
        {
            maxlen = max(maxlen, right - left + 1);
        }
        right++;
        if (right < n)
        {
            sum += arr[right];
        }
    }
    return maxlen;
}
}
    }
    return length;
}
