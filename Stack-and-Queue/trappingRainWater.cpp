//Trapping rain water
//BruteForce
int trappingRainWaterBr(vector<int> arr){
    int n = arr.size();
    int total = 0;
    for(int i = 1; i < n; i++){
        int leftMax = 0;
        for(int j = 0; j <= i; j++) {
            leftMax = max(leftMax, arr[j]);
        }
        int rightMax = 0;
        for(int j = i; j < n; j++) {
            rightMax = max(rightMax, arr[j]);
        }
        total += min(leftMax, rightMax) - arr[i];
    }
    return total;
} 

//Better
int trappingRainWaterBt(vector<int> arr){
    int n = arr.size();
    int total = 0;
    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);

        leftMax[0] = arr[0];
        for(int j = 1; j <= n-1; j++) {
            leftMax[j] = max(leftMax[j-1], arr[j]);
        }

        rightMax[n-1] = arr[n-1];
        for(int j = n-2; j >=0; j--) {
            rightMax[j] = max(rightMax[j+1], arr[j]);
        }

        for(int j = 0; j < n; j++) {
             total += min(leftMax[j], rightMax[j]) - arr[j];
        }
       
    return total;
} 

//Optimal
int trappingRainWaterOp(vector<int> arr){
    int n = arr.size();
    int total = 0;
    int l = 0, r = n - 1;
    int leftMax = 0;
    int rightMax = 0;
    while(l<r){
        leftMax = max(leftMax, arr[l]);
        rightMax = max(rightMax, arr[r]);

        if(leftMax<rightMax){
            total += leftMax - arr[l];
            l++;
        }
        else{
            total += rightMax - arr[r];
            r--;
        }
    }
    return total;
}
