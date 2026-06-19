//Check Palindrome
//BruteForce
bool checkPalindrome(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp!=nullptr){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=nullptr){
        if(st.top() != temp->data) return false;
        temp = temp->next;
        st.pop();
    }
    return true;
}

//Optimal
Node* reverseLL2(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
bool checkPalindromeOp(Node* head){
    if(head == nullptr || head->next == nullptr) return true;  
    Node* slow= head;
    Node* fast = head;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
               slow= slow->next;
               fast = fast->next->next;
    }
    Node* newHead = reverseLL2(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second!=nullptr){
        if(first->data != second->data){
             reverseLL2(newHead);
             return false;
        } 
        first = first->next;
        second = second->next;
    }
    reverseLL2(newHead);
    return true;
}
