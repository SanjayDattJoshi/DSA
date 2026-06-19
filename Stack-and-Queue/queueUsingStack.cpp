//Implementing Queue using Stack
class QueueByStack{
    public:
    stack<int> s1, s2;
    
    void push(int x){
        while(s1.size()!=0){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()!=0){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop(){
        if(s1.empty()) throw std::runtime_error("Queue is empty");
        int val = s1.top();
        s1.pop();
        return val;
    }

    int front(){
        if(s1.empty()) throw std::runtime_error("Queue is empty");
        return s1.top();
    }

     bool isEmpty(){
        return s1.empty();
    }

    int size(){
        return s1.size();
    }
};

//Optimizing push pop operations 
class QueueByStackOp{
    public:
    stack<int> s1, s2;
    
    void push(int x){
        s1.push(x);
    }
    
    int pop(){
        if(s1.empty() && s2.empty()) throw std::runtime_error("Queue is empty");
        int val;
        if(!s2.empty()){
        val = s2.top();
            s2.pop();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            val = s2.top();
            s2.pop();
        } 
        return val;
    }

    int top(){
        int val;
        if(!s2.empty()){
            val = s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            val = s2.top();
        } 
        return val;
    }
    bool isEmpty(){
        return s1.empty() && s2.empty();
    }

    int totalSize(){
        return s1.size()+s2.size();
    }
};
