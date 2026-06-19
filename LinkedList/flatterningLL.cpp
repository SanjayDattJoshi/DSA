//Flattening a LL

//BruteForce 

// Helper function to collect all nodes recursively
void collectAllNodes(mulNode* node, vector<int>& arr) {
    while(node != nullptr) {
        arr.push_back(node->data);
        if(node->child != nullptr) {
            collectAllNodes(node->child, arr);
        }
        node = node->next;
    }
}

mulNode* flattenLL(mulNode* head){
    vector<int> arr;
    collectAllNodes(head, arr);
    
    sort(arr.begin(), arr.end());

    mulNode* newNode = new mulNode(arr[0]);
    mulNode* mulHead = newNode;
    for(int i = 1; i < arr.size(); i++){
        mulNode* t = new mulNode(arr[i]);
        newNode->child = t;
        newNode = newNode->child;
    }
    return mulHead;
}

//Optimal
mulNode* mergeLL(mulNode* list1, mulNode* list2){
         mulNode* dummyNode = new mulNode(-1);
         mulNode* res = dummyNode;

         while(list1!=nullptr && list2!=nullptr){
            if(list1->data < list2->data){
                res->child = list1;
                res = list1;
                list1 = list1->child;
            }
            else{
                res->child = list2;
                res = list2;
                list2 = list2->child;
            }
            res->next = nullptr;
         }
         if(list1) res->child = list1;
         else res->child = list2;
         if(dummyNode->child) dummyNode->child->next = nullptr;
         return dummyNode->child;
}
mulNode* flattenLLOp(mulNode* mulHead){
    if(mulHead == nullptr || mulHead->next == nullptr) return mulHead;

    mulNode* mergedHead = flattenLLOp(mulHead->next);
    mulHead = mergeLL(mulHead, mergedHead);
    return mulHead;
}
