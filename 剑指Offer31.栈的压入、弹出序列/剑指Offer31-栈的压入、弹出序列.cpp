class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        int i = 0;

        for(int push:pushed){
            stack.push(push);

            while(!stack.empty() && stack.top() == popped[i]){
                stack.pop();
                i++;
            }
        }

        return stack.empty();
    }
};