//Implementing Stack using Queue
class stackByQueue{
    public:
    queue<int> q;
    int s;

    stackByQueue(): s(0){}

    void push(int x){
     s = q.size();
     q.push(x);
     for(int i=1; i<=s; i++){
        q.push(q.front());
        q.pop();
     }
    }

    int pop(){
        if(q.empty()) throw std::runtime_error("Stack is empty");
        int val = q.front();  
        q.pop(); 
        return val;
    }

    int top(){
        if(q.empty()) throw std::runtime_error("Stack is empty");
        return q.front();
    }
    bool isEmpty() {
        return q.empty();
    }

    int size() {
        return q.size();
    }
};
