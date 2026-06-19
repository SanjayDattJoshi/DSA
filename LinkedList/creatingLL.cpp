//Creating LinkedList in c++.

//Using Structures
// Creating Linked List
//  struct Node{
//      public:
//      int data;
//      Node* next;

//     public:
//     Node(int data1, Node* next1){
//             data = data1;
//             next = next1;
//     }
// };

//Using Classes(recommanded)
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1 = nullptr)
    {
        data = data1;
        next = next1;
    }
};
