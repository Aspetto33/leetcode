/*
 *动态规划:从（0，0）出发只能向右或者向下走
 *因此可以推导出来想要到达（i，j）只能从（i-1，j）或者（i，j-1）处到达
 *当从起点出发的时候去（i，0）和（0，j）都是只有一条路可以走，因此将数组dp[i][0]和dp[0][j]
 *都初始化为1，然后循环，令dp[i][j]的值等于dp[i-1][j]和dp[i][j-1]的和，数组最后一个元素的值
 *即为最终结果。
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++) dp[i][0] = 1;  //初始化，向下走只有一条路径
        for(int j=0;j<n;j++) dp[0][j] = 1;  //初始化，向右走只有一条路径
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];  
            }
        }
        return dp[m-1][n-1];
    }
};