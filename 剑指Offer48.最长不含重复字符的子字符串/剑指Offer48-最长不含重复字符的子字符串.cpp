class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> record;

        int leftIndex = 0;  //滑动窗口左边界值
        int rightIndex = 0; //滑动窗口右边界值
        int result = 0; //结果值

        //如果当前元素没有在哈希表中出现，右边界移动，将元素放入哈希表中，否则移除第一个元素，左边右移
        while(rightIndex<s.size()){
            if(record.end() == record.find(s[rightIndex])){
                record.insert(s[rightIndex++]);
            }else{
                record.erase(s[leftIndex++]);
            }
            result = max(result,rightIndex-leftIndex);  //取大的结果值
        }
        return result;
    }
};