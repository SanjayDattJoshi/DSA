// Delete a Node in Binary Search Tree
Node *helper(Node *root)
{
    if (root->left == nullptr)
        return root->right;
    else if (root->right == nullptr)
        return root->left;

    Node *rightChild = root->right;
    Node *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}
Node *findLastRight(Node *root)
{
    if (root->right == nullptr)
        return root;
    return findLastRight(root->right);
}
Node *deleteNode(Node *root, int val)
{
    if (root == nullptr)
        return nullptr;
    if (root->data == val)
        return helper(root);

    Node *dummy = root;
    while (root != nullptr)
    {
        if (root->data > val)
        {
            if (root->left != nullptr && root->left->data == val)
            {
                root->left = helper(root->left);
                break;
            }
            else
                root = root->left;
        }
        else
        {
            if (root->right != nullptr && root->right->data == val)
            {
                root->right = helper(root->right);
                break;
            }
            else
                root = root->right;
        }
    }
    return dummy;
}
