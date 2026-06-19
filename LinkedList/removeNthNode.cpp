// Remove Nth Node from the end of LL
// BruteForce
Node *deleteNthNode(Node *head, int pos)
{
    Node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    temp = head;
    int position = count - pos;
    if (position == 0)
    {
        Node *newHead = head->next;
        free(head);
        return newHead;
    }
    while (temp != nullptr && temp->next != nullptr)
    {
        position--;
        if (position == 0)
        {
            Node *deleteNode = temp->next;
            temp->next = temp->next->next;
            free(deleteNode);
            break;
        }
        temp = temp->next;
    }
    return head;
}

// Optimal
Node *deleteNthNodeOp(Node *head, int pos)
{
    Node *fast = head;
    for (int i = 0; i < pos; i++)
    {
        fast = fast->next;
    }
    if (fast == nullptr)
    {
        Node *newHead = head->next;
        free(head);
        return newHead;
    }
    Node *slow = head;
    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node *deleteNode = slow->next;
    slow->next = slow->next->next;
    free(deleteNode);
    return head;
}
