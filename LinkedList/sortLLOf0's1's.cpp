// Sort LL of 0's, 1's and 2's.
// BruteForce
void sortLL2(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return;
    Node *temp = head;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    while (temp != nullptr)
    {
        if (temp->data == 0)
            cnt0++;
        else if (temp->data == 1)
            cnt1++;
        else
            cnt2++;
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        if (cnt0 != 0)
        {
            temp->data = 0;
            cnt0--;
        }
        else if (cnt1 != 0)
        {
            temp->data = 1;
            cnt1--;
        }
        else
        {
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
}

// Optimal
Node *sortLL2Op(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *dummy0Head = new Node(-1);
    Node *dummy1Head = new Node(-1);
    Node *dummy2Head = new Node(-1);
    Node *dummy0 = dummy0Head;
    Node *dummy1 = dummy1Head;
    Node *dummy2 = dummy2Head;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            dummy0->next = temp;
            dummy0 = temp;
        }
        else if (temp->data == 1)
        {
            dummy1->next = temp;
            dummy1 = temp;
        }
        else
        {
            dummy2->next = temp;
            dummy2 = temp;
        }
        temp = temp->next;
    }
    dummy0->next = dummy1Head->next ? dummy1Head->next : dummy2->next;
    dummy1->next = dummy2Head->next;
    dummy2->next = nullptr;
    Node *newHead = dummy0Head->next;
    delete dummy0Head;
    delete dummy1Head;
    delete dummy2Head;
    return newHead;
}
