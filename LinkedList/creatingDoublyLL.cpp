class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    public:
    Node(int data1, Node* next1 = nullptr, Node* prev1 = nullptr){
        data = data1;
        prev = prev1;
        next = next1;
    }
};
