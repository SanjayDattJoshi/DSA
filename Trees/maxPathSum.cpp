// Maximum Path Sum in Binary Tree
// Bruteforce
int maxDepth(TreeNode* node) {
    if (node == nullptr) return 0;

    int left  = max(0, maxDepth(node->left));
    int right = max(0, maxDepth(node->right));

    return node->val + max(left, right);
}

int maxPathSum(TreeNode* root) {
    if (root == nullptr) return 0;
    int left  = max(0, maxDepth(root->left));
    int right = max(0, maxDepth(root->right));
    int throughRoot = left + right + root->val;
    int leftBest  = maxPathSum(root->left);
    int rightBest = maxPathSum(root->right);
    return max({throughRoot, leftBest, rightBest});
}

//Optimal
int solve(TreeNode *node, int &maxSum)
{
    if (node == nullptr)
        return 0;
    int leftGain = max(0, solve(node->left, maxSum));
    int rightGain = max(0, solve(node->right, maxSum));
    int currentPath = leftGain + rightGain + node->val;
    maxSum = max(maxSum, currentPath);
    return node->val + max(leftGain, rightGain);
}
int maxPathSum(TreeNode *root)
{
    int maxSum = INT_MIN;
    solve(root, maxSum);
    return maxSum;
}
