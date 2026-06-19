//Add two numbers in LinkedList
Node* addTwoLL(Node* head1, Node* head2){
    int carry = 0;
    Node* dummyNode = new Node(-1);
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* curr = dummyNode;
    while(temp1!=nullptr || temp2!=nullptr){
    int sum = carry;
    if(temp1) sum += temp1->data;
    if(temp2) sum += temp2->data;

    Node* newNode = new Node(sum%10);
    carry = sum/10;
    
    curr->next = newNode;
    curr = curr->next;
    
    if(temp1) temp1 = temp1->next;
    if(temp2) temp2 = temp2->next;
  }
   if(carry==1){
    Node* newNode = new Node(carry);
    curr->next = newNode;
    }
    return dummyNode->next;
}
