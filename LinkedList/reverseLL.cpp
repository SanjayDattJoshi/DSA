//Reversing a DLL

//BruteForce
Node* reverseLL(Node* head){
     if(head == nullptr || head->next == nullptr){
        return head;  
    }
    Node *temp = head;
    stack<int> st;
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }
    temp = head;
    while(temp!=nullptr){
        temp->data = st.top();
        st.pop();
        temp=temp->next;
    }
   return head;
}

//Optimal
Node* reverseLLOp(Node* head){
     if(head == nullptr || head->next == nullptr){
        return head;  
    }
    Node *temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
         Node* front = temp->next;
         temp->next = prev;
         prev = temp;
         temp = front;
    }
    return prev;
}

//Recursive approach (it takes O(n) TC and SC.)
Node* reverseLLRecur(Node* head){
     if(head == nullptr || head->next == nullptr){
        return head;  
    }
    Node* newHead = reverseLLRecur(head->next);
    Node* front= head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
