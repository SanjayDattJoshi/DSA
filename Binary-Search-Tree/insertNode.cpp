// Insert a given node in BST
Node *insertNode(Node *root, int val)
{
    if (root == nullptr)
        return new Node(val);
    Node *cur = root;
    while (true)
    {
        if (cur->data <= val)
        {
            if (cur->right != nullptr)
            {
                cur = cur->right;
            }
            else
            {
                cur->right = new Node(val);
                break;
            }
        }
        else
        {
            if (cur->left != nullptr)
                cur = cur->left;
            else
            {
                cur->left = new Node(val);
                break;
            }
        }
    }
    return root;
}
