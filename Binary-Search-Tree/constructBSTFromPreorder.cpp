// Construct a BST from a preorder traversal
Node *buildBST(vector<int> &preorder, int &i, int upperBound)
{
    if (i == preorder.size() || preorder[i] > upperBound)
        return nullptr;
    Node *root = new Node(preorder[i++]);
    root->left = buildBST(preorder, i, root->data);
    root->right = buildBST(preorder, i, upperBound);
    return root;
}

Node *constructBST(vector<int> preorder)
{
    int i = 0;
    return buildBST(preorder, i, INT_MAX);
}

// Inorder Successor/Predecessor in BST
// Bruteforce solution is store the inorder of BST and return first greater value than the value so it will
// take o(n+n) TC and o(n) SC.

// Better approach just return the value while performing inorder traversal which is greater than the value
// so it will take O(n) TC and O(1) SC.

// Optimal
int inorderSuccessor(Node *root, int val)
{
    if (root == nullptr)
        return -1;
    int inSuccessor = -1;
    while (root != nullptr)
    {
        if (root->data <= val)
        {
            root = root->right;
        }
        else
        {
            inSuccessor = root->data;
            root = root->left;
        }
    }
    return inSuccessor;
}

// Optimal (Predecessor is the largest node smaller than val)
int inorderPredecessor(Node *root, int val)
{
    if (root == nullptr)
        return -1;
    int inPredecessor = -1;
    while (root != nullptr)
    {
        if (root->data >= val)
            root = root->left;
        else
        {
            inPredecessor = root->data;
            root = root->right;
        }
    }
    return inPredecessor;
}
