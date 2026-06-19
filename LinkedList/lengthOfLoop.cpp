//Length of Loop
//BruteForce
int lengthOfLoop(Node* head){
    Node* temp = head;
    map<Node*, int> mpp;
    int timer = 0;
    while(temp != nullptr){
        timer++;
        if(mpp.find(temp) != mpp.end()) return timer-mpp[temp];
        mpp[temp] = timer;
        temp = temp->next;
    }
    return 0;
}

//Optimal(slow and fast pointer)
int lengthOfLoopOp(Node* head){
     Node* fast = head;
    Node* slow = head;
    int count = 0;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){ 
            fast = fast->next;
            count++;
        while(fast != slow){
             count++;
             fast = fast->next;
          }
    return count;
        }
    }
  return count;
}
