/First and Last Occurrences in Array

//BruteForce it takes O(n) TC.
pair <int, int>occurenceOfNum_Brute (int arr[], int n, int num){
         int firstOcc = -1, lastOcc = -1;
         for(int i=0; i<n; i++){
            if(arr[i] == num){
                if(firstOcc == -1) firstOcc = i;
                lastOcc = i;
            }
         }
         return {firstOcc, lastOcc};
}

//Optimal(using lower bound and upper bound that is written previously)
//it takes O(2*logn) TC.
pair <int, int>occurenceOfNum_Optimal (int arr[], int n, int num){
         int lb = lowerBound(arr, n, num);
         if((lb == n) || arr[lb] != num) return {-1, -1};

         return {lb, upperBound(arr, n, num)-1};
}

//Optimal 2 (using plain binary search)
int firstOcc(int arr[], int n, int num){
    int low = 0, high = n-1;
         int firstOcc = -1;
         while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] == num) {
                firstOcc = mid;
                high = mid - 1;
            }
            else if(arr[mid]<num) low = mid+1;
            else high = mid-1;
         }
         return firstOcc;
}
int lastOcc(int arr[], int n, int num){
    int low = 0, high = n-1;
         int lastOcc = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] == num) {
                lastOcc = mid;
                low = mid + 1;
            }
            else if(arr[mid]<num) low = mid+1;
            else high = mid-1;
         }
         return lastOcc;
}
pair <int, int>occurrenceOfNum_Optimal2 (int arr[], int n, int num){
        
        int first= firstOcc(arr, n, num);
        if(first == -1) return {-1, -1};
        int last = lastOcc(arr, n, num);
        return {first, last};
}
