//Reverse LL in group of given size K
Node *reverseLLOp(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
 Node* findKthNode(Node* head, int k){
    Node* temp = head;
    while(temp!=nullptr && k>0){
        k--;
        temp= temp->next;
    }
    return temp;
 }
Node* reverseLLInKGroup(Node* head, int k){
    Node* temp = head;
    Node*nextNode;
    Node* prevNode=nullptr;
    while(temp!=nullptr){
        Node* KthNode = findKthNode(temp, k-1);
        if(KthNode==nullptr){ 
            if(prevNode) prevNode->next = temp;
            break;
        }
        Node* nextNode= KthNode->next;
        KthNode->next = nullptr;
        reverseLLOp(temp);
        if(temp == head) head = KthNode;
        else prevNode->next = KthNode;
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}
