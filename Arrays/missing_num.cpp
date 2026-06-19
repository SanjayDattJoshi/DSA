//Problem - 11 --> Finding Missing number in an array.

//BruteForce Approach --> takes O(n*n) TC.
int missing_num(int arr[], int n){
   for(int i=1; i<=n; i++){
    int flag = 0;
    for(int j=0; j<n; j++){
        if(arr[j] == i){
            flag = 1;
            break;
        }
    }
    if(flag == 0) return i;
   }
}

//Better Solution --> it takes O(2n) TC and O(n) SC.
int missing_num(int arr[], int n){
   int hash[n+1] = {0};
   for(int i=0; i<n-1; i++){
    hash[arr[i]] = 1;
   }

   for(int i=1; i<=n; i++){
    if(hash[i]==0) return i;
   }
}


// Optimal Solution using sum--> it takes O(n) TC.
int missing_num(int arr[], int n)
{
    int sum = n*(n+1)/2;
    int arr_sum=0;
    int result;
    for(int i=0; i<n-1; i++){
        arr_sum += arr[i];
    }
    if(sum!=arr_sum) {
      result = sum-arr_sum;
    }
    return result;
}

//Optimal solution using XOR -->TC is O(n). 
int missing_num(int arr[], int n)
{
    int XOR1 = 0;
    int XOR2 = 0;
    int N=n-1;
    for(int i=0; i<N; i++){
        XOR2 = XOR2^arr[i];
        XOR1 = XOR1^(i+1);
    }
    XOR1 = XOR1^n;

    return XOR1^XOR2;
}
