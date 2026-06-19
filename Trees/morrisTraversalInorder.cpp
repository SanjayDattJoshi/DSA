//Morris Traversal | Inorder 
vector<int> morrisTraversalIn(Node* root){
    vector<int> inorder;
    Node* cur = root;
    while(cur!=nullptr){
        if(cur->left == nullptr){
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else{
            Node* prev = cur->left;
            while(prev->right && prev->right != cur){
                prev = prev->right;
            }

            if(prev->right == nullptr){
                prev->right = cur;
                cur = cur->left;
            }

            else{
                prev->right = nullptr;
                inorder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return inorder;
}
