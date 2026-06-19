//Kth Missing Positive Number 
//BruteForce
int kthMissingEle(int arr[], int n, int k){
    for(int i=0; i<n; i++){
        if(arr[i]<k) k++;
        else break;
    }
    return k;
}

//Optimal solution
int kthMissingEleOp(int arr[], int n, int k){
   int low = 0, high = n-1, missing;
    while(low<=high){
        int mid = (low+high)/2;
        missing = arr[mid]-(mid+1);
        if(missing<k){
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }
    return k + low;//we can write high + 1 = low here.
}
