//Min Stack

//BruteForce
class MinStack{    
    private:
        stack<pair<int, int>> st;
    public:
    MinStack(){}
    void push(int val){
        if(st.empty()){ 
            st.push({val, val});
            return;
        }
        int mini = min(st.top().second, val);
        st.push({val, mini});
    }
       void pop() {
        st.pop(); 
    }
    int top() {
        return st.top().first;
    }
    int getMin() {
        return st.top().second;
    }
};

//Optimal
class MinStackOp{    
    private:
        stack<int> st;
        int minimum;
    public:
    MinStackOp():minimum(INT_MAX){}
    void push(int val){
        if(st.empty()) {
            minimum = val;
            st.push(val);
            return;
        }
        if(val>=minimum) st.push(val);
        else{
            st.push(2*val-minimum);
            minimum = val;
        }
    }
       void pop() {
       if(st.empty()) return;

       int x = st.top();
       st.pop();

       if(x<minimum) minimum = 2*minimum - x;
    }
    int top() {
        if(st.empty()) return -1;
        if(minimum<st.top()) return st.top();
        else return minimum;
    }
    int getMin() {
        return minimum;
    }
};
