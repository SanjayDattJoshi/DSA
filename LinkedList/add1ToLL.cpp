//Add 1 to a number represented by LL
//BruteForce
Node* add1InLL(Node*head){
    head = reverseLL(head);
    Node* temp = head;
    int carry = 1;
    while(temp != nullptr) {
        temp->data += carry;
        if(temp->data<10){
            carry = 0;
            break;
        }
        else{
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    if(carry==1){
    Node* newNode = new Node(carry);
    newNode->next = head;
    head = newNode;
    }
    return reverseLL(head);
}

//Optimal (it takes O(n) TC and SC.)
int helper_fun(Node* temp){
    if(temp == nullptr) return 1;
    int carry = helper_fun(temp->next);
    temp->data += carry;
    if(temp->data<10) return 0;
    temp->data = 0;
    return 1;
}
Node* add1InLL(Node*head){
    int carry = helper_fun(head);
    if(carry==1){
    Node* newNode = new Node(carry);
    newNode->next = head;
    head = newNode;
    }
    return head;
}
