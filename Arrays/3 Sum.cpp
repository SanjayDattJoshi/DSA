
//Problem - 3 --> 3 Sum (return all unique triplets that gives sum 0.)

//Brute Force approach --> it takes O(n*n*n) TC and O(2*no of triplets) SC.
vector<vector<int>> three_sum(vector<int> arr){
    int n = arr.size();
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i]+arr[j]+arr[k] == 0){
                    vector<int> temp = { arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    if(st.find(temp) == st.end())st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//Better solution --> takes(n*n * log M) TC where no. of elements
//in hashset and O(n + 2*no. of unique triplets) SC.
vector<vector<int>> three_sum(vector<int> arr){
    int n = arr.size();
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        set<int> hashset;
        for(int j=i+1; j<n; j++){
            int third = -(arr[i] + arr[j]);
            if(hashset.find(third) != hashset.end()){
            vector<int> temp = {arr[i], arr[j], third};
            sort(temp.begin(), temp.end());
            st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//Optimal solution --> it takes O(nlogn + n*n) TC and 
//O(no. of unique triplets) SC.
vector<vector<int>> three_sum(vector<int> arr){
    vector<vector<int>> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        if(i>0 && arr[i] == arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        
        while(j<k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum<0) j++;
            else if(sum>0) k--;
            else{
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                k--;
                while(j<k && arr[j] == arr[j-1]) j++;
                while(j<k && arr[k] == arr[k+1]) k--;
            }
        }
    }
    return ans;
}
