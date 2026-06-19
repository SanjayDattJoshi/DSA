Problem - 4 --> Maximum subarray sum.

BruteForce solution. it takes O(n*n*n) TC.
int max_sum(int arr[], int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){ 
        for(int j=i; j<n; j++){
            int sum=0;
            for(int k=i; k<=j; k++){
                sum += arr[k];   
            }
                maxi = max(sum,maxi);
        }
    }
    return maxi; 
}


// Better solution. -->takes O(n*n) TC.
int max_sum(int arr[], int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){ 
        int sum=0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            maxi = max(sum,maxi);   
        }   
    }


//Optimal solution(Kedane's Algorithm) --> O(n)
int max_sum(int arr[], int n){
    int sum=0; 
    int maxi = INT_MIN;
    
    for(int i=0; i<n; i++){
     
        sum+= arr[i];

        if(sum>maxi) maxi = sum;
           
        if(sum<0) sum = 0;
    }
    return maxi;
}
    return maxi; 
}
