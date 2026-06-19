int ceilInBST(Node* root, int key){
    int ceil = INT_MAX;

    while(root){

        if(root->data == key){
            return = root->data;
        }

        if(root->data > key){
            ceil = root->data;
            root = root->left;
        }

        else{
            root = root->right;
        }
    }
    return ceil;
}
