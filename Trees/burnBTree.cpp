//Minimum time taken to BURN the Binary Tree from a Node
void markParents(Node* root, unordered_map<Node*, Node*> &parent_track){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        q.pop();

        if(current->left){ 
            parent_track[current->left] = current;
            q.push(current->left);
        }

        if(current->right){ 
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
}
int burnBTree(Node* root, Node* target){
    unordered_map<Node*, Node*> parent_track;
    markParents(root, parent_track);
    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    visited[target] = true;
    q.push(target);
    int maxi = 0;
    while(!q.empty()){
        int size = q.size();
        bool f1 = false;
        for(int i = 0; i<size; i++){
            Node* current = q.front();
            q.pop();
            if(current->left && !visited[current->left]){
                f1 = true;
                visited[current->left] = true;
                q.push(current->left);
            }
            if(current->right && !visited[current->right]){
                f1 = true;
                visited[current->right] = true;
                q.push(current->right);
            }
            if(parent_track[current] && !visited[parent_track[current]]){
                f1 = true;
                visited[parent_track[current]] = true;
                q.push(parent_track[current]);
            }
        }
        if(f1) maxi++;
    }
    return maxi;
}
