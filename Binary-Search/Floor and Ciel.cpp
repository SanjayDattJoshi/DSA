//Floor and Ciel (ciel is simple lower bound )
int floor(int arr[], int n, int num){
    int low = 0, high = n-1, ans = -1;
    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid]<= num){
            ans = arr[mid];
            low = mid + 1;
        }
        else high = mid-1;
    }
    return ans;
}
