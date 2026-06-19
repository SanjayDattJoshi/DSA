//Problem - 11 --> Rotate Matrix/Image by 90 Degrees.

//Brute Approach -->
vector<vector<int>> rotate_image(vector<vector<int>> arr){
        int n = arr.size();
        
        vector<vector<int>> result(n, vector<int>(n));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                result[j][(n-1)-i] = arr[i][j];
            }
        }
        return result;
}


//Optimal Approach --> it takes O(n/2 * n/2 + n * n/2) TC.
void rotate_image(vector<vector<int>> &arr){
    int n = arr.size();

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        reverse(arr[i].begin(), arr[i].end());
    }
}
