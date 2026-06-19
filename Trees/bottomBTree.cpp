//Bottom View of Binary Tree
vector<int> bottomViewOfBinaryTree(Node* root){
    vector<int> ans;
    if(root == nullptr) return ans;
    map<int, int> mpp;
    queue<pair<Node*, int>> todo;
    todo.push({root, 0});

    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        Node* node = p.first;
        int line = p.second;
        mpp[line] = node->data;

        if(node->left != nullptr) todo.push({node->left, line-1});
        if(node->right != nullptr) todo.push({node->right, line+1});
    }
    for(auto it: mpp){
        ans.push_back(it.second);
    }
    return ans;
}
