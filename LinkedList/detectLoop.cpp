//Detect Loop

//BruteForce
bool loop(Node*head){
    Node* temp = head;
    map<Node*, int> mpp;
    while(temp != nullptr){
        if(mpp.find(temp) != mpp.end()) return true;
        mpp[temp] = 1;
        temp = temp->next;
    }
  return false;
}

//Optimal (using slow and fast pointer)
bool loopOp(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
