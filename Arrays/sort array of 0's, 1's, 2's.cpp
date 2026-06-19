//Problem - 2 --> Sort an array of 0's, 1's, 2's

//Brute Force solution we can use sorting algorithms.


//Better solution --> takes O(2n) TC.
void sort_arr(int arr[], int n){
    int count0=0;
    int count1=0;
    int count2=0;

    for(int i=0; i<n; i++){
        if(arr[i]==0) count0++;
        if(arr[i]==1) count1++;
        if(arr[i]==2) count2++;
    }
    for(int i=0; i<count0; i++){
        arr[i] = 0;
    }

       for(int i=count0; i<count0+count1; i++){
        arr[i] = 1;
    }
       for(int i=count0+count1; i<count0+count1+count2; i++){
        arr[i] = 2;
    }
}


//Optimal solution(using dutch national flag algorithm)
//takes O(n) TC.
void sort_arr(int arr[], int n){
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
