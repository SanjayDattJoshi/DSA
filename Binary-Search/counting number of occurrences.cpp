//Count Number of Occurrences(use previously written code for finding first and last occurrence)
int countOcc(int arr[], int n, int num){
    pair<int, int> result = occurrenceOfNum_Optimal2(arr, n, num);
    if(result.first == -1) return 0;
    return (result.second - result.first) + 1;
}
