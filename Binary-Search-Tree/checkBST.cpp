// Check if a tree is a BST or BT
bool checkBST(Node *root, long minVal, long maxVal)
{
    if (root == nullptr)
        return true;
    if (root->data >= maxVal || root->data <= minVal)
        return false;
    return checkBST(root->left, minVal, root->data) &&
           checkBST(root->right, root->data, maxVal);
}
bool isBST(Node *root)
{
    return checkBST(root, INT_MIN, INT_MAX);
}
