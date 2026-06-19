//Lower Bound
int lowerBound(int arr[], int n, int target){
    int low = 0, high = n-1, ans = n;
    while(low<=high){
        int mid = (low + high) /2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid - 1;
        } 
        else low = mid + 1;
    }
    return ans;
}

//Upper Bound
int upperBound(int arr[], int n, int target){
    int low = 0, high = n-1, ans = n;
    while(low<=high){
        int mid = (low + high) /2;
        if(arr[mid] > target){
            ans = mid;
            high = mid - 1;
        } 
        else low = mid + 1;
    }
    return ans;
}
