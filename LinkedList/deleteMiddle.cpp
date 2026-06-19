// Delete middle node of LL.
// BruteForce
Node *deleteMiddle(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    temp = head;
    int deletePos = cnt / 2;
    while (temp != nullptr)
    {
        deletePos--;
        if (deletePos == 0)
        {
            Node *deleteNode = temp->next;
            temp->next = temp->next->next;
            delete (deleteNode);
            break;
        }
        temp = temp->next;
    }
    return head;
}

// Optimal
Node *deleteMiddleOp(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *fast = head;
    Node *slow = head;
    Node *slowPrev = nullptr;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slowPrev = slow;
        slow = slow->next;
    }
    slowPrev->next = slow->next;
    delete (slow);
    return head;
}
