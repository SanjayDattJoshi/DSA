//Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. 
// There are a ‘m’ number of students, and the task is to allocate all the books to the students.
// Allocate books in such a way that:

// Each student gets at least one book.
// Each book should be allocated to only one student.
// Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. 
// If the allocation of books is not possible. return -1

//BruteForce Solution. it takes O((sum-max+1)*n) TC.
int countStu(int arr[], int n, int maxPages){
       int std = 1, pagesStd = 0;
       for(int i=0; i<n; i++){
        if(pagesStd + arr[i]<=maxPages) pagesStd += arr[i];

       else {
        std++;
        pagesStd = arr[i];
        }
    }
        return std;
}
int bookAllocation(int arr[], int n, int std){
    if(std>n) return -1;
    int low = maxEle(arr,n), high = arrSum(arr,n);
    for(int i = low; i<=high; i++){
        int cntStd = countStu(arr, n, i);
        if(cntStd <= std) return i;
    }
    return -1;
}

//Optimal takes O(log2(sum - max + 1)* n) TC.
int bookAllocationOp(int arr[], int n, int std){
    if(std>n) return -1;
    int low = maxEle(arr,n), high = arrSum(arr,n);
    while(low<=high){
        int mid = (low+high) /2;
        if(countStu(arr, n, mid) <= std) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
