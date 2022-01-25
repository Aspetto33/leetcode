class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        for(char c:s){
            if(stack.empty() || c!=stack.top()){
                stack.push(c);
            }
            else{
                stack.pop();
            }
        }
        string result="";
        while(!stack.empty()){
            result+= stack.top();
            stack.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};