class Solution {
public:
    int rob(vector<int>& nums) {
        //数组为空时，偷窃的最高金额为0
        if(nums.size()==0) return 0;

        //数组只有一个元素时，偷窃的最高金额为这个元素的值
        if(nums.size()==1) return nums[0];

        //声明记录结果数组
        vector<int> dp(nums.size());

        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2;i<nums.size();i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
            cout<<dp[i]<<endl;
        }
        return dp[nums.size()-1];
    }
};