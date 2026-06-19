//Problem - 6 --> Left rotate array by n. 

//Approach - 1 (Brute) --> it will take O(size+n) TC and O(n) SC.

void left_rotate(int arr[], int size,int n){
    int temp[n];
    for(int i=0; i<n; i++){
        temp[i] = arr[i];
    }

    for(int i=n; i<size; i++){
        arr[i-n] = arr[i];
    }

    for(int i=size-n; i<size; i++){
        arr[i] = temp[i-(size-n)];
    }
}

//Approach - 2 (Optimal) -->
void left_rotate(int arr[], int n,int d){
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
}
