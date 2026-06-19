//Row with maximum number of 1s in 2D array with sorted rows.

//BruteForce
int findMax1s(vector<vector<int>>arr){

    if (arr.empty() || arr[0].empty()) {
        return -1;  
    }
    int n = arr.size();
    int m = arr[0].size();
    int ind = -1, maxSum = -1;
    
    for(int i=0; i<n; i++){
        int rowSum = 0;
        for(int j = 0; j<m; j++){
            rowSum += arr[i][j];
        }
        if(rowSum>maxSum){
            maxSum = rowSum;
            ind = i;
        }
    }
    return ind;
}

//Optimized (it takes O(n*logm) TC)
int lowerBound(const vector<int>&arr, int n, int target){
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

int findMax1s(vector<vector<int>>&arr){

     if (arr.empty() || arr[0].empty()) {
        return -1;  
    }
    int n = arr.size();
    int m = arr[0].size();
    int ind = -1, maxSum = -1;
    for(int i=0; i<n; i++){
        int rowSum = m-lowerBound(arr[i], m, 1);
        if(rowSum>maxSum){
            maxSum = rowSum;
            ind = i;
        }
    }
    return ind;
}
