//Function that finds nth root of a number

//BruteForce
int power(int num, int n){
      int result = 1;
      for(int i = 0; i < n; i++){
         result *= num;
      }
      return result;
}

int nthRoot(int n, int num){
    for(int i = 1; i < num; i++){
        int pow_result = power(i, n);
        if(pow_result == num){
              return i;
        } 
        else if(pow_result > num) break;  
    }
    return -1;
}

//Optimal solution
int power(int num, int n){
    long long ans = 1;
    while(n>0){
        if(n%2==0){
          n = n/2;
          num = num*num;
        }
        else{
            ans = ans*num;
            n = n-1;
        }
    }
    return ans;
}

int nthRoot(int n, int num){
    int low = 1, high = num;
    while(low<=high){
        int mid = (low + high)/2;
        int midN = power(mid, n);
        if(midN == num) return mid;
        else if(midN<num) low = mid+1;
        else high = mid - 1;
    }
    return -1;
}
