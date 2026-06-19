int findMini(int arr[], int n){
    int low = 0, high = n-1, ans = INT_MAX;
    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid]>=arr[low]){
               ans = min(ans, arr[low]);
               low = mid + 1;
        }
        else{
            ans = min (arr[mid], ans);
            high = mid - 1;
        }
    }
    return ans;
}
