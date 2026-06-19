//Problem - 9 --> Find union of two sorted arrays.
//it takes TC of O(n1logn + n2logn) + O(n1+n2) and 
//SC O(n1+n2) + O(n1+n2) -> this is for arrunion .
#include <vector>
#include <set>
using namespace std;

vector<int> union_arrays(vector<int>& arr1, vector<int>& arr2){
   set<int> st;
   
   // Insert all elements from arr1
   for(int i = 0; i < arr1.size(); i++){
       st.insert(arr1[i]);
   } 
   
   // Insert all elements from arr2
   for(int i = 0; i < arr2.size(); i++){
       st.insert(arr2[i]);
   }
   
   // Convert set to vector and return
   vector<int> arrunion(st.begin(), st.end());
   return arrunion;
}

// Usage example:
int main(){
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {3, 4, 5, 6, 7};
    
    vector<int> result = union_arrays(arr1, arr2);
    
    // Print result
    for(int x : result){
        cout << x << " ";
    }
    // Output: 1 2 3 4 5 6 7
    
    return 0;
}
