class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int subLen = 0;
        int sum = 0;
        int i = 0;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>=target){
                subLen=j-i+1;
                result = result<subLen?result:subLen;
                sum-=nums[i++];
            }
        }
        return result == INT32_MAX?0:result;
    }
};