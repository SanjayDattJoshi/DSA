// Sort a LL

// BruteForce
void sortLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return;
    vector<int> arr;
    Node *temp = head;
    while (temp != nullptr)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    temp = head;
    int i = 0;
    while (temp != nullptr)
    {
        temp->data = arr[i++];
        temp = temp->next;
    }
}

// Optimal
// Finding Middle Node (Optimal) slight change needed as previous.
Node *middleLL(Node *head)
{
    Node *fast = head->next; // modification for even list
    Node *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node *mergeLL(Node *left, Node *right)
{
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while (left != nullptr && right != nullptr)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    if (left)
        temp->next = left;
    else
        temp->next = right;
    Node *result = dummyNode->next;
    delete dummyNode; // Clean up memory leak
    return result;
}
Node *sortLLOp(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *middle = middleLL(head);
    Node *right = middle->next;
    middle->next = nullptr;
    Node *left = sortLLOp(head);
    right = sortLLOp(right);
    return mergeLL(left, right);
}
