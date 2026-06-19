// Maximum Rectangle Area with all 1's 
int areaOfRectangle(vector<vector<int>>&arr){
    int n = arr.size();
    int m = arr[0].size();
    vector<int> height(m,0);
    int maxi = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 1) height[j]++;
            else height[j] = 0;
        }
        int area = areaOfLargestRectangleOp(height);
        maxi = max(area, maxi);
    }
    return maxi;
}
