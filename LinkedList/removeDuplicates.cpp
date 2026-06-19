//Remove duplicates from sorted DLL
Node* removeDuplicates(Node* head){
    Node* temp = head;
    while(temp!=nullptr && temp->next != nullptr){
        Node* nextNode = temp->next;
        while(nextNode!=nullptr && nextNode->data == temp ->data){
            nextNode = nextNode->next;
        }
        temp->next = nextNode;
        if(nextNode) nextNode->prev = temp;
        temp = temp->next;
    }
    return head;
}
