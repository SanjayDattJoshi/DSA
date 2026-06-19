// Search in LL
bool searchInLL(Node *head, int val)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}
