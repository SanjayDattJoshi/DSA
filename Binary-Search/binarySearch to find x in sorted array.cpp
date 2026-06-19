//Recursive approach
int searchRecursion(int arr[], int low, int high, int target){
    if(low>high) return -1;

        int mid = (low + high) /2;
        if(arr[mid] == target) return mid;
        else if(target>arr[mid]) low = mid+1;
        else high = mid - 1;
        return searchRecursion(arr, low, high, target);
}

//Iterative approach
int search(int arr[], int n, int target){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low + high) /2;
        if(arr[mid] == target) return mid;
        else if(target>arr[mid]) low = mid+1;
        else high = mid - 1;
    }
    return -1;
}
