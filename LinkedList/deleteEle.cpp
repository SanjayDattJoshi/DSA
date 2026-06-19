// Deletion in LL

//-->Deleting head
Node *delete_Head(Node *head)
{
    if (head == nullptr)
        return head;
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

//-->Deleting tail
Node *delete_Tail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete (temp->next);
    temp->next = nullptr;
    return head;
}

// Delete element at any position
Node *deleteAtAnyPosition(Node *head, int pos)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;

    if (pos == 1)
    {
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int count = 0;
    Node *prev = NULL;
    while (temp != nullptr)
    {
        count++;
        if (count == pos)
        {
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Delete value
Node *deleteValue(Node *head, int ele)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;

    if (head->data == ele)
    {
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *prev = NULL;
    while (temp != nullptr)
    {
        if (temp->data == ele)
        {
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
