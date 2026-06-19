//Morris Traversal | Preorder 
vector<int> morrisTraversalPre(Node* root){
    vector<int> preorder;
    Node* cur = root;
    while(cur!=nullptr){
        if(cur->left == nullptr){
            preorder.push_back(cur->data);
            cur = cur->right;
        }
        else{
            Node* prev = cur->left;
            while(prev->right && prev->right != cur){
                prev = prev->right;
            }

            if(prev->right == nullptr){
                prev->right = cur;
                preorder.push_back(cur->data);//One Line Change fron inorder
                cur = cur->left;
            }

            else{
                prev->right = nullptr;
                cur = cur->right;
            }
        }
    }
    return preorder;
}
