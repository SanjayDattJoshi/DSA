//Right/Left View of Binary Tree

//Iterative solution
vector<int> rightViewOfBinaryTree(Node* root){
    vector<int> ans;
    if(root == nullptr) return ans;
    map<int, int> mpp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        Node* node = p.first;
        int level = p.second;
        if(mpp.find(level) == mpp.end()) mpp[level] = node->data;
        if(node->right != nullptr) q.push({node->right, level+1});
        if(node->left != nullptr) q.push({node->left, level+1});
    }
    for(auto it: mpp){
        ans.push_back(it.second);
    }
    return ans;
}

//Recursive solution
void recursion(Node* root, level, vector<int> &res){
    if(root == nullptr) return;
    if(res.size() == level) res.push_back(root->data);
    recursion(root->right, level+1, res);
    recursion(root->left, level+1, res);
}
vector<int> rightViewUsingRecursion(Node* root){
    vector<int> res;
    if(root == nullptr) return res;
    recursion(root, 0, res);
    return res;
}
