// K-th Smallest/Largest Element in BST
// Inorder Traversal

// For Bruteforce use simple recursion and store all nodes then sort

// Better approach
void inorderTraversal(Node *root, vector<int> &inorder)
{
    if (root == nullptr)
        return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}
int kthLargestInBST(Node *root, int k)
{
    vector<int> result;
    int n = result.size();
    inorderTraversal(root, result);
    return result[n - k]; // for smallest return result[k];
}

// Optimal
int kthSmallestOp(Node *root, int k)
{
    Node *cur = root;
    int count = 0;
    while (cur != nullptr)
    {
        if (cur->left == nullptr)
        {
            count++;
            if (count == k)
                return cur->data;
            cur = cur->right;
        }
        else
        {
            Node *prev = cur->left;
            while (prev->right && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == nullptr)
            {
                prev->right = cur;
                cur = cur->left;
            }

            else
            {
                prev->right = nullptr;
                count++;
                if (count == k)
                    return cur->data;
                cur = cur->right;
            }
        }
    }
    return -1;
}

int kthLargestOp(Node *root, int k)
{
    Node *cur = root;
    int count = 0;
    while (cur != nullptr)
    {
        if (cur->right == nullptr)
        {
            count++;
            if (count == k)
                return cur->data;
            cur = cur->left;
        }
        else
        {
            Node *prev = cur->right;
            while (prev->left && prev->left != cur)
                prev = prev->left;

            if (prev->left == nullptr)
            {
                prev->left = cur;
                cur = cur->right;
            }
            else
            {
                prev->left = nullptr;
                count++;
                if (count == k)
                    return cur->data;
                cur = cur->left;
            }
        }
    }
    return -1;
}
