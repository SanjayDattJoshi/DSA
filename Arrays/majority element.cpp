Problem - 3 --> Majority element(element that appears more than n/2 times).
 

BruteForce solution. it takes O(n*n) TC.

int majority_ele(int arr[], int n){
    int count=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i]==arr[j]) count++;
        }
        if(count>n/2) return arr[i];
    }
}


Better solution. it takes O(nlogn) + O(n) TC and O(n) SC.
int majority_ele(int arr[], int n){
    map<int, int>mpp;
    for(int i=0; i<n; i++){//takes O(nlogn) TC.
        mpp[arr[i]]++;
    }

    for(auto it:mpp){
        if(it.second>n/2) return it.first;
    }
    return -1; 
}


//Optimal solution -->Moore's Voting Algorithm. it takes O(n) TC.
int majority_ele(int arr[], int n){
   int cnt=0;
   int ele=0;

   for(int i=0; i<n; i++){
    //this loop does'n guarantee a mojority
    //element it gives potential candidate only.
    if(cnt==0){
        cnt = 1;
        ele= arr[i];
    }
    else if(arr[i] == ele) cnt++;

    else cnt--;
   }

   int cnt2=0;
   for(int i=0; i<n; i++){
    if(arr[i]==ele) cnt2++;
   }
   if(cnt2>n/2) return ele;
   else return -1;
}
