// Diameter of Binary Tree
// Bruteforce
int findDiameterBr(Node *node)
{
    if (node == nullptr)
        return 0;

    int lh = maxDepth(node->left);
    int rh = maxDepth(node->right);
    int maxi = lh + rh + 2;
    int leftDia = findDiameterBr(node->left);
    int rightDia = findDiameterBr(node->right);
    return max({maxi, leftDia, rightDia});
}

// Optimal
int heightAndDiameter(Node *node, int &diameter)
{
    if (node == nullptr)
        return -1;

    int lh = heightAndDiameter(node->left, diameter);
    int rh = heightAndDiameter(node->right, diameter);

    diameter = max(diameter, lh + rh + 2);

    return max(lh, rh) + 1;
}
int findDiameterOp(Node *node)
{
    int diameter = 0;
    heightAndDiameter(node, diameter);
    return diameter;
}
