// Find Peak Element in 2D Array
/*Problem Statement: Given a 0-indexed n x m matrix mat where no two adjacent cells are equal, 
find any peak element mat[i][j] and return the array [i, j]. 
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent 
neighbours to the left, right, top, and bottom.
Assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.*/

//BruteForce
vector<int> findPeakElement2D(const vector<vector<int>>& mat){
    if (mat.empty() || mat[0].empty()) {
        return {-1, -1};
    }
    int n = mat.size();
    int m = mat[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int current = mat[i][j]; 
            // Check all 4 neighbors (top, bottom, left, right)
            int top = (i > 0) ? mat[i-1][j] : -1;
            int bottom = (i < n-1) ? mat[i+1][j] : -1;
            int left = (j > 0) ? mat[i][j-1] : -1;
            int right = (j < m-1) ? mat[i][j+1] : -1;
            if(current > top && current > bottom && 
               current > left && current > right){
                return {i, j};
            }
        }
    }
    return {-1, -1}; 
}

//Optimal
int findMaxEleInd(vector<vector<int>> &mat, int n, int m, int col){
    int max = INT_MIN;
    int index = -1;
    for(int i=0; i<n; i++){
          if(mat[i][col]>max){ 
            max = mat[i][col];
            index = i;
          }
    }
    return index;
}
vector<int> findPeakElement2D(const vector<vector<int>>& mat){
    if (mat.empty() || mat[0].empty()) {
        return {-1, -1};
    }
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m-1;
    while(low<=high){
        int mid = (low+high)/2;
        int maxRowEleInd = findMaxEleInd(mat, n, m, mid);
        int left = mid - 1>=0?mat[maxRowEleInd][mid-1]: -1;
        int right = mid + 1<m?mat[maxRowEleInd][mid+1]: -1;
        if(mat[maxRowEleInd][mid] > left && mat[maxRowEleInd][mid]>right){
            return {maxRowEleInd, mid};
        }
        else if(mat[maxRowEleInd][mid]<left) high = mid - 1;
        else low = mid + 1;
    }
    return {-1,-1};
}
