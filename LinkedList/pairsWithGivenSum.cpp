// Find all pairs with given sum in sorted DLL
//BruteForce
vector<pair<int, int>> allPairs(Node *head, int val)
{
    Node *temp1 = head;
    vector<pair<int, int>> arr;
    while (temp1 != nullptr)
    {
        Node *temp2 = temp1->next;
        while (temp2 != nullptr && (temp1->data + temp2->data) <= val)
        {
            if ((temp1->data + temp2->data) == val)
            {
                arr.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return arr;
}

//Optimal
Node* findTail(Node*head){
    Node*temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    return temp;
}
vector<pair<int, int>> allPairsOp(Node *head, int val)
{
    Node* left = head;
    vector<pair<int, int>> arr;
    Node* right = findTail(head);
    while(left != right && left->prev != right){
        if(left->data+right->data == val){
             arr.push_back({left->data, right->data});
             left = left->next;
             right = right->prev;
        }
        else if(left->data+right->data < val) left = left->next;
        else right = right->prev;
    }
    return arr;
}
