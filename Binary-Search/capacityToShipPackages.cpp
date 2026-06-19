//Capacity to Ship Packages within D Days

int arrSum(int arr[], int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}
int daysRequired(int arr[], int n, int capacity){
    int days = 1;           
    int currentLoad = 0;   
    for(int i = 0; i < n; i++){
        if(currentLoad + arr[i] <= capacity){
            currentLoad += arr[i];
        } else {
            days++;
            currentLoad = arr[i];
        }
    }
    return days;
}
int capacityToShipPackages(int arr[], int n, int days){
    int low = maxEle(arr, n), high = arrSum(arr, n), ans = high;
    while(low<=high){
            int mid = (low + high)/2;
            if(daysRequired(arr,n,mid)<=days){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
    }
    return ans;
}
