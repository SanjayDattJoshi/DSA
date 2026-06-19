
//Problem - 10 --> Intersection of sorted arrays.

//Approach - 1 (Brute) takes O(n1*n2) TC and O(n2+x) where n1 and n2 are sizes of 
//arr1 and arr2 and x is the size of used vector.

vector<int> intersection(vector<int>& arr1, vector<int>& arr2){
    vector<int> result;
    vector<bool> used(arr2.size(), false);  // Track used elements
    
    for(int i = 0; i < arr1.size(); i++){
        for(int j = 0; j < arr2.size(); j++){
            if(arr1[i] == arr2[j] && !used[j]){
                result.push_back(arr1[i]);
                used[j] = true;  // Mark as used to avoid duplicates
                break;
            }
        }
    }
    
    return result;
}

// Approach-2 (using two pointer approach) --> this will take O(n1+n2) TC and also SC.
vector<int> arr_intersection(vector<int> arr1, vector<int> arr2)
{
    int i = 0;
    int j = 0;
    int n = arr1.size();
    int m = arr2.size();
    vector<int> result;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else
        {
            result.push_back(arr1[i]);
                i++;
            j++;
        }
    }
    return result;
}
