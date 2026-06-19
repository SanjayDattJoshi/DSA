//Reversing a DLL

//BruteForce
Node* reverseDLL(Node* head){
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
Node* reverseDLLOp(Node* head){
     if(head == nullptr || head->next == nullptr){
        return head;  
    }
     Node* current = head;
     Node* last = nullptr;
     while(current != nullptr){
           last = current -> prev;
           current -> prev = current -> next;
           current -> next = last;
           current = current->prev;
     }
     return last->prev;
}
