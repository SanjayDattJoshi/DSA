// LCA in Binary Search Tree

// Recursive approach
Node *LCAOfBST(Node *root, int p, int q)
{
    if (root == nullptr)
        return nullptr;
    int curr = root->data;
    if (curr < p && curr < q)
    {
        return LCAOfBST(root->right, p, q);
    }
    if (curr > p && curr > q)
    {
        return LCAOfBST(root->left, p, q);
    }
    return root;
}

// Iterative approach
Node *LCAOfBST(Node *root, int p, int q)
{
    if (root == nullptr)
        return nullptr;
    while (root != nullptr)
    {
        int curr = root->data;

        if (curr < p && curr < q)
            root = root->right;
        else if (curr > p && curr > q)
            root = root->left;
        else
            return root;
    }
    return nullptr;
}
