class CQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    CQueue() {
        
    }
    
    void appendTail(int value) {
        stack2.push(value);
    }
    
    int deleteHead() {
        int head = 0;
        if(!stack1.empty()){
            head = stack1.top();
            stack1.pop();
        }else{
            if(!stack2.empty()){
                while(!stack2.empty()){
                    stack1.push(stack2.top());
                    stack2.pop();
                }
                head = stack1.top();
                stack1.pop();
            }else{
                return -1;
            }
        }
        return head;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */