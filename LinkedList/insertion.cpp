// Insertion at beginning
Node *insertEle(Node *head, int ele)
{
    Node *temp = new Node(ele, head);
    return temp;
}

// Insertion at last
Node *insertAtEnd(Node *head, int ele)
{
    if (head == nullptr)
    {
        return new Node(ele);
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(ele);
    temp->next = newNode;
    return head;
}

//Insert at any position
Node *insertAtK(Node *head, int ele, int pos)
{
    if (head == nullptr)
    {
        if (pos == 1)
    {
        return new Node(ele);
    }
    else return nullptr;
    }
      if (pos == 1)
    {
        return new Node(ele, head);
    }
    Node *temp = head;
    int cnt = 0;
    while (temp->next != nullptr)
    {
        cnt++;
        if(cnt == pos-1){
            break;
        }
        temp = temp->next;
    }
    Node *newNode = new Node(ele);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

//Insert before a given value
Node *insertBeforeVal(Node *head,int ele, int val)
{
    if (head == nullptr) return nullptr;

    if(head->data == val){
        return new Node(ele, head);
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {  
        if(temp->next->data == val){
            break;
        }
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        return head;  // Value not found, return unchanged list
    }
    Node *newNode = new Node(ele);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
