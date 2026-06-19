//Flatten a Binary Tree to Linked List

//Recursive Solution(TC is O(n) and SC is O(n))
void flattenBTreeRecursive(Node* root){
    static Node* prev = nullptr;
    if(root == nullptr) return;
    flattenBTreeRecursive(root->right);
    flattenBTreeRecursive(root->left);
    root->right = prev;
    root->left = nullptr;
    prev = root;
}

//Iterative Solution(TC is O(n) and SC is O(n))
void flattenBTreeIterative(Node* root){
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* cur = st.top();
        st.pop();

        if(cur->right) st.push(cur->right);
        if(cur->left) st.push(cur->left);

        if(!st.empty()){
            cur->right = st.top();
        }
        cur->left = nullptr;
    }
}

//Morris approach (TC is O(n) and SC is O(1))
void flattenBTree(Node* root){
    Node* cur = root;
    Node* prev = nullptr;
    while(cur!=nullptr){
        if(cur->left!=nullptr){
            prev = cur->left;
            while(prev->right) prev = prev->right;
            prev->right = cur->right;
            cur->right = cur->left;
        }
    cur = cur->right;
    }
}
