//Preorder Inorder Postorder Traversals in One Traversal
vector<vector<int>> allInOneIterative(Node* root){
    if(root == nullptr) return {};
    vector<int> preorder, inorder, postorder;
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.second == 1){
            preorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left != nullptr){
            st.push({it.first->left, 1});
            }
        }
        else if(it.second == 2){
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right != nullptr){
            st.push({it.first->right, 1});
            }
        }
        else if(it.second == 3){
            postorder.push_back(it.first->data);
        }
    }
    return {preorder, inorder, postorder};
}
