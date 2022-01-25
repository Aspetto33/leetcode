class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int result = 0;
        // cout<<"dp[0]:"<<dp[0]<<endl;
        // cout<<"dp[1]:"<<dp[1]<<endl;
        // cout<<"dp[2]:"<<dp[2]<<endl;
        // cout<<"dp[3]:"<<dp[3]<<endl;
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                dp[i+1] = max(dp[i+1],dp[i]+1);
                cout<<"dp[i+1]:"<<dp[i+1]<<endl;
            }
        }

        for(int i = 0;i<dp.size();i++){
            result = max(result,dp[i]);
        }
        return result;
    }
};