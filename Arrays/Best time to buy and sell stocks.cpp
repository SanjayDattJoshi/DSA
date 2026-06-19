//Problem - 5--> Best time to buy and sell stocks
int buy_sell(int arr[], int n){
    int mini = arr[0];
    int maxprofit = 0;
    
    for(int i=1; i<n; i++){
        int cost = arr[i] - mini;
        maxprofit = max(cost, maxprofit);
        mini = min(mini, arr[i]);
    }
    return maxprofit;
}
