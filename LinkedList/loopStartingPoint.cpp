//Starting point of the loop

//BruteForce
Node* loopStartingPoint(Node*head){
    Node* temp = head;
    map<Node*, int> mpp;
    while(temp != nullptr){
        if(mpp.find(temp) != mpp.end()) return temp;
        mpp[temp] = 1;
        temp = temp->next;
    }
  return nullptr;
}

//Optimal (using tortoise and hare / slow or fast pointer)
Node* loopStartingPointOp(Node*head){
    Node* fast = head;
    Node* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){ 
            slow = head;
        while(fast != slow){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
        }
    }
  return nullptr;
}
