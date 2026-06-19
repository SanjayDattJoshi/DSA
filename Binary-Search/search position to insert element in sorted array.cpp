//Search Insert Position
int searchPosition(int arr[], int n, int target){
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
