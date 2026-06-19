// Iterative Postorder Traversal(with 1 stacks)
vector<int> iterativePost(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    stack<Node *> st;
    Node *curr = root;
    while (curr != nullptr || !st.empty())
    {
        if (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }

        else
        {
            Node *temp = st.top()->right;
            if (temp == nullptr)
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);

                }
            }
            else curr = temp;
        }
    }
    return ans;
}
