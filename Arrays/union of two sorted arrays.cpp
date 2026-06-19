//Approach - 2 (2 - pointer approach) it will take O(n1+n2) TC and O(n1+n2) SC.
vector<int> arrays_union(vector<int> arr1, vector<int> arr2){
    vector<int>arr_union;
    int n1 = arr1.size();
    int n2 = arr2.size();

    int j=0; 
    int i=0;
    
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]  ){
            if(arr_union.size()==0||arr_union.back() != arr1[i]){
            arr_union.push_back(arr1[i]);
            }
            i++;
        }
        else{
                if(arr_union.size()==0||arr_union.back() != arr2[j]){
            arr_union.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(j<n2){
        if(arr_union.size()==0||arr_union.back() != arr2[j]){
            arr_union.push_back(arr2[j]);
            }
            j++;
    }
    while(i<n1){
        if(arr_union.size()==0||arr_union.back() != arr1[i]){
            arr_union.push_back(arr1[i]);
            }
            i++;
    }
    return arr_union;
}
