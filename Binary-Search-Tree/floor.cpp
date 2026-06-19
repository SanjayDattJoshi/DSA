int floorInBST(Node* root, int key){
    int floor = INT_MIN;

    while(root){
        if(root->data == key){
            floor = root->data;
            return floor;
        }
        if(root->data < key){
            floor = root->data;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return floor;
}
