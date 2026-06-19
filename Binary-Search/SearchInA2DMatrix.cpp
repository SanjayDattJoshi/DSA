//Search in a 2D Matrix - I
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

//Optimized
bool searchIn2DArraysOp(vector<vector<int>>arr, int target){
     if (arr.empty() || arr[0].empty()) {
        return -1;  
    }
    int n = arr.size();
    int m = arr[0].size();
    int low = 0, high = (n*m) - 1;
    while(low<=high){
        int mid = (low + high)/2;
        int row = mid/m, column = mid%m;
        if(arr[row][column] == target ) return true;
        else if(arr[row][column]< target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
