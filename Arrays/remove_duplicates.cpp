//Problem - 4 --> Remove duplicates from sorted array.

//Approach - 1

// int remove_dupli(int arr[], int n){
//     set<int> st;
//     for(int i=0; i<n; i++){
//         st.insert(arr[i]);
//     }
//     int index = 0;
//     for(auto it:st){
//         arr[index] = it;
//         index++;
//     }
//     return index;
// }



//Approach - 2
int remove_dupli(int arr[], int n){
    int i=0; 
    for(int j=1; j<n; j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}
