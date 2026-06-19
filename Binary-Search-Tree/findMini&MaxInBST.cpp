//Find MIN in BST
int minInBST(Node* root){
    int val = INT_MAX;
    while(root!=nullptr){
        val = root->data;
        root = root->left;
    }
    return val;
}

//Find MAX in BST
int maxInBST(Node* root){
    int val = INT_MIN;
    while(root!=nullptr){
        val = root->data;
        root = root->right;
    }
    return val;
}
