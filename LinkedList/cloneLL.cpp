//Clone a LinkedList with Next and Random Pointers 
//Bruteforce
Node* cloneLL(Node* head){
    Node* temp = head;
    map<Node*, Node*> mpp;

    while(temp != nullptr){
        Node* newNode = new Node(temp->data);
        mpp[temp] = newNode;
        temp = temp->next;
    }
    temp = head;
    while(temp!=nullptr){
        Node* copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->randomPt = mpp[temp->randomPt];
        temp = temp->next;
    }
    return mpp[head];
}

//Optimal
Node* cloneLLOp(Node* head){
    if (head == nullptr) return nullptr;
    Node* temp = head;
    Node* copyNode = nullptr;
     while(temp!=nullptr){
        copyNode = new Node(temp->data);
        copyNode->next = temp->next;        
        temp->next = copyNode;
        temp = copyNode->next;
     }
    temp = head;
    Node* dummy = new Node(-1);
     while(temp!=nullptr){
        copyNode = temp->next;
       if(temp->randomPt) copyNode->randomPt = temp->randomPt->next;
       temp = temp->next->next;
     }
    
    Node* res = dummy;
    temp = head ;
    while(temp!=nullptr){
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp =temp->next;
    } 
     return dummy->next; 
}
