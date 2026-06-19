class Node{

public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int data1, Node *right1 = nullptr, Node *left1 = nullptr)
    {
        data = data1;
        left = left1;
        right = right1;
    }
};
