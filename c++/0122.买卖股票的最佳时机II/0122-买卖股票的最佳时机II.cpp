class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        vector<vector<int>> dp(length,vector<int>(2,0));

        //初始化,表示第一天持有股票获得的钱数
        dp[0][0] -=prices[0];

        //表示第一天不持有股票获得的钱数
        dp[0][1] = 0;
        for(int i = 1;i<length;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]-prices[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]);
        }
        return dp[length-1][1];
    }
};