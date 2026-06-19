//Celibrity Problem
//bruteforce
int celebrityBr(vector<vector<int>>arr){
    int n  = arr.size();
    vector<int> knowsCelebrity(n,0);
    vector<int> celebrityKnows(n,0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 1){
                knowsCelebrity[j]++;
                celebrityKnows[i]++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(knowsCelebrity[i] == n - 1 && celebrityKnows[i] == 0){
            return i;
        }
    }
    return -1;
}

//Optimal
int celebrityOp(vector<vector<int>> arr){
    int n = arr.size();
    int top = 0, down = n-1;
    while(top<down){
        if(arr[top][down]==1) top++;
        else if(arr[down][top] == 1) down--;
        else {
            top++;
            down--;
        }
    }
    if(top>down) return -1;
    for(int i = 0; i<n; i++){
        if(i == top) continue; 
        if(arr[top][i] != 0 || arr[i][top] != 1){
            return -1;
        }
    }
    return top;
}
