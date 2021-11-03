/*
 *根据题目推导得出当前层数可以走的选择数是前面两个选择数相加，从3开始遵循此规则
 *因此dp[i]表达的意思是走i层楼梯，有多少选择
*/
class Solution {
public:
    int climbStairs(int n) {
        //当n为0的时候直接返回n即可
        if(n<=1){
            return n;
        }
        vector<int> dp(n+1);
        dp[1]=1;
        dp[2]=2;
        //规律从3开始
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];   
    }
};