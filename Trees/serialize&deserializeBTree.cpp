//Serialize and De-serialize Binary Tree
string serialize(Node* root){
    if(!root) return "";

    string s = "";
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curNode = q.front();
        q.pop();
        if(curNode == nullptr) s.append("#,");
        else s.append(to_string(curNode->data)+",");
        if(curNode!=nullptr){
            q.push(curNode->left);
            q.push(curNode->right);
        }
    }
    cout<<s;
    return s;
}

Node* deserialize(string data){
    if(data.size() == 0) return nullptr;
    stringstream s(data); 
    string str;
    getline(s, str, ',');
    Node* root = new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* n = q.front();
        q.pop();

        getline(s, str, ',');
        if(str == "#"){
            n->left = nullptr;
        }else{
            Node* leftNode = new Node(stoi(str));
            n->left = leftNode;
            q.push(leftNode);
        }
        getline(s, str, ',');
        if(str == "#"){
            n->right = nullptr;
        }else{
            Node* rightNode = new Node(stoi(str));
            n->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
