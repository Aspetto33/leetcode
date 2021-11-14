class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0)); //初始化数组元素为0

        //遍历字符串
        for(string str:strs){
            //记录0和1的数量
            int zeroNums = 0,oneNums = 0;
            //遍历字符，记录数量
            for(char c:str){
                if(c=='0') zeroNums++;
                else oneNums++;
            }
            //遍历书包容量
            for(int i = m;i>=zeroNums;i--){
                for(int j = n;j>=oneNums;j--){
                    dp[i][j] = max(dp[i][j],dp[i-zeroNums][j-oneNums]+1);
                }
            }
        }
        return dp[m][n];
    }
};