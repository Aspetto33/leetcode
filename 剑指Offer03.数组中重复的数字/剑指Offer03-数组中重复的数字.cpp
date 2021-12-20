class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int> result;

        for(int i = 0;i<nums.size();i++){
            result[nums[i]]++;

            if(result[nums[i]]>1) return nums[i];
        }
        return -1;
    }
};