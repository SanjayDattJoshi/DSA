//Implementation of Queue using LinkedList
class QueueByLL{
    public:
    Node* start;
    Node* end;
    int currSize;

    QueueByLL():start(nullptr), end(nullptr), currSize(0){}

    void push(int x){
        Node* temp = new Node(x);
        if(start == nullptr){ 
            start = temp;
            end = temp;
            currSize++;
        }
        else {
            end->next = temp;
            end = end->next;
            currSize++;
        }
    }
    int pop(){
        if(start == nullptr)throw std::runtime_error("Queue is empty");
        Node* temp = start;
        int poppedVal = temp->data;
        start = start->next;
         if (start == nullptr) {  
            end = nullptr;
        }
        delete temp;
        currSize--;
        return poppedVal;
    }
    int peek(){
        if(start == nullptr) throw std::runtime_error("Queue is empty");
        return start->data;
    }
    int sizeOfLL(){
        return currSize;
    }
    bool isEmpty(){
        return start == nullptr;
    }
};
