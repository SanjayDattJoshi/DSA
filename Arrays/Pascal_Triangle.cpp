//Problem - 1 --> Pascal Triangle

// Variation - 1 (Asks for element at i,j position)
// Extreme Brute Force for this is we can calculate ! for each
// term separatly but it takes O(n+r+(n-r)) TC.
// So we use this one which takes O(r) TC.
int func_nCr(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

// Variation - 2 (Asks for print element of a specific row)
// it takes O(n*r) TC.
 void print_row(int row){
     for(int column=1; column<=row; column++){
         cout<<func_nCr(row-1, column-1)<<" ";
     }
 }

// Oprimizing it( now it take O(n) TC)
void print_row(int row)
{
    int res = 1;
    cout << res << " ";
    for (int column = 1; column < row; column++)
    {
        res = res * (row - column);
        res = res / column;
        cout << res << " ";
    }
}


//Variation - 3(printing whole Pascal Triangle) 
//--> it takes O(n*n) TC.
vector<vector<int>> print_Ptriangle(int rows){
    vector<vector<int>> result;  
    for(int i=1; i<=rows; i++){
        vector<int> temp;
        for(int j=1; j<=i; j++){
            temp.push_back(func_nCr(i-1, j-1));
        }
        result.push_back(temp);
    }
    return result;
}
