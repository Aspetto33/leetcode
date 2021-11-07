class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);    // ��ʼ��dp���飬����Ϊi������ֺ�˻������ֵ
        dp[2] = 1;  //��ʼ��ֵ��2���֮��˻����ֵΪ1
        for(int i = 3;i<=n;i++){
            for(int j = 1;j<i-1;j++){
                dp[i] = max(dp[i],max(dp[i-j]*j,(i-j)*j));  //ÿ�αȽ�ѡ������ֵ
            }
        }
        return dp[n];
    }
};