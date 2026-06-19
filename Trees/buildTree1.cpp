//Construct a Binary Tree from Preorder and Inorder Traversal 
Node* buildTree(vector<int> preorder, vector<int> inorder){
    map<int, int> inMap;
    for(int i=0; i<inorder.size(); i++){
        inMap[inorder[i]] = i;
    }
    Node* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    return root;
}

Node* buildTree(vector<int> preorder, int preStart, int preEnd, vector<int> inorder, int inStart, int inEnd, map<int, int> inMap){
    if(preStart>preEnd || inStart>inEnd) return nullptr;

    Node* root = new Node(preorder[preStart]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot-1, inMap);
    root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
    return root;
}
