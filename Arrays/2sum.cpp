//Problem - 1 : 2 sum.

//BruteForce approach --> takes O(n*n) TC.
vector<int> two_sum(int arr[], int n, int value){
    vector<int> result;
      for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] + arr[j] == value) {
                result.push_back(arr[i]);
                result.push_back(arr[j]);
                return result;
            }
        }
      }
      return result;
}

// Better approach.it takes O(nlogn) TC.
vector<int> two_sum(int arr[], int n, int value)
{

    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int num1 = arr[i];
        int num2 = value - num1;

        if (mpp.find(num2) != mpp.end())
        {
            return {mpp[num2], i};
        }
        mpp[num1] = i;
    }


  
  //Optimal solution --> O(n) + O(nlogn) TC and we are changing 
//the array here and we cant return indexes easily we have to
//use another array. //so for returnig indexes better solution
//is good.

vector<int>two_sum(int arr[], int n, int value){
    sort(arr, arr+n);
    int left = 0;
    int right = n-1;
    
    while(left<right){
        if(arr[left] + arr[right] < value) left++;
        if(arr[left] + arr[right] > value) right--;
        else return 1;
    }
    return 0;
}

    return {-1, -1};
}
