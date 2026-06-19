//Finding Middle Node(Bruteforce) -> it takes O(n+n/2) TC.
Node* findMiddle(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        temp = temp->next;
    }
    int middleNode = (cnt/2) + 1;
    temp = head;
    while(temp != nullptr){
        middleNode -= 1;
        if(middleNode == 0) break;
        temp = temp->next;
    }
    return temp;
}

//Finding Middle Node (Optimal) -> it takes O(n/2) TC.
Node* findMiddleOp(Node* head){
   Node* fast = head;
   Node* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
