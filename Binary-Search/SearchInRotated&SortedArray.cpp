//Search Element in Rotated sorted array
int searchInRotatedSortedArray(int arr[], int n, int num){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low + high) / 2;
        if(arr[mid] == num) return mid;

        //left sorted 
        if(arr[low]<=arr[mid]){
            if(arr[low]<=num && num <= arr[mid]) high = mid-1;
            else low = mid + 1;
        }

        //right sorted
        else {
        if(arr[mid] <= num && num <= arr[high] ) low = mid+1;
        else high = mid - 1;
        }
    }
            return -1; 
}
