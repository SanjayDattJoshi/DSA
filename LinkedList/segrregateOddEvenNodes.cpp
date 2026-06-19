//Odd Even LL
//Brute
Node* oddEvenLL(Node* head){
    if(head==nullptr || head->next == nullptr) return head;
    vector<int>arr;
    Node* temp = head;
    while(temp!=nullptr&&temp->next!=nullptr){
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    temp = head->next;
     while(temp!=nullptr&&temp->next!=nullptr){
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    int i = 0;
    temp = head;
    while(temp != nullptr){
        temp->data = arr[i++];
        temp = temp->next;
    }
    return head;
}

//Optimal
Node* oddEvenLLOp(Node* head){
    if(head==nullptr || head->next == nullptr) return head;
    Node* odd = head;
    Node*even = head->next;
    Node* evenHead = head->next;
    while(even!=nullptr && even->next!=nullptr){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd= odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
