class Solution {
public:
    string reverseWords(string s) {
        stack<string> stack;
        
        for(int i = 0;i<s.size();i++){

            string s1 = "";
            while(i<s.size() && s[i]!=' '){
                s1 += s[i];
                i++;
            }
            if(!s1.empty()){
                stack.push(s1);
            }
        }
        
        string result = "";
        while(!stack.empty()){
            result += stack.top();
            stack.pop();

            if(!stack.empty()){
                result += " ";
            }
        }
        return result;
    }
};