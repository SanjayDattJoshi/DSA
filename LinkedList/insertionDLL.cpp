//Insertion before head
Node* insertBeforeHead(Node* head, int ele){
    Node* temp = new Node(ele, head);
    head->prev = temp;
    return temp;
}

//Insertion before Tail
Node* insertBeforeTail(Node* head, int ele){
    if(head == nullptr) return new Node(ele);
    if(head->next == nullptr) return insertBeforeHead(head, ele);
    Node* tail = head;
    while(tail->next!=nullptr){
        tail = tail->next;
    }
    Node* newNode = new Node(ele, tail, tail->prev);
    tail->prev->next = newNode;
    tail->prev = newNode;
    return head;
}

//Insertion before kth element
Node* insertBeforePos(Node* head, int ele, int pos){
    if(pos == 1) return insertBeforeHead(head, ele);
    if(head == nullptr){
        return new Node(ele);  
    }
    Node* temp = head;
    int count = 0;
    while(temp->next != nullptr){
        count++;
        if(count == pos) break;
        temp = temp->next;
    }
    // Position out of bounds
      if(temp == nullptr){
        return head;  
    }
    Node* newNode = new Node(ele, temp, temp->prev);
    // Handle if inserting after head (temp->prev exists)
     if(temp->prev != nullptr){
        temp->prev->next = newNode;
    }
    temp->prev = newNode;
    return head;
}

//Insert element before given node
void insertBeforeNode(Node*head, int ele, Node* node){
    Node* prev = node->prev;
    Node* newNode = new Node(ele, node, prev);
    prev->next = newNode;
    node->prev = newNode;
}
