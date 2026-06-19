// Delete all Occurences of a Key in DLL
Node *deleteAllOcc(Node *head, int key)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            if (temp == head)
            {
                head = head->next;
            }
            Node *nextNode = temp->next;
            Node *prevNode = temp->prev;
            if (nextNode)
                nextNode->prev = temp->prev;
            if (prevNode)
                prevNode->next = temp->next;
            delete temp;
            temp = nextNode;
        }
        else
            temp = temp->next;
    }
    return head;
}
