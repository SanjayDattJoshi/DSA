//Check for Symmetrical Binary Trees
bool checkBTreeIsSymmetric(Node* root){
    return root == nullptr || checkBTreeIsSymmetric(root->left, root->right);
}

bool checkBTreeIsSymmetric(Node* left, Node* right){
    if(left == nullptr || right == nullptr) return left == right;

    if(left->data != right->data) return false;

    return checkBTreeIsSymmetric(left->left, right->right)
                            && checkBTreeIsSymmetric(left->right, right->left);
}
