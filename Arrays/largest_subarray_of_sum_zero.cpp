// Problem - 5 --> Largest subarray with sum zero.

// Brute Force solution --> it takes O(n*n) TC.
 int Lar_Sub(vector<int> arr){
     int n = arr.size();
     int maxlen = 0;
     for(int i=0; i<n; i++){
         int sum = 0;
         for(int j=i; j<n; j++){
             sum += arr[j];
             if(sum==0){
                 maxlen = max(maxlen, j-i+1);
             }
         }
     }
     return maxlen;
 }

//Better solution --> it takes O(n) TC and SC.
int Lar_Sub(vector<int> arr){
    int n = arr.size();
    int sum = 0;
    int maxlen = 0;
    unordered_map<int, int> mpp;
    
    for(int i = 0; i < n; i++){
        sum += arr[i];
        
        if(sum == 0) {
            maxlen = i + 1;
        }
        
        if(mpp.find(sum) != mpp.end()) {
            maxlen = max(maxlen, i - mpp[sum]);
        }
        else {
            mpp[sum] = i;
        }
    }
    return maxlen;
}


//Optimal Approach --> it takes O(n) TC.
int Lar_Sub(vector<int> arr)
{
    int n = arr.size();
    int sum = 0;
    int maxlen = 0;
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
            maxlen = i + 1;

        else if (mpp.find(sum) != mpp.end())
            maxlen = max(maxlen, i - mpp[sum]);

        else
            mpp[sum] = i;
    }
    return maxlen;
}

//to Print elements also
void Lar_Sub(vector<int> arr)
{
    int n = arr.size();
    int sum = 0;
    int maxlen = 0;
    int startIdx = -1, endIdx = -1;
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0){
            maxlen = i + 1;
            startIdx = 0;
            endIdx = i;
        }
        else if (mpp.find(sum) != mpp.end()){
            int len = max(maxlen, i - mpp[sum]);
            
            if(len>maxlen) {
                       maxlen = len;
                       startIdx = mpp[sum] + 1;
                       endIdx = i;
            }
        }
        else
            mpp[sum] = i;
    }
     cout << "Length: " << maxlen << endl;
    
    if(startIdx != -1) {
        cout << "Subarray: ";
        for(int i = startIdx; i <= endIdx; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "No subarray with sum 0 found" << endl;
    }
}
