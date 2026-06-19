//Search in a 2D Matrix - II(every row and column is sorted in iteself)
//BruteForce is same as previous.
//Better solution also same.

//BruteForce
bool searchIn2DArraysBrute(const vector<vector<int>>& arr, int target){
    if (arr.empty() || arr[0].empty()) {
        return false;
    }
    int n = arr.size();
    int m = arr[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == target){
                return true;
            }
        }
    }
    return false;
}

//Better
bool searchIn2DArraysBetter(vector<vector<int>>arr, int target){
     if (arr.empty() || arr[0].empty()) {
        return -1;  
    }
    int n = arr.size();
    int m = arr[0].size();
    
    for(int i = 0; i<n; i++){
        int low = 0, high = m - 1;
        while(low<=high){
        int mid = (low + high)/2;
        if(arr[i][mid] == target ) return true;
        else if(arr[i][mid]< target) low = mid + 1;
        else high = mid - 1;
        }
    }
    return false;
}

//Optimized (it takes O(n+m) TC)
vector<int> SearchIn2DMatrixII(vector<vector<int>>&arr, int target){
     if (arr.empty() || arr[0].empty()) {
        return {-1,-1};  
    }
    int n = arr.size();
    int m = arr[0].size();
    int row = 0 , col = m - 1;
    while(row<n && col>=0){
        if(arr[row][col] == target ) return {row, col};
        else if(arr[row][col]< target) row++;
        else col--; 
    }
   return {-1,-1};
}
