// Find the intersection point of Y LL.
// BruteForce
Node *intersectionOfLL(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr)
        return nullptr;
    Node *temp = head1;
    map<Node *, int> mpp;
    while (temp != nullptr)
    {
        mpp[temp] = 1;
        temp = temp->next;
    }
    temp = head2;
    while (temp != nullptr)
    {
        if (mpp.find(temp) != mpp.end())
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

// Better
Node *collisionPoint(Node *smallerLL, Node *largerLL, int d)
{
    while (d)
    {
        d--;
        largerLL = largerLL->next;
    }
    while (smallerLL != largerLL)
    {
        smallerLL = smallerLL->next;
        largerLL = largerLL->next;
    }
    return smallerLL;
}
Node *intersectionOfLLBetter(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr)
        return nullptr;
    Node *temp = head1;
    int n1 = 0, n2 = 0;
    while (temp != nullptr)
    {
        n1++;
        temp = temp->next;
    }
    temp = head2;
    while (temp != nullptr)
    {
        n2++;
        temp = temp->next;
    }

    if (n1 < n2)
        return collisionPoint(head1, head2, n2 - n1);
    else
        return collisionPoint(head2, head1, n1 - n2);
}

// Optimal
Node *intersectionOfLLOp(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr)
        return nullptr;
    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1 != temp2)
    {
        temp1 = (temp1 == nullptr) ? head2 : temp1->next;
        temp2 = (temp2 == nullptr) ? head1 : temp2->next;
    }
    return temp1;
}
