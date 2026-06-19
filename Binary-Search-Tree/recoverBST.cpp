// Recover BST | Correct BST with two nodes swapped
// Bruteforce - find inorder traversal and sort it then run a pointer
// across sorted values and change nodes which are not in correct position
// so it takes O(2n + nlogn) TC and O(N) SC.

// Optimal
void inorder(Node *root, Node *&prev, Node *&first, Node *&middle, Node *&last)
{
    if (root == nullptr)
        return;

    inorder(root->left, prev, first, middle, last);
    if (prev != nullptr && (root->data < prev->data))
    {
        if (first == nullptr)
        {
            first = prev;
            middle = root;
        }
        else
            last = root;
    }
    prev = root;
    inorder(root->right, prev, first, middle, last);
}
Node *recoverBST(Node *root)
{
    Node *first, *middle, *last;
    first = middle = last = nullptr;
    Node *prev = new Node(INT_MIN);
    inorder(root, prev, first, middle, last);
    if (first && last)
        swap(first->data, last->data);
    else if (first && middle)
        swap(first->data, middle->data);
    return root;
}
