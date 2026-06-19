// Check if two trees are Identical or Not
bool isSameTree(Node* t1, Node* t2){
    if(t1==nullptr || t2==nullptr) return (t1==t2);
    return (t1->data == t2->data )
           && (isSameTree(t1->left, t2->left))
           && (isSameTree(t1->right, t2->right));
}
