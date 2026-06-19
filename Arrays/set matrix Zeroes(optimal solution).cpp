//Optimal solution
void set_matrix(vector<vector<int>>&arr, int n, int m){
    bool firstRow = false;
    bool firstColumn= false;

    for(int i=0; i<m; i++){
        if(arr[0][i] == 0){
            firstRow = true;
            break;
        }
    }
    for(int i=0; i<n; i++){
        if(arr[i][0] == 0){
            firstColumn = true;
            break;
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(arr[i][j]==0){
                    arr[i][0] = 0;
                    arr[0][j] = 0;
            }
        }
    }
     for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(arr[i][0]==0 || arr[0][j]==0){
                arr[i][j] =0;
            }
        }
    }
    if(firstRow){
        for(int i=0; i<m; i++){
            arr[0][i] = 0;
        }
    }
    if(firstColumn){
        for(int i=0; i<n; i++){
            arr[i][0] = 0;
        }
    }
}
