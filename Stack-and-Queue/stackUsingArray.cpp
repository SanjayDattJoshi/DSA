//Implementation of Stack using Arrays
class StackImpByArrays{
    private:
    int top;
    vector<int> st;
    int size;

    public:
    StackImpByArrays(int capacity = 100){
    top = -1;
    size = capacity;
    st.resize(capacity);
    }
    void push(int n){
        if(top>=size-1){
             cout<<endl<<"Stack Overflow"<<endl;
             return;
        }
        top = top + 1;
        st[top] = n;
    }
    int pop(){
       if(top==-1){ 
        cout<<endl<<"Stack Underflow"<<endl;
        return -1;
       }
        int poppedValue = st[top];  
        top--;
        return poppedValue; 
    }
    int getTop(){
        if(top==-1){ 
            cout<<endl<<"Stack is empty!"<<endl;
            return -1;
        }
        return st[top];
    }
    bool isEmpty(){
        return top == -1;
    }
};
