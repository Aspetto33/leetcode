class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);    // 初始化dp数组，含义为i个数拆分后乘积的最大值
        dp[2] = 1;  //初始化值，2拆分之后乘积最大值为1
        for(int i = 3;i<=n;i++){
            for(int j = 1;j<i-1;j++){
                dp[i] = max(dp[i],max(dp[i-j]*j,(i-j)*j));  //每次比较选出最大的值
            }
        }
        return dp[n];
    }
};