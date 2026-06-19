//BruteForce Solution
void Merge_Arrays(int arr1[], int arr2[], int n, int m){
    vector<int> arr3(n + m);  
    int left = 0;
    int right = 0;
    int index = 0;
    
  
    while(left < n && right < m){
        if(arr1[left] <= arr2[right]){
            arr3[index++] = arr1[left++];
        }
        else{
            arr3[index++] = arr2[right++];
        }
    }
    
    // Copy remaining elements
    while(left < n) arr3[index++] = arr1[left++];
    while(right < m) arr3[index++] = arr2[right++];

    // Copy back to original arrays
    for(int i = 0; i < n + m; i++){
        if(i < n) 
            arr1[i] = arr3[i];
        else 
            arr2[i - n] = arr3[i];
    }
}

//Optimal Solution - 1
void Merge_Arrays(int arr1[], int arr2[], int n, int m){
    
    sort(arr2, arr2 + m);
    
    vector<int> arr3(n + m); 
    int left = 0;
    int right = 0;
    int index = 0;
    
    // Merge process
    while(left < n && right < m){
        if(arr1[left] <= arr2[right]){
            arr3[index++] = arr1[left++];
        }
        else{
            arr3[index++] = arr2[right++];
        }
    }
    
    while(left < n) arr3[index++] = arr1[left++];
    while(right < m) arr3[index++] = arr2[right++];


    for(int i = 0; i < n + m; i++){
        if(i < n) 
            arr1[i] = arr3[i];
        else 
            arr2[i - n] = arr3[i];
    }
}

//Optimal Solution- 2
void swapIfGreater(int arr1[], int arr2[], int Ind1, int Ind2){
    if(arr1[Ind1]> arr2[Ind2]) swap(arr1[Ind1], arr2[Ind2]);
}
void Merge_Arrays(int arr1[], int arr2[], int n, int m){
    int len = m+n;
    int gap = len/2 + len%2;
    while(gap>0){
        int left = 0; 
        int right = left + gap;
        while(right < len){
            if(left<n && right>=n){
                 swapIfGreater(arr1, arr2, left, right-n); 
            }
            else if(left>=n){
                 swapIfGreater(arr2, arr2, left-n, right-n); 
            }
            else{
                 swapIfGreater(arr1, arr1, left, right); 
            }
            left++;
            right++;
        }
        if(gap==1) break;
        gap = (gap/2) + gap%2;
    }
}
