// Iterative Postorder Traversal(with 2 stacks)
vector<int> iterativePostorder(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    stack<Node *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();

        st2.push(root);
        if (root->left != nullptr)
            st1.push(root->left);
        if (root->right != nullptr)
            st1.push(root->right);
    }
    while (!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}
