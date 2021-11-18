class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //初始化记录数组，dp[j]表示达到j需要使用的最少硬币数,
        vector<int> dp(amount+1,INT_MAX);   //因为是求最小值，因此初始化要是最大值，以防被覆盖

        //dp[0]的意思是凑齐0金额需要的最少硬币数，是0
        dp[0] = 0;

        //无关顺序
        for(int i = 0;i<coins.size();i++){
            for(int j = coins[i];j<=amount;j++){
                if(dp[j-coins[i]]!=INT_MAX){
                    dp[j] = min(dp[j],dp[j-coins[i]]+1);    //如果是初始值则跳过
                }
                
            }
        }
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount]; 
    }
};