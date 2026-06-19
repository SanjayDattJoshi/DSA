// Problem - 4 --> 4 Sum

// Brute Force approach -- > it takes O(n*n*n*n) TC and O(no of quads) SC.
vector<vector<int>> four_sum(vector<int> arr)
{
    int n = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (arr[i] + arr[j] + arr[k] + arr[l]== 0)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        if (st.find(temp) == st.end())
                            st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Better solution --> takes(n*n*n * log M) TC   where M is no. of elements
// in hashset and O(n + 2*no. of unique quads) SC.
 vector<vector<int>> four_sum(vector<int> arr){
     int n = arr.size();
     set<vector<int>> st;
     for(int i=0; i<n; i++){
         for(int j=i+1; j<n; j++){
             set<int> hashset;
            for(int k = j+1; k<n; k++){
             int fourth = -(arr[i] + arr[j] + arr[k]);
             if(hashset.find(fourth) != hashset.end()){
             vector<int> temp = {arr[i], arr[j], arr[k], fourth};
             sort(temp.begin(), temp.end());
             st.insert(temp);
             }
             hashset.insert(arr[k]);
            }
         }
     }
     vector<vector<int>> ans(st.begin(), st.end());
     return ans;
 }

// Optimal solution --> it takes O(nlogn + n*n*n) TC and
// O(no. of unique quads) SC.
vector<vector<int>> four_sum(vector<int> arr)
{
    vector<vector<int>> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j!= i+1  && arr[j] == arr[j - 1])
            continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if (sum < 0)
                    k++;
                else if (sum > 0)
                    l--;
                else
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while (k < l && arr[k] == arr[k - 1])
                        k++;
                    while (k < l && arr[l] == arr[l + 1])
                        l--;
                }
            }
        }
    }
    return ans;
}
