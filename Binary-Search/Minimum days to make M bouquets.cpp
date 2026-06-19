// Minimum days to make M bouquets

bool bouquetPossible(int arr[], int n, int day, int totalBouquets, int flowersInBouquet){
    int b = 0;
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] <= day) count++;
        else{
            b += count / flowersInBouquet;
            count = 0;
        }
    }
    b += count / flowersInBouquet;
    return b >= totalBouquets;
}

int maxEle(int arr[], int n){
    int max = INT_MIN;
    for(int i=0; i<n; i++){
          if(arr[i] > max) max = arr[i];
    }
    return max;
}

int minEle(int arr[], int n){
    int min = INT_MAX;
    for(int i=0; i<n; i++){
          if(arr[i] < min) min = arr[i];
    }
    return min;
}
int bouquetBrute(int arr[], int n, int bouquets, int flowers){
    long long required = (long long)bouquets * flowers;
    if(n < required) return -1;
    int mini = minEle(arr, n);
    int maxi = maxEle(arr, n);
    // Check every day from mini to maxi
    for(int day = mini; day <= maxi; day++){
        if(bouquetPossible(arr, n, day, bouquets, flowers)){
            return day;  // Return first day that works
        }
    }
    return -1;
}

//Optimal Solution (It takes O(n*log(max-min+1)) TC.
int bouquetOptimized (int arr[], int n, int bouquets, int flowers){
    long long required = (long long)bouquets * flowers;
    if(n < required) return -1;
    int low = minEle(arr,n);
    int high = maxEle(arr,n);
    int ans;
    while(low<=high){
        int mid = (low + high)/2;
        if(bouquetPossible(arr, n, mid, bouquets, flowers)==false){
             low = mid + 1;
        }
        else {
            high = mid - 1;
            ans = mid;
    }
}
    return low;
}
