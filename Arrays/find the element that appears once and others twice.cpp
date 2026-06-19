// Problem - 13 --> Find the elements that appears once and others twice.

// BruteForce Approach --> it will take O(n*n) TC.
int appear_once(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int num = arr[i];
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == num)
                count++;
        }
        if (count == 1)
            return num;
    }
}

// Better Approach -->if m = n/2+1 is size of the map
// it takes O(nlogm) + O(n/2+1) TC and O(n/2+1) SC.
int appear_once(int arr[], int n)
{
   map<int, int> mymp;

   for(int i=0; i<n; i++){
    mymp[arr[i]]++;
   }
   for(auto it:mymp){
    if(it.second == 1) return it.first;
   }
}

// Optimal Approach --> it will take O(n) TC.
int appear_once(int arr[], int n)
{
   int XOR =0;
   for(int i=0; i<n; i++){
    XOR = XOR ^ arr[i];
   }
   return XOR;
}
