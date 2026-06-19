//Rearrange array elements by sign. 


//solution if number of positives == negatives
//Brute Force solution. It takes O(2n) TC and O(n) SC.
void rearrange(int arr[], int n){
    vector <int> posi;
    vector <int> nega;

    for(int i=0; i<n; i++){
        if(arr[i]>0) posi.push_back(arr[i]);
        else nega.push_back(arr[i]);
    }
    int posIdx=0;
    int negIdx=0;
    for(int i=0; i<n; i++){
        if(i%2==0&& i<posi.size()) arr[i] = posi[posIdx++];
        else if(i%2!=0&&nega.size()>i) arr[i]= nega[negIdx++];
    }
}

Optimal solution(using vectors it will take O(n) TC and O(n) SC)
void rearrange(int arr[], int n){
    int posInd=0; 
    int negInd=1;
    int result[n];
    for(int i=0; i<n; i++){
        if(arr[i]>0){
            result[posInd] = arr[i];
            posInd += 2;
        }
        else { 
            result[negInd] = arr[i];
            negInd +=2;
        }
    }
    for(int i = 0; i<n; i++){
        arr[i] = result[i];
    }
}

//Solutions if positives != negatives. it takes O(2n) and O(n) SC.
void rearrange(int arr[], int n){
    vector <int> posi;
    vector <int> nega;

    for(int i=0; i<n; i++){
        if(arr[i]>0) posi.push_back(arr[i]);
        else nega.push_back(arr[i]);
    }
    if(posi.size()>nega.size()){
        for(int i=0; i<nega.size(); i++){
            arr[2*i] = posi[i];
            arr[2*i+1] = nega[i];
        }
        int index =  nega.size()*2;
        for(int i=nega.size(); i<posi.size(); i++){
            arr[index] = posi[i];
            index++;
        }
    }
    else{
        for(int i=0; i<posi.size(); i++){
            arr[2*i] = posi[i];
            arr[2*i+1] = nega[i];
        }
        int index =  posi.size()*2;
        for(int i=posi.size(); i<nega.size(); i++){
            arr[index] = nega[i];
            index++;
        }
    }
}
