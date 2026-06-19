//Problem - 7 --> Move Zeros to end of array.

//Approach - 1(Brute) -->it will take O(2n) TC and O(x) SC where x is no. of zeros in array.
void move_zeros(int arr[], int n){
    vector<int> temp;
    for(int i=0; i<n; i++){
        if(arr[i] != 0) temp.push_back (arr[i]);
    }
    
    
    for(int i=0; i<temp.size(); i++){
         arr[i] = temp[i];
    }

    for(int i=temp.size(); i<n; i++){
        arr[i]=0;
    }
}

//Approach - 2 (Optimal solution also called two pointer approach)
//takes time complexity of O(n).
void move_zeros(int arr[], int n){
   int i=0;
   for(int j=0; j<n; j++){
    if( arr[j] != 0){
        if(i!=j){
        swap (arr[i], arr[j]);
        }
        i++;
    }
   }
}
