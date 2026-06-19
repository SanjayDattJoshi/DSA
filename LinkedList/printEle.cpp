//Print LinkedList
void printLL(Node* head){
    Node* temp = head;
    cout<<"LinkedList :";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl<<endl;
}
