// Problem -Given an m x n matrix, if an element is 0, set its entire row and column to 0. 
//Do it in-place.


// 1.Brute Force Approach --> Time Complexity: O((m × n) × (m + n) + (n x m)) - For each zero, 
// we traverse its row and column
#include <bits/stdc++.h>
using namespace std;
void set_matrix(vector<vector<int>> &arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                for (int k = 0; k < n; k++)
                {
                    if (arr[i][k] != 0)
                    {
                        arr[i][k] = -1;
                    }
                }
                for (int k = 0; k < m; k++)
                {
                    if (arr[k][j] != 0)
                    {
                        arr[k][j] = -1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == -1)
                arr[i][j] = 0;
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
