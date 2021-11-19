class Solution {
public:
    int numSquares(int n) {
        //声明数组记录是平方数的数，n如果是平方数也要push进去
        vector<int> nums;
        for(int i = 0;i<=n;i++){
            if(sqrt(i)-(int)sqrt(i)==0){
                nums.push_back(i);
            }
        }

        //求使用最少的平方数组成要求的数，因此初始值要是最大值防止被覆盖
        vector<int> dp(n+1,INT_MAX);
        //组成和为0用到0个平方数
        dp[0] = 0;
        //组合不是排列，因此与顺序无关，平方数无限使用，因此是完全背包问题，背包从小到大遍历
        for(int i = 0;i<nums.size();i++){
            for(int j = nums[i];j<=n;j++){
                if(dp[j-nums[i]]!=INT_MAX){
                    dp[j] = min(dp[j],dp[j-nums[i]]+1);
                }
                
            }
        }
        return dp[n];
    }
};