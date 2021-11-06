/*
 *初始化，如果是路障的话跳过，否则令第一行和第一列的所有数值为1
 *循环赋值，如果是路障则跳过，否则当前位置等于上面和左面的数值相加
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0;i<m && obstacleGrid[i][0]==0;i++) dp[i][0]=1; 
        for(int j = 0;j<n && obstacleGrid[0][j]==0;j++) dp[0][j]=1;
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(obstacleGrid[i][j]==1) continue;
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};