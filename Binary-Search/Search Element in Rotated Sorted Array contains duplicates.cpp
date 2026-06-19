//Search Element in Rotated sorted array that contains duplicates
int searchEle(int arr[], int n, int num){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low + high) / 2;
        if(arr[mid] == num) return true;

        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low++; 
            high--;
            continue;
        }

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
            return false; 
}
