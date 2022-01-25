class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int nums1 = stack.top();
                stack.pop();
                int nums2 = stack.top();
                stack.pop();
                if(tokens[i]=="+") stack.push(nums1+nums2);
                if(tokens[i]=="-") stack.push(nums2-nums1);
                if(tokens[i]=="*") stack.push(nums1*nums2);
                if(tokens[i]=="/") stack.push(nums2/nums1);
            }else{
                stack.push(stoi(tokens[i]));
            }
        }
        int result = stack.top();
        stack.pop();
        return result;
    }
};