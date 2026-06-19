//Maximum Product Sum
//BruteForce Solution
int maxProductSum(int arr[], int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int product = 1;
            for(int k = i; k<j; k++){
                product *= arr[k];
            }
            maxi = max(maxi, product);
        }
    }
    return maxi;
}

//Optimized BruteForce Solution
int maxProductSum(int arr[], int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        int product = 1;
        for(int j=i; j<n; j++){  
                product *= arr[j];   
                maxi = max(maxi, product); 
        }      
    }
    return maxi;
}

//Optimal Solution. It takes O(n) TC.
int maxProductSum(int arr[], int n){
    int maxi = INT_MIN;
    int pre = 1 , suff = 1;
    for(int i=0; i<n; i++){
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;

        pre = pre * arr[i];
        suff = suff * arr[n-i-1];
        maxi = max(maxi, max(pre, suff));
    }
    return maxi;
}
