//Print all the Nodes at a distance of K in Binary Tree
void markParents(Node* root, unordered_map<Node*, Node*> &parent_track, Node* target){
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
vector<int> nodesAtDistance(Node* root, Node* target, int k){
    unordered_map<Node*, Node*> parent_track;
    markParents(root, parent_track, target);

    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;
    while(!q.empty()){
        int size = q.size();
        if(curr_level++ == k) break;
        for(int i = 0; i<size; i++){
            Node* current = q.front(); q.pop();
            if(current->left && !visited[current->left]){
                q.push(current->left);
                visited[current->left] = true;
            }
            if(current->right && !visited[current->right]){
                q.push(current->right);
                visited[current->right] = true;
            }
            if(parent_track[current] && !visited[parent_track[current]]){
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }

    vector<int> result;
    while(!q.empty()){
        Node* current = q.front(); q.pop();
        result.push_back(current->data);
    }
    return result;
}
