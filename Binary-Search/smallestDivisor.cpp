//Find the Smallest Divisor Given a Threshold
//BruteForce
int smallestDivisor(int arr[], int n, int thrashhold){
    for(int i=1; i<=maxEle(arr, n); i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            sum += ceil((double)arr[j]/i);
        }
        if(sum<=thrashhold) return i;
    }
    return -1;
}

//Optimal Solution
int countSum(int arr[], int n, int divisor){
    int sum = 0;
    for(int i=0; i<n; i++){
         sum += ceil((double)arr[i]/divisor);
    }
    return sum;
}
int smallestDivisorBS(int arr[], int n, int thrashhold){
    if(n>thrashhold) return -1;
    int low = 1, high =  maxEle(arr,n), ans = -1;
    while(low<=high){
        int mid = (low + high)/2;
        if(countSum(arr, n, mid)<=thrashhold) {
            ans =  mid;
            high = mid-1;
        }
        else low = mid + 1;
    }
    return ans;
}
