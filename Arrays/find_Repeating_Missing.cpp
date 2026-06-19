//Approach - 1
vector<int>find_Repeating_Missing(int arr[], int n){
    int hash[n+1] = {0};
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }
    int repeating = -1, missing = -1;
    for(int i=1; i<=n; i++){
        if(hash[i] == 2) repeating  = i;
        else if(hash[i] == 0) missing = i;

        if(repeating != -1 && missing != -1){
            break;
        }
    }
    return {repeating, missing };
}

//Approach - 2 (Optimal Solution)
vector<int>find_Repeating_Missing(int arr[], int n){
    long long sn = (n*(n+1))/2;
    long long s2n = (n*(n+1) * (2*n+1))/6;
    long long s = 0;
    long long s2 = 0;
    for(int i=0; i<n; i++){
        s+= arr[i];
        s2 += (long long) arr[i]*(long long )arr[i];
    }
    long long val1 = s-sn;
    long long val2 = s2 - s2n;
    val2 = val2/val1;
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int ) x, (int ) y };
}
