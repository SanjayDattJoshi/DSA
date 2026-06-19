// Problem -Given an m x n matrix, if an element is 0, set its entire row and column to 0. 
//Do it in-place.

//Better Solution --> takes O(2*n*m) TC and O(n)+O(m) SC.

#include <bits/stdc++.h>
using namespace std;
void set_matrix(vector<vector<int>>&arr, int n, int m){
    int col[m] = {0};
    int row[n] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==0){
                col[j] = 1;
                row[i] = 1;
            }
        }
    }
     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(row[i] || col[j]){
                arr[i][j] =0;
            }
        }
    }
}
  
int main(){
vector<vector<int>> arr2 = {{2, 4, 5},
                                {5, 0, 6},
                                {7, 0, 0}};

    set_matrix(arr2, 3, 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
        
    }
    return 0;
}
