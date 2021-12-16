class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stack1;
    stack<int> stack2;
    int minNum = INT_MAX;
    MinStack() {
        
    }
    
    void push(int x) {
        stack1.push(x);
        minNum = minNum<x? minNum:x;
        cout<<"push:"<<minNum<<endl;

    }
    
    void pop() {
            minNum = INT_MAX;
            stack1.pop();

            while(!stack1.empty()){
                minNum = minNum<stack1.top()? minNum:stack1.top();
                stack2.push(stack1.top());
                stack1.pop();
            }
            cout<<"pop:"<<minNum<<endl;
            while(!stack2.empty()){
                stack1.push(stack2.top());
                stack2.pop();
            }
    }
    
    int top() {
        return stack1.top();
    }
    
    int min() {
        return minNum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */