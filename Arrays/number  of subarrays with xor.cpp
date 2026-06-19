//Problem - 6 --> Number of Subarrays with XOR K.

//Brute Force --> takes O(n*n*n) TC.
int subarrays_xor(vector<int> arr, int target){
    int count = 0;
    for(int i =0; i<arr.size(); i++){
        for(int j=i; j<arr.size(); j++){
                    int xor_val = 0;
              for(int k=i; k<=j; k++){
                       xor_val ^= arr[k];
              }
        if(xor_val == target) count++;
        }
    }
    return count;
}


//Better solution --> takes O(n*n) TC.
int subarrays_xor(vector<int> arr, int target){
    int count = 0;
    for(int i =0; i<arr.size(); i++){
            int xor_val = 0;
        for(int j=i; j<arr.size(); j++){
            xor_val ^= arr[j];
        if(xor_val == target) count++;
        }
    }
    return count;
}


//Optimal solution --> takes O(n) TC and O(n) SC.
//one more solution 
int subarrays_xor(vector<int> arr, int target){
    int count = 0, preXOR=0;
    map<int, int> mpp;
    mpp[0] = 1;
    for(int i =0; i<arr.size(); i++){
       preXOR ^= arr[i];
       int x = preXOR ^ target;
       count += mpp[x];
       mpp[preXOR]++;
    }
    return count;
}
