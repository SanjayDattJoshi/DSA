//Find Minimum speed at which koko can eat all bananas
int maxEle(int arr[], int n){
    int max = INT_MIN;
    for(int i=0; i<n; i++){
          if(arr[i]>max) max = arr[i];
    }
    return max;
}

int calculateHours(int arr[], int n, int hourly){
    int totalH = 0;
    for(int i=0; i<n; i++){
        totalH += ceil((double)arr[i]/(double)hourly);
    }
    return totalH;
}
int kokoEatingBanana(int arr[], int n, int deadline){
      int maxi = maxEle(arr, n);
      int low=1, high = maxi;
      while(low<=high){
           int mid = (low+high)/2;
           int totalH = calculateHours(arr, n, mid);
           if(totalH<=deadline) high = mid-1;
           else low = mid+1;
      }
      return low;    
}
