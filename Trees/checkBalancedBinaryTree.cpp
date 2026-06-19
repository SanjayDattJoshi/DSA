// Check for Balanced Binary Tree

// Bruteforce
bool checkBinaryTree(Node *root)
{
    if (root == nullptr)
        return true;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    if (abs(rh - lh) > 1)
        return false;

    bool left = checkBinaryTree(root->left);
    bool right = checkBinaryTree(root->right);

    if (!left || !right)
        return false;

    return true;
}

// Optimal
int checkBinaryTreeOp(Node *node)
{
    if (node == nullptr)
        return 0;

    int lh = checkBinaryTreeOp(node->left);
    if (lh == -1)
        return -1;

    int rh = checkBinaryTreeOp(node->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return max(lh, rh) + 1;
}
