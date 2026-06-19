//Count total Nodes in a COMPLETE Binary Tree

//Bruteforce
// Inorder Traversal
int countNodesOfCompleteTree(Node *root)
{
    int count = 0;
    if (root == nullptr)
        return 0;
    count++;
    int leftCount = countNodesOfCompleteTree(root->left);
    int rightCount = countNodesOfCompleteTree(root->right);
    return 1 + leftCount + rightCount;
}

//Optimal 
int findHeightLeft(Node* node){
    int height = 0;
    while(node){
        height++;
        node = node->left;
    }
    return height;
}
int findHeightRight(Node* node){
    int height = 0;
    while(node){
        height++;
        node = node->right;
    }
    return height;
}

int countNodes(Node* root){
    if(root == nullptr) return 0;

    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    if(lh==rh) return (1 << lh) - 1;

    return 1+countNodes(root->left) + countNodes(root->right);
}
