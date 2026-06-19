//Implement LRU Cache
class LRUCache{
    class Node
{
public:
    int key, value;
    Node *prev;
    Node *next;

public:
    Node(int key1, int value1, Node *next1 = nullptr, Node *prev1 = nullptr)
    {
        key = key1;
        value = value1;
        prev = prev1;
        next = next1;
    } 
};
Node *head = new Node(-1, -1);
Node *tail = new Node(-1, -1);

unordered_map<int, Node*> mpp;
int limit;

LRUCache(int capacity){
    limit = capacity;
    head->next = tail;
    tail->prev = head;
}

void deleteNode(Node* oldNode){
    oldNode->prev->next = oldNode->next;
    oldNode->next->prev = oldNode->prev;
}

void addNode(Node* newNode){
    newNode->next = head->next;
    head->next->prev = newNode;
    head->next = newNode;
    newNode->prev = head;
}
void put(int key, int value){
    if(mpp.find(key) != mpp.end()){
        Node* oldNode = mpp[key];
        deleteNode(oldNode);
        mpp.erase(key);
        delete oldNode;
    }
     if(mpp.size() == limit){
            Node* lru = tail->prev;      
            mpp.erase(lru->key);
            deleteNode(lru);
            delete lru;                 
    }
    Node* newNode = new Node(key, value);
    addNode(newNode);
    mpp[key] = newNode;
}

int get(int key){
    if(mpp.find(key) == mpp.end()) return -1;
    
    Node* ansNode = mpp[key];
    int ans = ansNode->value;

    deleteNode(ansNode);

    addNode(ansNode);
    mpp[key] = ansNode;
    
    return ans;
}
};
