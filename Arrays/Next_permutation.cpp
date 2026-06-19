//Problem - 7 --> Next Permutation
void next_permutation(int arr[], int n){
    int pivot = -1;
    for(int i=n-2; i>=0; i--){
        if(arr[i]<arr[i+1]){ pivot = i;
        break;
        }
    }

    if(pivot==-1){
        reverse(arr, arr+n);
        return;
    }

    for(int i =n-1; i>pivot; i--){
        if(arr[i]>arr[pivot]){
            swap(arr[i], arr[pivot]);
            break;
        }
    }

    int i= pivot+1;
    int j= n-1;

    while(i<=j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}
