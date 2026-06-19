// Construct the Binary Tree from Postorder and Inorder Traversal
Node* buildTreePostIn(vector<int> postorder, int postStart, int postEnd, vector<int> inorder, int inStart, int inEnd, map<int, int> inMap){
    if(postStart>postEnd || inStart>inEnd) return nullptr;

    Node* root = new Node(postorder[postEnd]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTreePostIn(postorder, postStart, postStart + numsLeft-1, inorder, inStart, inRoot-1, inMap);
    root->right = buildTreePostIn(postorder, postStart + numsLeft, postEnd-1, inorder, inRoot + 1, inEnd, inMap);
    return root;
}
Node* buildTree2(vector<int> postorder, vector<int> inorder){
    if(postorder.size() != inorder.size()) return nullptr;
    map<int, int> inMap;
    for(int i=0; i<inorder.size(); i++){
        inMap[inorder[i]] = i;
    }
    Node* root = buildTreePostIn(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    return root;
}
