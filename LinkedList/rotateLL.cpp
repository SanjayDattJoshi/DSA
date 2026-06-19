//Rotate a given linked list
Node* rotateLL(Node* head, int k){
    if(head == nullptr || head->next == nullptr || k == 0) return head;
    
    // Count total nodes and tail will point to last element
    Node* tail = head;
    int count = 1;
    while(tail->next != nullptr){
        count++;
        tail = tail->next;
    }
    
    // If k = 0, k, 2k, 3k .... ans will be given LL
    k = k % count;
    if(k == 0) return head;

    // Traverse LL till the kth node 
    Node* temp = head;
    while(k != 0){
        k--;
        temp = temp->next;
    }
    
    // Connect tail to head (make circular)
    tail->next = head;
    // (k+1)th node becomes new head
    head = temp->next;
    // kth node becomes new tail
    temp->next = nullptr;

    return head;
}
