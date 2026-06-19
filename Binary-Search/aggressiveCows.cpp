//Aggressive Cows
//BruteForce
bool canWePlace(int arr[], int n, int d, int cows){
          int countCows=1, last = arr[0];
          for(int i=1; i<n; i++){
            if(arr[i]-last>=d){
                countCows++;
                last = arr[i];
            }
          }
          if(countCows>=cows) return true;
          return false;
}
int largestAmongMinis(int arr[], int n, int cows){
    sort(arr, arr+n);
    int ans = -1;
    int range = maxEle(arr, n) - minEle(arr, n);
    for(int i=1; i<=range; i++) {
        if(canWePlace(arr, n, i, cows) == true) ans = i;
        else break;
    }
    return  ans;
}

//Optimal takes O(nlogn + O (log(high))*O(n) TC.
int largestAmongMinisOp(int arr[], int n, int cows){
    sort(arr, arr+n);
    int ans = -1;
    int low=arr[0], high = arr[n-1]-arr[0];
    while(low<=high){
        int mid = (low+high)/2;
        if(canWePlace(arr,n,mid,cows) == true){
            ans = mid;
            low = mid+1;
        }
        else{
              high = mid-1;
        }
    }
    return  ans;
}
