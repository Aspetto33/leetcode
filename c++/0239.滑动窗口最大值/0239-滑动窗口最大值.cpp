class MyQueue{
public:
    deque<int> que;
    void pop(int val){
        if(!que.empty()&&val==que.front()){
            que.pop_front();
        }
    }
    void push(int val){
        while(!que.empty()&&val>que.back()){
            que.pop_back();
        }
        que.push_back(val);
    }
    int front(){
        return que.front();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        MyQueue myque;
        for(int i=0;i<k;i++){
            myque.push(nums[i]);
        }
        result.push_back(myque.front());
        for(int i=k;i<nums.size();i++){
            myque.pop(nums[i-k]);
            myque.push(nums[i]);
            result.push_back(myque.front());
        }
        return result;
    }
};