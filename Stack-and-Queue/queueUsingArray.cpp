//Implementation of Queue using array
class QueueImpByArray{
    private:
    int start,end, currSize, capacity;
    vector<int> que;

    public:
    QueueImpByArray(int cap = 100){
    capacity = cap;
    start = -1, end = -1;
    currSize = 0;
    que.resize(capacity);
    }
    void push(int n){
        if(currSize == capacity){
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }
        if(end == -1){ 
            end = 0;
            start = 0;
        }
        else{
            end = (end + 1) % capacity;
        }
        que[end] = n;
        currSize++;
    }

    int pop(){
        if(start == -1){
            cout << "Queue Empty\nExiting..." << endl;
            exit(1);
        }
        int popped = que[start];
          if (currSize == 1) {
            start = -1;
            end = -1;
        }
        else {
            start = (start + 1) % capacity;
        }
        currSize--;
        return popped;
    }
    int peek() {
        if (start == -1) {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return que[start];
    }
    bool isEmpty() {
        return (currSize == 0);
    }
};
