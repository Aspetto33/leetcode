class MaxQueue {
public:
    queue<int> que1;
    deque<int> que2;
    MaxQueue() {

    }
    
    int max_value() {
        if(que1.empty()) return -1;
        return que2.front();
    }
    
    void push_back(int value) {
        que1.push(value);
        while(!que2.empty() && que2.back()<value){
            que2.pop_back();
        }
        que2.push_back(value);
    }
    
    int pop_front() {
        if(que1.empty()) return -1;
        int front = que1.front();
        que1.pop();
        if(front == que2.front()) que2.pop_front();
        return front;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */