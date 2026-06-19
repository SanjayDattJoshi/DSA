//Implementation of Stack by LinkedList
class StackByLL{
    public:
    Node* top;
    int size;

    StackByLL() : top(nullptr), size(0) {}//Constructor initializes top and size

    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }

    int pop(){
        if(top == nullptr) throw std::runtime_error("Stack is empty");
        Node* temp = top;
        int poppedValue = top -> data;
        top = top->next;
        delete temp;
        size--;
        return poppedValue;
    }

    int peek(){
        if(top==nullptr) throw std::runtime_error("Stack is empty");
        return top->data;
    }

    int sizeOfLL(){
        return size;
    }
      bool isEmpty() {
        return top == nullptr;
    }
};
