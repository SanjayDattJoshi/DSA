//Leaders in an array(leader is an element who have everyone
//less than itself on its right side of array)

//Brute Force solution
vector<int> leaders(int arr[], int n){
   
    vector<int> result;
    for(int i=0; i<n; i++){
         bool maxi = true;
        for(int j=i+1; j<n; j++){
                if(arr[i]<arr[j]){ 
                    maxi = false;
                    break;
        }
    }
        if(maxi == true) result.push_back(arr[i]); 
    }
    return result;
}

//Optimal solution. takes O(n) + O(nlogn)(if question asks for sorted result otherwise only n) TC
//and O(n) SC to return.
vector<int> leaders(int arr[], int n){
   int maxi = INT_MIN;
   vector<int> result;
   for(int i=n-1; i>=0; i--){
    if(arr[i]>maxi) result.push_back(arr[i]);
    maxi = max(arr[i], maxi);
   }
   sort(result.begin(), result.end());
    return result;
}
