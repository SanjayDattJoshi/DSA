//Print Root to Node Path in Binary Tree
bool getPath(Node* node, vector<int> &arr, int x){
    if(!node) return false; //if null false

    arr.push_back(node->data);

    if(node->data == x) return true;

    if(getPath(node->left, arr, x) || 
       getPath(node->right, arr, x))
       return true;

    arr.pop_back();
    return false;
}
vector<int> rootToNodePath(Node* root, int b){
    vector<int> A;
    if(root == nullptr) return A;

    getPath(root, A, b);
    return A;
}
