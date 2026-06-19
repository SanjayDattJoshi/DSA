//Boundary Traversal in Binary Tree
bool isLeaf(Node* node){
    if(!node) return false; 
    if(node->left || node->right) return false;
    return true;
}

void addLeftBoundary(Node* root, vector<int> &res){
    Node* cur = root->left;
    while(cur){
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->left) cur = cur -> left;
        else cur = cur -> right;
    }
}

void addLeaves(Node* root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);
}

void addRightBoundary(Node* root, vector<int> &res){
    Node* cur = root->right;
    vector<int>temp;
    while(cur){
        if(!isLeaf(cur)) temp.push_back(cur->data);
        if(cur->right) cur = cur -> right;
        else cur = cur -> left;
    }
    for(int i = temp.size()-1; i>=0; i--){
        res.push_back(temp[i]);
    }
}
vector<int> boundaryTraversal(Node* root){
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    addLeftBoundary(root->left, res);
    addLeaves(root, res);
    addRightBoundary(root->right, res);
    return res;
}
