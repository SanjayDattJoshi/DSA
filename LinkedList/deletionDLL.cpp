//Deletion of head
Node* deleteHead(Node* head){
    if(head==nullptr || head->next == nullptr){
        delete head;
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;

    return head;
}

//Deleting Tail of Doubly LL.
Node* deleteTail(Node* head){
    if( head==nullptr || head->next == nullptr ){
        delete head;
        return nullptr;
    }
    Node* tail = head;
    while(tail->next!=nullptr){
        tail= tail->next;
    }
    Node* prev = tail->prev;
    prev->next = nullptr;
    tail->prev = nullptr;
    delete tail;
    return head;
}

//Deleting any element at k position in LL.
Node* deleteEle(Node* head, int pos){
    if( head==nullptr) return nullptr;
    if(pos==1){
        head = deleteHead(head);
        return head;
    }
    Node* temp = head;
    int count = 0;
    while(temp->next != nullptr){
        count++;
        if(count == pos) break;
        temp = temp->next;
    }
    if(temp == nullptr){
        return head;
    }
    Node* prev = temp->prev;
    Node* next = temp->next;
    if(next == nullptr) return deleteTail(head);
    prev->next = next;
    if(next != nullptr){  // Check if not deleting tail
        next->prev = prev;
    }
    delete temp;
    return head;
}

//Deleting a Node
void deleteNode(Node* temp){
    Node* prev = temp->prev;
    Node* next = temp->next;

    if(next == nullptr){
        prev->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return;
    }
        prev->next = next;
        next->prev = prev;
        temp->next = temp->prev = nullptr;
        delete temp;
}  
