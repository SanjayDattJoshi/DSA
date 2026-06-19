//Lowest Common Ancestor in Binary Tree
//Bruteforce
int LCA(Node* root, int a1, int a2){
    if(root == nullptr) return -1;
    vector<int> a1Path;
    vector<int> a2Path;
    a1Path = rootToNodePath(root, a1);
    a2Path = rootToNodePath(root, a2);

    int ans = -1;

    for(int i = 0; i<min(a1Path.size(), a2Path.size()); i++){
        if(a1Path[i] == a2Path[i]) ans = a1Path[i];
        else break;
    }
    return ans;
}

//Optimal
Node* LCAOp(Node* root, Node* p, Node* q){
    if(root == nullptr || root == p || root == q) return root;

    Node* left = LCAOp(root->left, p, q);
    Node* right = LCAOp(root->right, p, q);

    if(left == nullptr) return right;
    else if(right == nullptr) return left;
    else return root;
}
